#include <string.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "ts_audio.h"
#include "ts_sdcard.h"

#include "ff.h"

//===========================================================================
// Variables and functions
//===========================================================================

static thread_t *shelltp = NULL;

static event_source_t audio_dma_tc_event;
static event_source_t audio_dma_ht_event;

//===========================================================================
// Threads and working areas
//===========================================================================

static THD_WORKING_AREA(blinker_wa, 16);

static THD_FUNCTION(blinkerThd, arg) {
    (void)arg;
    chRegSetThreadName("blinker");
    while (true) {
        palSetLine(LINE_LED);
        chThdSleepMilliseconds(I2SD1.state == 3 ? 250 : 500);
        palClearLine(LINE_LED);
        chThdSleepMilliseconds(I2SD1.state == 3 ? 250 : 500);
    }
}

//===========================================================================
// Command line / shell configuration
//===========================================================================

#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(128)
static const ShellCommand commands[] = {
    {"tree", cmd_tree},
    {"play", cmd_play},
    {"stop", cmd_stop},
    {"state", cmd_state},
    {NULL, NULL}
};

//===========================================================================
// Driver configuration and callbacks
//===========================================================================

// ChibiOS shell configuration
static const ShellConfig shell_cfg = {
    (BaseSequentialStream *)&SD1,
    commands
};

static void i2scallback(I2SDriver *i2sp)
{
    chSysLockFromISR();
    if (i2sIsBufferComplete(i2sp)) chEvtBroadcastI(&audio_dma_tc_event);
    else chEvtBroadcastI(&audio_dma_ht_event);
    chSysUnlockFromISR();
}

static const I2SConfig i2scfg =
{
    dac_buffer,
    NULL,
    WAV_BUFFER_SIZE,
    i2scallback,
    0,  // CFGR register: I2SSTD = 00 (Philips I2S), CKPOL = 0 (clk default low), DATLEN = 00 (16-bit data), CHLEN = 0 (16-bit)
        // I2SMOD, I2SE and I2SCFG bits will be set by driver automatically
    SPI_I2SPR_ODD_Msk | 12  // I2S prescaler
};

//===========================================================================
// Application entry point
//===========================================================================

int main(void)
{
    event_listener_t el0, el1;
	void *pbuffer = dac_buffer;

    // System initialization
    halInit();
    chSysInit();

    //chThdCreateStatic(blinker_wa, sizeof(blinker_wa), NORMALPRIO - 1, blinkerThd, NULL);

    sdStart(&SD1, NULL);
    shellInit();
    shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell", NORMALPRIO, shellThread, (void *)&shell_cfg);

    sdCardInit();
        
    i2sObjectInit(&I2SD1);
    i2sStart(&I2SD1, &i2scfg);
    palSetLine(LINE_AUDIO_EN);

    // register events
    chEvtObjectInit(&audio_dma_tc_event);
    chEvtRegister(&audio_dma_tc_event, &el0, EVT_DAC_TC);
    chEvtObjectInit(&audio_dma_ht_event);
    chEvtRegister(&audio_dma_ht_event, &el1, EVT_DAC_HT);

    while (true) {
        eventmask_t evt = chEvtWaitAny(ALL_EVENTS);

        if (evt & EVENT_MASK(EVT_DAC_TC)) {
            // TC -> fill second half of buffer with new data
            pbuffer += WAV_BUFFER_SIZE * sizeof(int16_t) / 2;
            sdCardReadChunk(pbuffer);
            palSetLine(LINE_LED);
        }

        if (evt & EVENT_MASK(EVT_DAC_HT)) {
            // HT -> fill first half of buffer with new data
            pbuffer = dac_buffer;
            sdCardReadChunk(pbuffer);
            palClearLine(LINE_LED);
        }
    }  

}  // end of main()
