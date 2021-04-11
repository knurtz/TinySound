#include "ch.h"
#include "hal.h"

#include "ff.h"
#include <string.h>
#include "chprintf.h"

#include "wave.h"

#include "ts_audio.h"

#define WAV_BUFFER_SIZE 512

#define FORMAT_PCM      1
#define RIFF            0x46464952  // FFIR
#define WAVE            0x45564157  // EVAW 
#define DATA            0x61746164  // atad
#define FMT             0x20746D66  //  tmf

#define EVT_DAC_TC      0           // DAC transmission complete
#define EVT_DAC_HT      1           // DAC transmission half complete
#define EVT_AUDIO       2           // Audio request from another thread

//===========================================================================
// Variables
//===========================================================================

static int16_t dac_buffer[WAV_BUFFER_SIZE];

static FATFS SDC_FS;
static FIL file;
static bool fs_ready = false;

static uint32_t bytes_to_play;

static event_source_t audio_dma_tc_event;
static event_source_t audio_dma_ht_event;

extern MMCDriver MMCD1;                         // from main.c

//===========================================================================
// SD card related
//===========================================================================

static void sdCardInit(void)
{
    FRESULT err;

    // Connect to the card
    if (mmcConnect(&MMCD1)) return;

    // mount file system
    err = f_mount(&SDC_FS, "/", 1);
    if (err != FR_OK) {
        mmcDisconnect(&MMCD1);
        return;
    }
    else fs_ready = true;
}

static void sdCardReadChunk(void* pbuffer)
{
    UINT btr = 0;

    f_read(&file, pbuffer, WAV_BUFFER_SIZE * sizeof(int16_t) / 2, &btr);
    bytes_to_play -= btr;

    // stop playing when there are not enough bytes left to play
    // TODO: read all bytes that are left and start from beginning of file
    if (bytes_to_play < WAV_BUFFER_SIZE * sizeof(int16_t) / 2) i2sStopExchange(&I2SD1);
}

static void playFile(char* filename)
{
	FRESULT err;
	UINT btr;

    if (!fs_ready) {
        chprintf((BaseSequentialStream*) &SD1, "Filesystem not mounted!\n");
        return;
    }

    err = f_open(&file, filename, FA_READ);
    if (err != FR_OK) {
        chprintf((BaseSequentialStream*) &SD1, "Error opening file.\n");
        return;
    }

    err = f_read(&file, &dac_buffer, sizeof(FILEHeader), &btr);
	if (err != FR_OK) {
        chprintf((BaseSequentialStream*) &SD1, "Error reading file header.\n");
        return;
    }

    FILEHeader* header = (FILEHeader*) dac_buffer;
    if (!(header->riff.descriptor.id == RIFF
        && header->riff.type == WAVE
        && header->wave.descriptor.id == FMT
        && header->wave.audioFormat == FORMAT_PCM)) {
            chprintf((BaseSequentialStream*) &SD1, "Wrong file format.\n");
            return;
    }

    chprintf((BaseSequentialStream*) &SD1,
		"Channels: %d\r\nSample Rate: %ld\r\nBits per Sample: %d\n",
		header->wave.numChannels, header->wave.sampleRate, header->wave.bitsPerSample);

    if (header->wave.numChannels != 2) {
        chprintf((BaseSequentialStream*) &SD1, "Wrong number of channels.\n");
        return;
    }

    if (header->wave.bitsPerSample != 16) {
        chprintf((BaseSequentialStream*) &SD1, "Wrong number of bits per sample.\n");
        return;
    }
    /*
    if (header->wave.sampleRate != 48000) {
        chprintf((BaseSequentialStream*) &SD1, "Wrong sample rate.\n");
        return;
    }
    */
    err = f_read(&file, &dac_buffer, sizeof(DATAHeader), &btr);
	if (err != FR_OK) {
        chprintf((BaseSequentialStream*) &SD1, "Error reading file header.\n");
        return;
    }    
    DATAHeader* dataheader = (DATAHeader*) &dac_buffer;

    if ((uint32_t) dataheader->descriptor.id != DATA) {
        chprintf((BaseSequentialStream*) &SD1, "Could not find data header.\n");
        return;
    }  
    
    chprintf((BaseSequentialStream*) &SD1, "Now playing: %s\n", filename);

    bytes_to_play = dataheader->descriptor.size;

    // fill buffer completely
    err = f_read(&file, &dac_buffer, WAV_BUFFER_SIZE * sizeof(int16_t), &btr);
    bytes_to_play -= btr;

    // start continuous transfer of audio data
    i2sStartExchange(&I2SD1);
}

static void stopPlayback(void) 
{
    i2sStopExchange(&I2SD1);
    f_close(&file);
}

void cmd_play(BaseSequentialStream *chp, int argc, char *argv[])
{
    stopPlayback();
    playFile("/TWODOT~1.WAV");
}

void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[])
{
    stopPlayback();
}


//===========================================================================
// Driver configs and callbacks
//===========================================================================

static void i2scallback(I2SDriver *i2sp)
{
    chSysLockFromISR();
    if (i2sIsBufferComplete(i2sp)) chEvtBroadcastI(&audio_dma_tc_event);
    else chEvtBroadcastI(&audio_dma_ht_event);
    chSysUnlockFromISR();
}

static const I2SConfig i2scfg =
{
    dac_buffer,
    NULL,
    WAV_BUFFER_SIZE,
    i2scallback,
    0,  // CFGR register: I2SSTD = 00 (Philips I2S), CKPOL = 0 (clk default low), DATLEN = 00 (16-bit data), CHLEN = 0 (16-bit)
        // I2SMOD, I2SE and I2SCFG bits will be set by driver automatically
    (1 << SPI_I2SPR_ODD_Pos) | 2  // I2S prescaler = 2 * 2 + 1 (to get from 7.68 MHz I2SCLK to 1.536 MHz BCLK)
};

//===========================================================================
// Audio thread main function
//===========================================================================

THD_FUNCTION(audioThd, arg)
{
    event_listener_t el0, el1;
	void *pbuffer = dac_buffer;

    chRegSetThreadName("audio");
        
    i2sStart(&I2SD1, &i2scfg);
    sdCardInit();

    palSetLine(LINE_AUDIO_EN);

    // register events
    chEvtObjectInit(&audio_dma_tc_event);
    chEvtRegister(&audio_dma_tc_event, &el0, EVT_DAC_TC);
    chEvtObjectInit(&audio_dma_ht_event);
    chEvtRegister(&audio_dma_ht_event, &el1, EVT_DAC_HT);

    // infinite loop
    while (1)
    {
        eventmask_t evt = chEvtWaitAny(ALL_EVENTS);

        if (evt & EVENT_MASK(EVT_DAC_TC)) {
            // TC -> fill second half of buffer with new data
            pbuffer += WAV_BUFFER_SIZE * sizeof(int16_t) / 2;
            sdCardReadChunk(pbuffer);
        }

        if (evt & EVENT_MASK(EVT_DAC_HT)) {
            // HT -> fill first half of buffer with new data
            pbuffer = dac_buffer;
            sdCardReadChunk(pbuffer);
        }
    }
}