#include "audio.h"
#include "shell.h"
#include "sdcard.h"
#include "wave.h"
#include "i2s.h"

#define WAV_BUFFER_SIZE 512

int16_t dac_buffer[WAV_BUFFER_SIZE];
void *pbuffer;

FIL file;
static uint32_t bytes_to_play;

volatile uint8_t ht_event = false, tc_event = false;

//===========================================================================
// Audio
//===========================================================================

void Audio_ReadChunk(void* pbuffer)
{
    UINT btr = 0;

    FRESULT fres = f_read(&file, pbuffer, WAV_BUFFER_SIZE * sizeof(int16_t) / 2, &btr);
    bytes_to_play -= btr;
    
    // stop playing when there are not enough bytes left to play
    // TODO: read all bytes that are left and start from beginning of file
    if ( (bytes_to_play < WAV_BUFFER_SIZE * sizeof(int16_t) / 2) || fres) Audio_StopPlayback();
    if (fres) 
    {
      fs_ready = false;
    }
}

void Audio_PlayFile(char* filename)
{
	FRESULT fres;
	UINT btr;

    SDCard_Start();

    fres = f_open(&file, filename, FA_READ);
    if (fres != FR_OK) {
        xprintf("Error opening file.\n");
        return;
    }

    fres = f_read(&file, &dac_buffer, sizeof(FILEHeader), &btr);
	if (fres != FR_OK) {
        xprintf("Error reading file header.\n");
        return;
    }

    FILEHeader* header = (FILEHeader*) dac_buffer;
    if (!(header->riff.descriptor.id == RIFF
        && header->riff.type == WAVE
        && header->wave.descriptor.id == FMT
        && header->wave.audioFormat == FORMAT_PCM)) {
            xprintf("Wrong file format.\n");
            return;
    }

    /*xprintf("Channels: %d\nSample Rate: %ld\nBits per Sample: %d\n",
		header->wave.numChannels, 
        header->wave.sampleRate, 
        header->wave.bitsPerSample);*/

    if (header->wave.numChannels != 2) {
        xprintf("Wrong number of channels.\n");
        return;
    }

    if (header->wave.bitsPerSample != 16) {
        xprintf("Wrong number of bits per sample.\n");
        return;
    }
    /*
    if (header->wave.sampleRate != 48000) {
        xprintf("Wrong sample rate.\n");
        return;
    }
    */
    fres = f_read(&file, &dac_buffer, sizeof(DATAHeader), &btr);
	if (fres != FR_OK) {
        xprintf("Error reading file header.\n");
        return;
    }    
    DATAHeader* dataheader = (DATAHeader*) &dac_buffer;

    if ((uint32_t) dataheader->descriptor.id != DATA) {
        xprintf("Could not find data header.\n");
        return;
    }  
    
    xprintf("Now playing: %s\n", filename);

    bytes_to_play = dataheader->descriptor.size;

    // fill buffer completely
    fres = f_read(&file, &dac_buffer, WAV_BUFFER_SIZE * sizeof(int16_t), &btr);
    bytes_to_play -= btr;

    //xprintf("Number of bytes: %i", bytes_to_play);

    // start continuous transfer of audio data
    HAL_GPIO_WritePin(AU_EN_GPIO_Port, AU_EN_Pin, GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_I2S_Transmit_DMA(&hi2s1, (uint16_t*)dac_buffer, WAV_BUFFER_SIZE);
}

void Audio_StopPlayback(void) 
{
    HAL_I2S_DMAStop(&hi2s1);
    f_close(&file);
    HAL_GPIO_WritePin(AU_EN_GPIO_Port, AU_EN_Pin, GPIO_PIN_RESET);
}

//===========================================================================
// DMA callbacks
//===========================================================================

int missed_hts = 0;
int max_missed = 0;
void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
  if (ht_event) missed_hts++;
  else
  {
    missed_hts = 0;
    if (missed_hts > max_missed) max_missed = missed_hts;
  }
  ht_event = true;
}

void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s)
{
  if (tc_event) HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
  tc_event = true;
}

void Audio_CheckEvents(void)
{
  void* pbuffer = dac_buffer;

  if (ht_event)
  {
    pbuffer = dac_buffer;
    Audio_ReadChunk(pbuffer);
    ht_event = false;
  }

  else if (tc_event)
  {
    pbuffer += WAV_BUFFER_SIZE * sizeof(int16_t) / 2;
    Audio_ReadChunk(pbuffer);
    tc_event = false;
  }
}

//===========================================================================
// Some commands for shell
//===========================================================================

void cmd_play(char* arg)
{
  Audio_StopPlayback();
  HAL_Delay(100);
  Audio_PlayFile(arg);
}

void cmd_stop(void)
{
  Audio_StopPlayback();
  //xprintf("Missed HTs: %i\n", missed_hts);
}