/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
ADC_HandleTypeDef hadc2;
DMA_HandleTypeDef hdma_adc2;

I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DPAD_LEFT_Pin GPIO_PIN_0
#define DPAD_LEFT_GPIO_Port GPIOC
#define DPAD_UP_Pin GPIO_PIN_1
#define DPAD_UP_GPIO_Port GPIOC
#define DPAD_RIGHT_Pin GPIO_PIN_2
#define DPAD_RIGHT_GPIO_Port GPIOC
#define DPAD_DOWN_Pin GPIO_PIN_3
#define DPAD_DOWN_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define JOYSTICK_X_Pin GPIO_PIN_5
#define JOYSTICK_X_GPIO_Port GPIOA
#define JOYSTICK_Y_Pin GPIO_PIN_6
#define JOYSTICK_Y_GPIO_Port GPIOA
#define Joystick_BTN_Pin GPIO_PIN_4
#define Joystick_BTN_GPIO_Port GPIOC
#define BTN_RED_Pin GPIO_PIN_13
#define BTN_RED_GPIO_Port GPIOB
#define BTN_GRN_Pin GPIO_PIN_14
#define BTN_GRN_GPIO_Port GPIOB
#define BTN_YEL_Pin GPIO_PIN_15
#define BTN_YEL_GPIO_Port GPIOB
#define BTN_SHL_Pin GPIO_PIN_6
#define BTN_SHL_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define NUMBER_OF_USER_BUTTONS 4
#define NUMBER_OF_DPAD_BUTTONS 4
#define NUMBER_OF_BUTTONS (NUMBER_OF_USER_BUTTONS + NUMBER_OF_DPAD_BUTTONS)
#define DPAD_UP HAL_GPIO_ReadPin(DPAD_UP_GPIO_Port, DPAD_UP_Pin)
#define DPAD_LEFT HAL_GPIO_ReadPin(DPAD_LEFT_GPIO_Port, DPAD_LEFT_Pin)
#define DPAD_RIGHT HAL_GPIO_ReadPin(DPAD_RIGHT_GPIO_Port, DPAD_RIGHT_Pin)
#define DPAD_DOWN HAL_GPIO_ReadPin(DPAD_DOWN_GPIO_Port, DPAD_DOWN_Pin)
#define BUTTON_SHOULDER HAL_GPIO_ReadPin(BTN_SHL_GPIO_Port, BTN_SHL_Pin)
#define BUTTON_RED HAL_GPIO_ReadPin(BTN_RED_GPIO_Port, BTN_RED_Pin)
#define BUTTON_GREEN HAL_GPIO_ReadPin(BTN_GRN_GPIO_Port, BTN_GRN_Pin)
#define BUTTON_YELLOW HAL_GPIO_ReadPin(BTN_YEL_GPIO_Port, BTN_YEL_Pin)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
