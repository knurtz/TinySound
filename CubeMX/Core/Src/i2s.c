/**
  ******************************************************************************
  * File Name          : I2S.c
  * Description        : This file provides code for the configuration
  *                      of the I2S instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "i2s.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2S_HandleTypeDef hi2s1;
DMA_HandleTypeDef hdma_spi1_tx;

/* I2S1 init function */
void MX_I2S1_Init(void)
{

  hi2s1.Instance = SPI1;
  hi2s1.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s1.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s1.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s1.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s1.Init.AudioFreq = I2S_AUDIOFREQ_48K;
  hi2s1.Init.CPOL = I2S_CPOL_LOW;
  if (HAL_I2S_Init(&hi2s1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_I2S_MspInit(I2S_HandleTypeDef* i2sHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2sHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* I2S1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**I2S1 GPIO Configuration
    PA1     ------> I2S1_CK
    PA2     ------> I2S1_SD
    PA4     ------> I2S1_WS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* I2S1 DMA Init */
    /* SPI1_TX Init */
    hdma_spi1_tx.Instance = DMA1_Channel1;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_SPI1_TX;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.Mode = DMA_CIRCULAR;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_VERY_HIGH;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(i2sHandle,hdmatx,hdma_spi1_tx);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }
}

void HAL_I2S_MspDeInit(I2S_HandleTypeDef* i2sHandle)
{

  if(i2sHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**I2S1 GPIO Configuration
    PA1     ------> I2S1_CK
    PA2     ------> I2S1_SD
    PA4     ------> I2S1_WS
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4);

    /* I2S1 DMA DeInit */
    HAL_DMA_DeInit(i2sHandle->hdmatx);
  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
