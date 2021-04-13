#include "ch.h"
#include "hal.h"

#include "ts_audio.h"
#include "ts_sdcard.h"
#include "wave.h"

//===========================================================================
// Variables
//===========================================================================

int16_t dac_buffer[WAV_BUFFER_SIZE];
static uint32_t bytes_to_play;
FIL file;

//===========================================================================
// Audio
//===========================================================================

void sdCardReadChunk(void* pbuffer)
{
    UINT btr = 0;

    f_read(&file, pbuffer, WAV_BUFFER_SIZE * sizeof(int16_t) / 2, &btr);
    bytes_to_play -= btr;

    // stop playing when there are not enough bytes left to play
    // TODO: read all bytes that are left and start from beginning of file
    if (bytes_to_play < WAV_BUFFER_SIZE * sizeof(int16_t) / 2) i2sStopExchange(&I2SD1);
}

void playFile(char* filename)
{
	FRESULT err;
	UINT btr;

    if (!fs_ready) {
        chprintf((BaseSequentialStream*) &SD1, "Filesystem not mounted!\r\n");
        return;
    }

    err = f_open(&file, filename, FA_READ);
    if (err != FR_OK) {
        chprintf((BaseSequentialStream*) &SD1, "Error opening file.\r\n");
        return;
    }

    err = f_read(&file, &dac_buffer, sizeof(FILEHeader), &btr);
	if (err != FR_OK) {
        chprintf((BaseSequentialStream*) &SD1, "Error reading file header.\r\n");
        return;
    }

    FILEHeader* header = (FILEHeader*) dac_buffer;
    if (!(header->riff.descriptor.id == RIFF
        && header->riff.type == WAVE
        && header->wave.descriptor.id == FMT
        && header->wave.audioFormat == FORMAT_PCM)) {
            chprintf((BaseSequentialStream*) &SD1, "Wrong file format.\r\n");
            return;
    }

    chprintf((BaseSequentialStream*) &SD1,
		"Channels: %d\r\nSample Rate: %ld\r\nBits per Sample: %d\r\n",
		header->wave.numChannels, header->wave.sampleRate, header->wave.bitsPerSample);

    if (header->wave.numChannels != 2) {
        chprintf((BaseSequentialStream*) &SD1, "Wrong number of channels.\r\n");
        return;
    }

    if (header->wave.bitsPerSample != 16) {
        chprintf((BaseSequentialStream*) &SD1, "Wrong number of bits per sample.\r\n");
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
        chprintf((BaseSequentialStream*) &SD1, "Error reading file header.\r\n");
        return;
    }    
    DATAHeader* dataheader = (DATAHeader*) &dac_buffer;

    if ((uint32_t) dataheader->descriptor.id != DATA) {
        chprintf((BaseSequentialStream*) &SD1, "Could not find data header.\r\n");
        return;
    }  
    
    chprintf((BaseSequentialStream*) &SD1, "Now playing: %s\r\n", filename);

    bytes_to_play = dataheader->descriptor.size;

    // fill buffer completely
    err = f_read(&file, &dac_buffer, WAV_BUFFER_SIZE * sizeof(int16_t), &btr);
    bytes_to_play -= btr;

    // start continuous transfer of audio data
    i2sStartExchange(&I2SD1);
}

void stopPlayback(void) 
{
    i2sStopExchange(&I2SD1);
    f_close(&file);
}

//===========================================================================
// Some commands for shell
//===========================================================================

void cmd_play(BaseSequentialStream *chp, int argc, char *argv[])
{
    stopPlayback();
    playFile("/TWODOT~1.WAV");
}

void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[])
{
    stopPlayback();
}

void cmd_state(BaseSequentialStream *chp, int argc, char *argv[])
{
    chprintf(chp, "I2S state: %i\r\n", I2SD1.state);
}
