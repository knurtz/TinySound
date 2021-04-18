#ifndef SDCARD_H
#define SDCARD_H

#include "app_fatfs.h"

void SDCard_Start(void);
void SDCard_Stop(void);

void SDCard_Test(void);
void SDCard_List(void);

extern uint8_t fs_ready;
extern FATFS FatFs;

#endif /* SDCARD_H */
