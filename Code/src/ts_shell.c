#include "ch.h"
#include "hal.h"
#include <string.h>
#include "shell.h"
#include "chprintf.h"
#include "ff.h"
#include "stdlib.h"

//===========================================================================
// FatFs related.                                                            
//===========================================================================

// FS object
static FATFS SDC_FS;

// FS mounted and ready
static bool fs_ready = FALSE;

// Generic large buffer
static uint8_t fbuff[512];

// MMCDriver object from main.c
extern MMCDriver MMCD1;

static FRESULT scan_files(BaseSequentialStream *chp, char *path) {
  static FILINFO fno;
  FRESULT res;
  DIR dir;
  size_t i;
  char *fn;

  res = f_opendir(&dir, path);
  if (res == FR_OK) {
    i = strlen(path);
    while (((res = f_readdir(&dir, &fno)) == FR_OK) && fno.fname[0]) {
      if (FF_FS_RPATH && fno.fname[0] == '.')
        continue;
      fn = fno.fname;
      if (fno.fattrib & AM_DIR) {
        *(path + i) = '/';
        strcpy(path + i + 1, fn);
        res = scan_files(chp, path);
        *(path + i) = '\0';
        if (res != FR_OK)
          break;
      }
      else {
        chprintf(chp, "%s/%s\r\n", path, fn);
      }
    }
  }
  return res;
}

//===========================================================================


// FatFS tree command
void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[]) {
  FRESULT err;
  uint32_t free_clust;
  FATFS *fsp;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: tree\r\n");
    return;
  }

  // Connection to the card
  chprintf(chp, "Connecting... ");
  if (mmcConnect(&MMCD1)) {
    chprintf(chp, "failed\r\n");
    return;
  }

  // mount file system
  err = f_mount(&SDC_FS, "/", 1);
  if (err != FR_OK) mmcDisconnect(&MMCD1);
  else fs_ready = TRUE;

  if (!fs_ready) {
    chprintf(chp, "File System not mounted\r\n");
    return;
  }

  err = f_getfree("/", &free_clust, &fsp);
  if (err != FR_OK) {
    chprintf(chp, "FS: f_getfree() failed\r\n");
    return;
  }

  chprintf(chp,
           "FS: %lu free clusters with %lu sectors (%lu bytes) per cluster\r\n",
           free_clust, (uint32_t)fsp->csize, (uint32_t)fsp->csize * 512);
  fbuff[0] = 0;
  scan_files(chp, (char *)fbuff);

  mmcDisconnect(&MMCD1);
  fs_ready = FALSE;
}