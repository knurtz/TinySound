#include <string.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "ts_shell.h"

#include "ts_audio.h"

#include "ff.h"

//===========================================================================
// Variables and functions
//===========================================================================

static thread_t *shelltp = NULL;
MMCDriver MMCD1;

//===========================================================================
// Threads and working areas
//===========================================================================

static THD_WORKING_AREA(audio_wa, 128);
static THD_WORKING_AREA(blinker_wa, 16);

static THD_FUNCTION(blinkerThd, arg) {
    (void)arg;
    chRegSetThreadName("blinker");
    while (true) {
        palSetLine(LINE_LED);
        chThdSleepMilliseconds(500);
        palClearLine(LINE_LED);
        chThdSleepMilliseconds(500);
    }
}

//===========================================================================
// Command line configuration
//===========================================================================

#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(128)
static const ShellCommand commands[] = {
    {"tree", cmd_tree},
    {"play", cmd_play},
    {"stop", cmd_stop},
    {NULL, NULL}
};

//===========================================================================
// Global driver configuration
//===========================================================================

// Maximum speed SPI configuration (18MHz, CPHA=0, CPOL=0, MSb first)
static SPIConfig hs_spicfg = {false, NULL, GPIOB, GPIOB_SD_CS, 0, 0};

// Low speed SPI configuration (281.250kHz, CPHA=0, CPOL=0, MSb first)
static SPIConfig ls_spicfg = {false, NULL, GPIOB, GPIOB_SD_CS, SPI_CR1_BR_2 | SPI_CR1_BR_1, 0};

// MMC over SPI configuration
static MMCConfig mmccfg = {&SPID2, &ls_spicfg, &hs_spicfg};

// ChibiOS shell configuration
static const ShellConfig shell_cfg = {
    (BaseSequentialStream *)&SD1,
    commands
};

//===========================================================================
// Application entry point
//===========================================================================

int main(void) {

    // System initialization
    halInit();
    chSysInit();

    sdStart(&SD1, NULL);
    shellInit();

    mmcObjectInit(&MMCD1);
    mmcStart(&MMCD1, &mmccfg);

    // start threads
    chThdCreateStatic(blinker_wa, sizeof(blinker_wa), NORMALPRIO - 1, blinkerThd, NULL);
    shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell", NORMALPRIO, shellThread, (void *)&shell_cfg);
    chThdCreateStatic(audio_wa, sizeof(audio_wa), NORMALPRIO + 1, audioThd, NULL);

    while (true) {
        chThdSleepMilliseconds(1000);
    };  

}  // end of main()
