#ifndef EW_AUDIO_H
#define EW_AUDIO_H

#include "ch.h"
#include "hal.h"

THD_FUNCTION(audioThd, arg);

void cmd_play(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[]);

#endif /* EW_AUDIO_H */
