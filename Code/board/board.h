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

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_TINY_SOUND
#define BOARD_NAME                  "TinySound"

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0
#endif

#define STM32_LSEDRV                (3U << 11U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                0
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32G071xx

/*
 * IO pins assignments.
 */
#define GPIOA_WAKEUP                0U
#define GPIOA_AUDIO_BCLK            1U
#define GPIOA_AUDIO_DIN             2U
#define GPIOA_PIN3                  3U
#define GPIOA_AUDIO_LRCLK           4U
#define GPIOA_AUDIO_EN              5U
#define GPIOA_PIN6                  6U
#define GPIOA_PIN7                  7U
#define GPIOA_PIN8                  8U
#define GPIOA_UART_TX               9U
#define GPIOA_UART_RX               10U
#define GPIOA_PIN11                 11U
#define GPIOA_PIN12                 12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_GPIO                  15U

#define GPIOB_LED                   0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_PIN3                  3U
#define GPIOB_SD_CS                 4U
#define GPIOB_SD_DET                5U
#define GPIOB_SD_MISO               6U
#define GPIOB_SD_MOSI               7U
#define GPIOB_SD_CLK                8U
#define GPIOB_PIN9                  9U

#define GPIOC_PIN6                  6U
#define GPIOC_OSC32 IN              14U
#define GPIOC_OSC32_OUT             15U


/*
 * TinySound board assignments.
 */
#define LINE_LED                    PAL_LINE(GPIOB, GPIOB_LED)
#define LINE_AUDIO_EN               PAL_LINE(GPIOA, GPIOA_AUDIO_EN)      // enable for MAX98360
#define LINE_SD_CS                  PAL_LINE(GPIOB, GPIOB_SD_CS)

#define LINE_SD_DET                 PAL_LINE(GPIOB, GPIOB_SD_DET)

#define LINE_I2S_CK                 PAL_LINE(GPIOA, GPIOA_AUDIO_BCLK)    // I2S1 - CK / BCLK
#define LINE_I2S_SD                 PAL_LINE(GPIOA, GPIOA_AUDIO_DIN)     // I2S1 - SD / DIN
#define LINE_I2S_WS                 PAL_LINE(GPIOA, GPIOA_AUDIO_LRCLK)   // I2S1 - WS / LRCLK

#define LINE_UART_TX                PAL_LINE(GPIOA, GPIOA_UART_TX)
#define LINE_UART_RX                PAL_LINE(GPIOA, GPIOA_UART_RX)

#define LINE_SD_MISO                PAL_LINE(GPIOB, GPIOB_SD_MISO)
#define LINE_SD_MOSI                PAL_LINE(GPIOB, GPIOB_SD_MOSI)
#define LINE_SD_SCK                 PAL_LINE(GPIOB, GPIOB_SD_CLK)



/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
