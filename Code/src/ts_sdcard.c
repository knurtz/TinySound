#include "ch.h"
#include "hal.h"

#include "ts_sdcard.h"

//===========================================================================
// Variables
//===========================================================================

MMCDriver MMCD1;

bool fs_ready = false;

static FATFS filesystem;

static uint8_t fbuff[512];

// Maximum speed SPI configuration (18 MHz, CPHA=0, CPOL=0, MSB first)
static const SPIConfig hs_spicfg = {false, NULL, GPIOB, GPIOB_SD_CS, 0, 0};

// Low speed SPI configuration (281.250 kHz, CPHA=0, CPOL=0, MSB first)
static const SPIConfig ls_spicfg = {false, NULL, GPIOB, GPIOB_SD_CS, SPI_CR1_BR_2 | SPI_CR1_BR_1, 0};

// MMC over SPI configuration
static const MMCConfig mmccfg = {&SPID2, &ls_spicfg, &hs_spicfg};

//===========================================================================
// SD card related
//===========================================================================

void sdCardInit(void)
{    
    mmcObjectInit(&MMCD1);
    mmcStart(&MMCD1, &mmccfg);

    // Connect to the card
    if (mmcConnect(&MMCD1)) return;

    // mount file system
    if (f_mount(&filesystem, "/", 1))
    {
        mmcDisconnect(&MMCD1);
        return;
    }
    else fs_ready = true;
}

static FRESULT scan_files(BaseSequentialStream *chp, char *path)
{
  static FILINFO fno;
  FRESULT res;
  DIR dir;
  size_t i;
  char *fn;

  res = f_opendir(&dir, path);

  if (res == FR_OK) {
    i = strlen(path);
    while (((res = f_readdir(&dir, &fno)) == FR_OK) && fno.fname[0]) 
    {
      if (FF_FS_RPATH && fno.fname[0] == '.') continue;
      fn = fno.fname;
      if (fno.fattrib & AM_DIR)
      {
        *(path + i) = '/';
        strcpy(path + i + 1, fn);
        res = scan_files(chp, path);
        *(path + i) = '\0';
        if (res != FR_OK) break;
      }
      else chprintf(chp, "%s/%s\r\n", path, fn);
    }
  }
  return res;
}

//===========================================================================

void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[])
{
  FRESULT err;
  uint32_t free_clust;
  FATFS *fsp;

  if (argc > 0) {
    chprintf(chp, "Usage: tree\r\n");
    return;
  }

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
}