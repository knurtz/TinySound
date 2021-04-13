// Based on https://github.com/ChibiOS/ChibiOS/blob/master/os/hal/boards/ST_NUCLEO64_G071RB/board.c

#include "hal.h"
#include "stm32_gpio.h"

static void stm32_gpio_init(void) {

  // Enabling GPIO-related clocks, the mask comes from the registry header file.
  rccResetIOP(STM32_GPIO_EN_MASK);
  rccEnableIOP(STM32_GPIO_EN_MASK, true);

  // Initialize all used GPIO ports
  palSetLineMode(LINE_UART_TX, PAL_MODE_ALTERNATE(1));
  palSetLineMode(LINE_UART_RX, PAL_MODE_ALTERNATE(1));

  palSetLineMode(LINE_I2S_CK, PAL_MODE_ALTERNATE(0) | PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
  palSetLineMode(LINE_I2S_WS, PAL_MODE_ALTERNATE(0) | PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
  palSetLineMode(LINE_I2S_SD, PAL_MODE_ALTERNATE(0) | PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);

  palSetLineMode(LINE_SD_MISO, PAL_MODE_ALTERNATE(4) | PAL_STM32_OSPEED_HIGHEST);
  palSetLineMode(LINE_SD_SCK, PAL_MODE_ALTERNATE(1) | PAL_STM32_OSPEED_HIGHEST);
  palSetLineMode(LINE_SD_MOSI, PAL_MODE_ALTERNATE(1) | PAL_STM32_OSPEED_HIGHEST);

  palSetLineMode(LINE_LED, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(LINE_AUDIO_EN, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(LINE_SD_CS, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLine(LINE_SD_CS);                                     // initially deselect SD card

  palSetLineMode(LINE_SD_DET, PAL_MODE_INPUT_PULLUP);           
}

/**
 * @brief   Early initialization code.
 * @details GPIO ports and system clocks are initialized before everything
 *          else.
 */
void __early_init(void) {

  stm32_gpio_init();
  stm32_clock_init();
}

#if HAL_USE_MMC_SPI || defined(__DOXYGEN__)
/**
 * @brief   MMC_SPI card detection.
 */
bool mmc_lld_is_card_inserted(MMCDriver *mmcp) {

  (void)mmcp;
  return !palReadLine(LINE_SD_DET);
}

/**
 * @brief   MMC_SPI card write protection detection.
 */
bool mmc_lld_is_write_protected(MMCDriver *mmcp) {

  (void)mmcp;
  return false;
}
#endif // HAL_USE_MMC_SPI

/**
 * @brief   Board-specific initialization code.
 * @note    You can add your board-specific code here.
 */
void boardInit(void) {

}