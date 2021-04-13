#ifndef TS_SDCARD_H
#define TS_SDCARD_H

#include "ch.h"
#include "hal.h"

#include "ff.h"
#include <string.h>
#include "chprintf.h"

extern MMCDriver MMCD1;
extern bool fs_ready;

void sdCardInit(void);

void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[]);

#endif /* TS_SDCARD_H */
