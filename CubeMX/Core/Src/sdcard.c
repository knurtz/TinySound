#include "sdcard.h"
#include "shell.h"
#include "spi.h"

uint8_t fs_ready = false;
FATFS FatFs;

void SDCard_Start(void)
{
  if (fs_ready) return;

  HAL_Delay(1000);

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
  xprintf("\n~ SD card demo by kiwih ~\n\n");

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

  xprintf("SD card stats:\n%10lu KiB total drive space.\n%10lu KiB available.\n", total_sectors / 2, free_sectors / 2);
}