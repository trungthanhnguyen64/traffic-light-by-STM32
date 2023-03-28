/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define LED7SEG_A   GPIO_PIN_0
#define LED7SEG_B   GPIO_PIN_1
#define LED7SEG_C   GPIO_PIN_2
#define LED7SEG_D   GPIO_PIN_3

#define LED1        GPIO_PIN_12
#define LED2        GPIO_PIN_13
#define LED3       	GPIO_PIN_14
#define LED4        GPIO_PIN_15

#define LED_DO        GPIO_PIN_5
#define LED_VANG      GPIO_PIN_4
#define LED_XANH      GPIO_PIN_3

#define LED_DO1       GPIO_PIN_9
#define LED_VANG1     GPIO_PIN_8
#define LED_XANH1     GPIO_PIN_7

#define PORT_LED7SEG_CODE GPIOA
#define PORT_LED          GPIOB

#define delayTime1          5


int green_light_time = 25;
int yellow_light_time = 3;
int red_light_time;
int time_counter = 0;
int time_run;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void led7seg( int y){
	switch(y){
		case 0 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 1 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 2 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 3 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 4 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 5 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 6 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 7 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_RESET);
							break;
		case 8 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_SET);
							break;
		case 9 : 	HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_A, GPIO_PIN_SET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_B, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_C, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(PORT_LED7SEG_CODE, LED7SEG_D, GPIO_PIN_SET);
							break;
	}
}
void show7Seg2(int c, int x){
	int x1, x2;
		x1 = x/10;
		x2 = x%10;
	if(c == 1){
		HAL_GPIO_WritePin(PORT_LED, LED1, GPIO_PIN_SET);
		led7seg(x1);
		HAL_Delay(delayTime1);
		HAL_GPIO_WritePin(PORT_LED, LED1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PORT_LED, LED2, GPIO_PIN_SET);
		led7seg(x2);
		HAL_Delay(delayTime1);
		HAL_GPIO_WritePin(PORT_LED, LED2, GPIO_PIN_RESET);
	}	else {
		HAL_GPIO_WritePin(PORT_LED, LED3, GPIO_PIN_SET);
		led7seg(x1);
		HAL_Delay(delayTime1);
		HAL_GPIO_WritePin(PORT_LED, LED3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PORT_LED, LED4, GPIO_PIN_SET);
		led7seg(x2);
		HAL_Delay(delayTime1);
		HAL_GPIO_WritePin(PORT_LED, LED4, GPIO_PIN_RESET);

	}
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	
	time_run = 2*(green_light_time+yellow_light_time);
	red_light_time = green_light_time + yellow_light_time;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//		time_counter += 1;
//		if(time_counter > 9)
//			time_counter = 0;
//		for(int i=0; i<25; i++){
//			show7Seg2(1, time_counter);
//			show7Seg2(0, time_counter+10);
//		}
		
		time_counter++;
		if(time_counter > time_run)
			time_counter = 0;
		if(time_counter < green_light_time){
			// cot 1
			HAL_GPIO_WritePin(GPIOB, LED_XANH, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED_VANG, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_DO, GPIO_PIN_SET);
			
			// cot 2
			HAL_GPIO_WritePin(GPIOB, LED_XANH1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_VANG1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED_DO1, GPIO_PIN_RESET);
			
			for(int i=0; i<50; i++){
				show7Seg2(1, green_light_time - time_counter);
				show7Seg2(0, red_light_time - time_counter);
			}
		}	else	if(time_counter < red_light_time){
							// cot 1
							HAL_GPIO_WritePin(GPIOB, LED_XANH, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOB, LED_VANG, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOB, LED_DO, GPIO_PIN_SET);
							
							// cot 2
							HAL_GPIO_WritePin(GPIOB, LED_XANH1, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOB, LED_VANG1, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOB, LED_DO1, GPIO_PIN_RESET);
			
							for(int i=0; i<50; i++){
								show7Seg2(1, red_light_time - time_counter);
								show7Seg2(0, red_light_time - time_counter);
							}
						}	else	if(time_counter < time_run-yellow_light_time){
											// cot 1
											HAL_GPIO_WritePin(GPIOB, LED_XANH, GPIO_PIN_SET);
											HAL_GPIO_WritePin(GPIOB, LED_VANG, GPIO_PIN_SET);
											HAL_GPIO_WritePin(GPIOB, LED_DO, GPIO_PIN_RESET);
											
											// cot 2
											HAL_GPIO_WritePin(GPIOB, LED_XANH1, GPIO_PIN_RESET);
											HAL_GPIO_WritePin(GPIOB, LED_VANG1, GPIO_PIN_SET);
											HAL_GPIO_WritePin(GPIOB, LED_DO1, GPIO_PIN_SET);
							
											for(int i=0; i<50; i++){
												show7Seg2(1, time_run - time_counter);
												show7Seg2(0, time_run - time_counter - yellow_light_time);
											}
										}	else {
												// cot 1
												HAL_GPIO_WritePin(GPIOB, LED_XANH, GPIO_PIN_SET);
												HAL_GPIO_WritePin(GPIOB, LED_VANG, GPIO_PIN_SET);
												HAL_GPIO_WritePin(GPIOB, LED_DO, GPIO_PIN_RESET);
												
												// cot 2
												HAL_GPIO_WritePin(GPIOB, LED_XANH1, GPIO_PIN_SET);
												HAL_GPIO_WritePin(GPIOB, LED_VANG1, GPIO_PIN_RESET);
												HAL_GPIO_WritePin(GPIOB, LED_DO1, GPIO_PIN_SET);
												
												for(int i=0; i<50; i++){
													show7Seg2(1, time_run - time_counter);
													show7Seg2(0, time_run - time_counter);
												}
											}
		
		/* USER CODE END WHILE */
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 PB15
                           PB3 PB4 PB5 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
