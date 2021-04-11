/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#include "hal.h"
#include "stm32_gpio.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of STM32 GPIO port setup.
 */
typedef struct {
  uint32_t              moder;
  uint32_t              otyper;
  uint32_t              ospeedr;
  uint32_t              pupdr;
  uint32_t              odr;
  uint32_t              afrl;
  uint32_t              afrh;
} gpio_setup_t;

/**
 * @brief   Type of STM32 GPIO initialization data.
 */
typedef struct {
  gpio_setup_t          PAData;
  gpio_setup_t          PBData;
  gpio_setup_t          PCData;  
  gpio_setup_t          PDData;
  gpio_setup_t          PEData;
} gpio_config_t;


static void stm32_gpio_init(void) {

  // Enabling GPIO-related clocks, the mask comes from the registry header file.
  rccResetIOP(STM32_GPIO_EN_MASK);
  rccEnableIOP(STM32_GPIO_EN_MASK, true);

  // Initialize all used GPIO ports
  palSetLineMode(LINE_UART_TX, PAL_MODE_ALTERNATE(1));
  palSetLineMode(LINE_UART_RX, PAL_MODE_ALTERNATE(1));

  palSetLineMode(LINE_I2S_CK, PAL_MODE_ALTERNATE(0));
  palSetLineMode(LINE_I2S_WS, PAL_MODE_ALTERNATE(0));
  palSetLineMode(LINE_I2S_SD, PAL_MODE_ALTERNATE(0));

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

#if HAL_USE_SDC || defined(__DOXYGEN__)

/**
 * @brief   SDC card detection.
 */
bool sdc_lld_is_card_inserted(SDCDriver *sdcp) {

  (void)sdcp;
  return true;
}

/**
 * @brief   SDC card write protection detection.
 */
bool sdc_lld_is_write_protected(SDCDriver *sdcp) {

  (void)sdcp;
  return false;
}

#endif // HAL_USE_SDC

#if HAL_USE_MMC_SPI || defined(__DOXYGEN__)
/**
 * @brief   MMC_SPI card detection.
 */
bool mmc_lld_is_card_inserted(MMCDriver *mmcp) {

  (void)mmcp;
  return true;
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

