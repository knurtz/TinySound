#ifndef TS_AUDIO_H
#define TS_AUDIO_H

#include "ch.h"
#include "hal.h"

#define WAV_BUFFER_SIZE 256

#define EVT_DAC_TC      0           // DAC transmission complete
#define EVT_DAC_HT      1           // DAC transmission half complete

extern int16_t dac_buffer[WAV_BUFFER_SIZE];

void playFile(char* filename);
void stopPlayback(void);
void sdCardReadChunk(void* pbuffer);

void cmd_play(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_state(BaseSequentialStream *chp, int argc, char *argv[]);

#endif /* TS_AUDIO_H */
