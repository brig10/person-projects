/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  GPIO_PinState col[8][8];
  GPIO_PinState stack[8][8];

  int row_cnt = -1;
  int size = 3;
  int speed = 125;
  int butt = 1;
  int count = 0;
  int offset = 0;
  int dir = 1;
  int deb_cnt = 0;
  int deb = 25;
  int end_cnt = 0;
  int pause_cnt = 0;

  for (int i=0; i<8; i++){
	  for (int j=0; j<8; j++){
	  col[i][j] = GPIO_PIN_RESET;
	  }
  }

  for (int i=0; i<8; i++){
  	  for (int j=0; j<8; j++){
  	  stack[i][j] = GPIO_PIN_RESET;
  	  }
    }

  col[4][4] = GPIO_PIN_SET;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
  while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET)
  while (1)
  {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);	//row 0 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[0][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[0][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[0][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[0][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[0][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[0][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[0][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[0][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);	//row 1 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[1][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[1][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[1][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[1][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[1][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[1][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[1][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[1][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);	//row 2 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[2][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[2][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[2][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[2][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[2][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[2][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[2][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[2][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);	//row 3 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[3][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[3][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[3][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[3][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[3][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[3][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[3][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[3][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);	//row 4 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[4][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[4][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[4][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[4][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[4][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[4][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[4][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[4][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);	//row 5 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[5][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[5][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[5][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[5][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[5][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[5][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[5][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[5][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);	//row 6 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[6][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[6][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[6][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[6][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[6][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[6][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[6][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[6][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);	//row 7 scan

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, col[7][0]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, col[7][1]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, col[7][2]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, col[7][3]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, col[7][4]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, col[7][5]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, col[7][6]);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, col[7][7]);

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);

	  HAL_Delay(1);

	  //START
	  if (row_cnt == -1){
		  for (int i=0; i<8; i++){
			  for (int j=0; j<8; j++){
					  col[i][j] = GPIO_PIN_SET;
			  }
		  }
		  if (butt == 0){
			  row_cnt++;
			  butt = 2;
		  }
	  }

	  //PAUSE & UPDATE ROW
	  else if (row_cnt > 10){
		  if (pause_cnt == 750){
			  row_cnt += -20;
			  pause_cnt = 0;
			  for (int i=0; i<8; i++){
				  if (row_cnt > 0 && col[row_cnt][i] == GPIO_PIN_SET && col[row_cnt-1][i] == GPIO_PIN_RESET){
					  size -= 1;
					  col[row_cnt][i] = GPIO_PIN_RESET;
				  }
			  }
			  for (int i=0; i<8; i++){
				  for (int j=0; j<8; j++){
						  stack[i][j] = col[i][j];
				  }
			  }
			  count = 0;
			  offset = 0;
			  speed *= 0.75;
			  row_cnt++;
		  }
		  pause_cnt++;
	  }

	  //END
	  else if (row_cnt == 8){
		  if (size == 0){
			  main();
		  }
		  if (end_cnt > 1250){
			  speed = 60;
			  for (int i=0; i<8; i++){
				  for (int j=0; j<8; j++){
						  col[i][j] = GPIO_PIN_RESET;
				  }
			  }
			  if (offset == 7){
				  dir = -1;
			  }
			  if (offset == 0){
				  dir = 1;
			  }
			  if (count == speed){
				  offset += dir;
				  count = 0;
			  }
			  for (int i=0; i<8; i++){
				  col[offset][i] = GPIO_PIN_SET;
			  }
			  count++;
			  if (butt == 0){
				  butt = 2;
				  main();
			  }
		  }
		  end_cnt++;
	  }

	  //GAMING
	  else{
		  if (size == 0){
			  main();
		  }
		  for (int i=0; i<8; i++){
			  for (int j=0; j<8; j++){
					  col[i][j] = stack[i][j];
			  }
		  }
		  if (offset+size > 7){
			  dir = -1;
		  }
		  if (offset == 0){
			  dir = 1;
		  }
		  for (int i=offset; i<size+offset; i++){
			  col[row_cnt][i] = GPIO_PIN_SET;
		  }
		  count++;
		  if (count == speed){
			  offset+=dir;
			  count = 0;
		  }
		  if (butt == 0){
			  butt = 2;
			  row_cnt += 20;
		  }
	  }


	  //BUTTON CHECK
	  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_RESET && butt == 1){
		  butt = 0;
	  }

	  else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_RESET && butt == 0){
		  butt = 2;
	  }

	  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET){
		  deb_cnt++;
		  if (deb_cnt == deb){
			  butt = 1;
			  deb_cnt = 0;
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
  HAL_GPIO_WritePin(GPIOA, R0_Pin|R1_Pin|R2_Pin|R3_Pin
                          |R4_Pin|R5_Pin|R6_Pin|R7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, C0_Pin|C1_Pin|C2_Pin|C3_Pin
                          |C4_Pin|C5_Pin|C6_Pin|C7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : R0_Pin R1_Pin R2_Pin R3_Pin
                           R4_Pin R5_Pin R6_Pin R7_Pin */
  GPIO_InitStruct.Pin = R0_Pin|R1_Pin|R2_Pin|R3_Pin
                          |R4_Pin|R5_Pin|R6_Pin|R7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : C0_Pin C1_Pin C2_Pin C3_Pin
                           C4_Pin C5_Pin C6_Pin C7_Pin */
  GPIO_InitStruct.Pin = C0_Pin|C1_Pin|C2_Pin|C3_Pin
                          |C4_Pin|C5_Pin|C6_Pin|C7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
