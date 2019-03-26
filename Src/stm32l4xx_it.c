/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l4xx_it.h"
#include "cmsis_os.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
int count_send_pulse = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
/* USER CODE BEGIN EV */
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  osSystickHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

	if(__HAL_GPIO_EXTI_GET_FLAG(RC_CH2_Pin)){

				GPIO_PinState etat_CH2 = HAL_GPIO_ReadPin(RC_CH2_GPIO_Port, RC_CH2_Pin);
				if(etat_CH2 == GPIO_PIN_RESET){
					long pulse_end = __HAL_TIM_GetCounter(&htim2);
					if((pulse_end - pulse_start[1])<0){
						pulse_width[1] = pulse_end - pulse_start[1] + htim2.Init.Period;// En cas d'overflow du timer;
					}
					else{
						pulse_width[1] = pulse_end - pulse_start[1];
					}
				}
				else if(etat_CH2 == GPIO_PIN_SET){
					pulse_start[1] = __HAL_TIM_GetCounter(&htim2);
				}
		}

	if(__HAL_GPIO_EXTI_GET_FLAG(RC_CH3_Pin)){

				GPIO_PinState etat_CH3 = HAL_GPIO_ReadPin(RC_CH3_GPIO_Port, RC_CH3_Pin);
				if(etat_CH3 == GPIO_PIN_RESET){
					long pulse_end = __HAL_TIM_GetCounter(&htim2);
					if((pulse_end - pulse_start[0])<0){
						pulse_width[0] = pulse_end - pulse_start[0] + htim2.Init.Period;// En cas d'overflow du timer;
					}
					else{
						pulse_width[0] = pulse_end - pulse_start[0];
					}
				}
				else if(etat_CH3 == GPIO_PIN_SET){
					pulse_start[0] = __HAL_TIM_GetCounter(&htim2);
				}
		}

	if(__HAL_GPIO_EXTI_GET_FLAG(RC_CH4_Pin)){

				GPIO_PinState etat_CH4 = HAL_GPIO_ReadPin(RC_CH4_GPIO_Port, RC_CH4_Pin);
				if(etat_CH4 == GPIO_PIN_RESET){
					long pulse_end = __HAL_TIM_GetCounter(&htim2);
					if((pulse_end - pulse_start[2])<0){
						pulse_width[2] = pulse_end - pulse_start[2] + htim2.Init.Period;// En cas d'overflow du timer;
					}
					else{
						pulse_width[2] = pulse_end - pulse_start[2];
					}
				}
				else if(etat_CH4 == GPIO_PIN_SET){
					pulse_start[2] = __HAL_TIM_GetCounter(&htim2);
				}
		}
  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(RC_CH2_Pin);
  HAL_GPIO_EXTI_IRQHandler(RC_CH3_Pin);
  HAL_GPIO_EXTI_IRQHandler(RC_CH4_Pin);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
