/**
  ******************************************************************************
  * @file    opamp.c
  * @brief   This file provides code for the configuration
  *          of the OPAMP instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "opamp.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

OPAMP_HandleTypeDef hopamp2;
OPAMP_HandleTypeDef hopamp3;

/* OPAMP2 init function */
void MX_OPAMP2_Init(void)
{

  /* USER CODE BEGIN OPAMP2_Init 0 */

  /* USER CODE END OPAMP2_Init 0 */

  /* USER CODE BEGIN OPAMP2_Init 1 */

  /* USER CODE END OPAMP2_Init 1 */
  hopamp2.Instance = OPAMP2;
  hopamp2.Init.PowerMode = OPAMP_POWERMODE_NORMALSPEED;
  hopamp2.Init.Mode = OPAMP_STANDALONE_MODE;
  hopamp2.Init.InvertingInput = OPAMP_INVERTINGINPUT_IO0;
  hopamp2.Init.NonInvertingInput = OPAMP_NONINVERTINGINPUT_IO0;
  hopamp2.Init.InternalOutput = DISABLE;
  hopamp2.Init.TimerControlledMuxmode = OPAMP_TIMERCONTROLLEDMUXMODE_DISABLE;
  hopamp2.Init.UserTrimming = OPAMP_TRIMMING_FACTORY;
  if (HAL_OPAMP_Init(&hopamp2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OPAMP2_Init 2 */

  /* USER CODE END OPAMP2_Init 2 */

}
/* OPAMP3 init function */
void MX_OPAMP3_Init(void)
{

  /* USER CODE BEGIN OPAMP3_Init 0 */

  /* USER CODE END OPAMP3_Init 0 */

  /* USER CODE BEGIN OPAMP3_Init 1 */

  /* USER CODE END OPAMP3_Init 1 */
  hopamp3.Instance = OPAMP3;
  hopamp3.Init.PowerMode = OPAMP_POWERMODE_NORMALSPEED;
  hopamp3.Init.Mode = OPAMP_STANDALONE_MODE;
  hopamp3.Init.InvertingInput = OPAMP_INVERTINGINPUT_IO0;
  hopamp3.Init.NonInvertingInput = OPAMP_NONINVERTINGINPUT_IO0;
  hopamp3.Init.InternalOutput = DISABLE;
  hopamp3.Init.TimerControlledMuxmode = OPAMP_TIMERCONTROLLEDMUXMODE_DISABLE;
  hopamp3.Init.UserTrimming = OPAMP_TRIMMING_FACTORY;
  if (HAL_OPAMP_Init(&hopamp3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OPAMP3_Init 2 */

  /* USER CODE END OPAMP3_Init 2 */

}

void HAL_OPAMP_MspInit(OPAMP_HandleTypeDef* opampHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(opampHandle->Instance==OPAMP2)
  {
  /* USER CODE BEGIN OPAMP2_MspInit 0 */

  /* USER CODE END OPAMP2_MspInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**OPAMP2 GPIO Configuration
    PA5     ------> OPAMP2_VINM
    PA6     ------> OPAMP2_VOUT
    PA7     ------> OPAMP2_VINP
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN OPAMP2_MspInit 1 */

  /* USER CODE END OPAMP2_MspInit 1 */
  }
  else if(opampHandle->Instance==OPAMP3)
  {
  /* USER CODE BEGIN OPAMP3_MspInit 0 */

  /* USER CODE END OPAMP3_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**OPAMP3 GPIO Configuration
    PB0     ------> OPAMP3_VINP
    PB1     ------> OPAMP3_VOUT
    PB2     ------> OPAMP3_VINM
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN OPAMP3_MspInit 1 */

  /* USER CODE END OPAMP3_MspInit 1 */
  }
}

void HAL_OPAMP_MspDeInit(OPAMP_HandleTypeDef* opampHandle)
{

  if(opampHandle->Instance==OPAMP2)
  {
  /* USER CODE BEGIN OPAMP2_MspDeInit 0 */

  /* USER CODE END OPAMP2_MspDeInit 0 */

    /**OPAMP2 GPIO Configuration
    PA5     ------> OPAMP2_VINM
    PA6     ------> OPAMP2_VOUT
    PA7     ------> OPAMP2_VINP
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);

  /* USER CODE BEGIN OPAMP2_MspDeInit 1 */

  /* USER CODE END OPAMP2_MspDeInit 1 */
  }
  else if(opampHandle->Instance==OPAMP3)
  {
  /* USER CODE BEGIN OPAMP3_MspDeInit 0 */

  /* USER CODE END OPAMP3_MspDeInit 0 */

    /**OPAMP3 GPIO Configuration
    PB0     ------> OPAMP3_VINP
    PB1     ------> OPAMP3_VOUT
    PB2     ------> OPAMP3_VINM
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2);

  /* USER CODE BEGIN OPAMP3_MspDeInit 1 */

  /* USER CODE END OPAMP3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
