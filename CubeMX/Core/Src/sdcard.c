#include "sdcard.h"
#include "shell.h"
#include "spi.h"

uint8_t fs_ready = false;
FATFS FatFs;

void SDCard_Start(void)
{
  if (fs_ready) return;
  
  // clear previously mounted filesystem
  f_mount(NULL, "", 0);
  
  HAL_Delay(100);

  FRESULT fres = f_mount(&FatFs, "", 1);
  if (fres != FR_OK) {
    xprintf("Error mounting filesystem: %i\n", fres);
    while(1);
  }

  fs_ready = true;
}

void SDCard_Stop(void)
{
  f_mount(NULL, "", 0);
}

void SDCard_Test(void)
{
  SDCard_Start();

  FRESULT fres;
  DWORD free_clusters, free_sectors, total_sectors;
  FATFS* getFreeFs;

  fres = f_getfree("", &free_clusters, &getFreeFs);
  if (fres != FR_OK) {
    xprintf("Error getting free clusters: %i\n", fres);
    while(1);
  }

  // Formula comes from ChaN's documentation
  total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
  free_sectors = free_clusters * getFreeFs->csize;

  int totalMB = total_sectors * 512 / 1000000.0;
  int freeMB = free_sectors * 512 / 1000000.0;

  xprintf("SD card stats:\n%i MB total drive space.\n%i MB available.\n", totalMB, freeMB);
}

void SDCard_List(void)
{
  DIR dir;
  FILINFO fileinfo;

  SDCard_Start();

  f_opendir(&dir, "/");

  f_readdir(&dir, &fileinfo);
  while (fileinfo.fname[0])
  {
    xprintf("%s\n", fileinfo.fname);
    f_readdir(&dir, &fileinfo);
  }
}