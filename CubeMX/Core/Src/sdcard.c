#include "sdcard.h"
#include "shell.h"
#include "app_fatfs.h"

void SDCard_Test(void)
{
  xprintf("\n~ SD card demo by kiwih ~\n\n");

  HAL_Delay(50); //a short delay is important to let the SD card settle

  //some variables for FatFs
  FATFS FatFs; 	//Fatfs handle
  FIL fil; 		//File handle
  FRESULT fres; //Result after operations

  //Open the file system
  fres = f_mount(&FatFs, "", 1); //1=mount now
  if (fres != FR_OK) {
    xprintf("f_mount error (%i)\n", fres);
    while(1);
  }

  //Let's get some statistics from the SD card
  DWORD free_clusters, free_sectors, total_sectors;

  FATFS* getFreeFs;

  fres = f_getfree("", &free_clusters, &getFreeFs);
  if (fres != FR_OK) {
    xprintf("f_getfree error (%i)\n", fres);
    while(1);
  }

  //Formula comes from ChaN's documentation
  total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
  free_sectors = free_clusters * getFreeFs->csize;

  xprintf("SD card stats:\n%10lu KiB total drive space.\n%10lu KiB available.\n", total_sectors / 2, free_sectors / 2);

  f_mount(NULL, "", 0);
}