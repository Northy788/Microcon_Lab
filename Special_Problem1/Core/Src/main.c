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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
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
char rx_buffer[256];
char tx_buffer[256];
char me[16];
char you[16];
int i = 0;
int header = 0;
int name = 0;
int ready = 0;
int myname = 0;
char c;

uint8_t status = 0; //init
uint8_t exit = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart2, (uint8_t*) &c, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */write_uart2(me);
  uart3_println("");
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  while (exit == 0){

		  //while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET){}
		  if (header == 0)
		  {
//			  while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) &header, strlen(header), 100);
			  uart3_println("Man from U.A.R.T.2!");
			  uart3_println("Quit PRESS q");


//			  while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET){}
//			  while (HAL_UART_Receive(&huart2, (uint8_t*) &c, 1, 1000) == HAL_OK){}
//
//			  while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET){}
//			  while (HAL_UART_Receive(&huart2, (uint8_t*) &c, 1, 1000) == HAL_OK)
//			  {
//				  name1[i] = c;
//				  i++;
//			  }
//			  name1[i] = '\0';
//			  while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) "\t", 1, 100);
//			  HAL_UART_Transmit(&huart3, (uint8_t*) &name1, strlen(name1), 100);
//			  HAL_UART_Transmit(&huart3, (uint8_t*) &ready, strlen(ready), 100);
//			  i = 0;
//			  while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) "\tName : ", 8, 100);
//			  while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE) == RESET){}
//			  while(HAL_UART_Receive(&huart3, (uint8_t*) &c, 1, 1000) == HAL_OK)
//			  {
//					  HAL_UART_Transmit(&huart3, (uint8_t*) &c, 1, 100);
//					  name2[i] = c;
//					  i++;
//			  }
//			  name2[i] = '\0';
//			  HAL_UART_Transmit(&huart2, (uint8_t*) &name2, strlen(name2), 100);
//			  HAL_UART_Transmit(&huart3, (uint8_t*) "\n\r", 2, 100);
			  //status = 1;
			  header = 1;
		  }
		  //print_receive(you, rx_buffer);
//		  i = 0;
		  if (rx_buffer[i - 1] == 127 && name == 0)
		  {
			  name = 1;
			  rx_buffer[i - 1] = '\0';
			  int k = 0;
			  while (rx_buffer[k])
			  {
				  you[k] = rx_buffer[k];
				  k++;
			  }
			  you[k] = '\0';
			  uart3_printtab(you);
			  uart3_println(" is ready!");
			  i = 0;
		  }

		  if (name == 1 && myname == 0)
		  {
			  uart3_printtab("Name : ");
			  read_uart3(me);
			  write_uart2(me);
			  uart3_println("");
			  myname = 1;
		  }

		  if (rx_buffer[i - 1] == 127 && ready == 0 && name == 1){
			  ready = 1;
			  rx_buffer[i - 1] = '\0';
			  print_receive(you, rx_buffer);
			  //clear_buffer(rx_buffer);
			  i = 0;
			  if (rx_buffer[i] == 'q' && strlen(rx_buffer) == 1)
			  {
				  ready = 0;
				  exit = 1;
				  if (exit == 1)
				  {
					  uart3_printtab("Exit.");
					  break;
				  }
			  }
		  }

		  if (ready == 1 && name == 1){
			  put_transmit(me, tx_buffer);
			  write_uart2(tx_buffer);
			  int j = 0;
			  while (tx_buffer[j] != 127)
				  j++;
			  tx_buffer[j] = '\0';
			  if (tx_buffer[i] == 'q' && strlen(tx_buffer) == 1)
			  {
			  		exit = 1;
			  		if (exit == 1)
			  		{
			  			uart3_printtab("Exit.");
			  			break;
			  		}
			  }
			  //clear_buffer(tx_buffer);
			  ready = 0;
		  }


//		  if (name == 1)
//		  {
//			  uart3_printtab("")
//			  uart3_print(you);
//
//		  }
//
//		  while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET){}
//		  while (HAL_UART_Receive(&huart2, (uint8_t*) &c, 1, 1000) == HAL_OK)
//		  {
//			  message[i] = c;
//			  i++;
//		  }
//		  message[i] = '\0';
//		  i = 0;
//
//		  HAL_UART_Transmit(&huart3, (uint8_t*) "\t", 1, 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) &name1, strlen(name1), 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) " : ", 3, 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) &message, strlen(message), 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) "\n\r", 2, 100);
//		  if (strlen(message) == 1 && message[0] == 'q')
//		  {rlen(mes
//			  exit = 1;
//			  break;
//		  }
//
//
//		  //while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE) == RESET){}
//		  //while (HAL_UART_Receive(&huart3, (uint8_t*) &c, 1, 1000) == HAL_OK ){}
//		  HAL_UART_Transmit(&huart3, (uint8_t*) "\t", 1, 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) &name2, strlen(name2), 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) " => ", 4, 100);
//		  while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE) == RESET){}
//		  while(HAL_UART_Receive(&huart3, (uint8_t*) &c, 1, 1000) == HAL_OK)
//			  {
//					  HAL_UART_Transmit(&huart3, (uint8_t*) &c, 1, 100);
//					  message[i] = c;
//					  i++;
//			  }
//		  message[i] = '\0';
//		  HAL_UART_Transmit(&huart2, (uint8_t*) &message, strlen(message), 100);
//		  HAL_UART_Transmit(&huart3, (uint8_t*) "\n\r", 2, 100);
//		  if (strlen(message) == 1 && message[0] == 'q')
//		  {
//			  exit = 1;
//			  break;
//		  }
	  }
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV6;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void uart3_print(const char* message)
{
	while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
	HAL_UART_Transmit(&huart3, message, strlen(message), 100);
}

void uart3_println(const char* message)
{
	while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
	HAL_UART_Transmit(&huart3, message, strlen(message), 100);
	HAL_UART_Transmit(&huart3, "\n\r", 2, 100);
}

void uart3_printtab(const char* message)
{
	while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TC) == RESET){}
	HAL_UART_Transmit(&huart3, "\t", 1, 100);
	HAL_UART_Transmit(&huart3, message, strlen(message), 100);
}

void read_uart2(char buffer[1024]){
	char c;
	int i = 0;
	//while (HAL_UART_Receive(&huart2, (uint8_t*) &c, 1, 1000) == HAL_OK){}
	while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET){}
	while (HAL_UART_Receive(&huart2, (uint8_t*) &c, 1, 1000) == HAL_OK)
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
}

void read_uart3(char buffer[1024]){
	char c;
	int i = 0;
	//while (HAL_UART_Receive(&huart3, (uint8_t*) &c, 1, 1000) == HAL_OK){}
	while (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE) == RESET){}
	while (HAL_UART_Receive(&huart3, (uint8_t*) &c, 1, 1000) == HAL_OK)
	{
		HAL_UART_Transmit(&huart3, (uint8_t*) &c, 1, 1000);
		buffer[i] = c;
		i++;
	}
	buffer[i] = 127;

}

void write_uart2(const char* message){
	while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TC) == RESET){}
	HAL_UART_Transmit(&huart2, message, strlen(message), 100);
}

void put_transmit(const char* transmitter, char buffer[1024]){
	uart3_printtab(transmitter);
	uart3_print(" => ");
	read_uart3(buffer);
	uart3_println("");
}

void print_receive(const char* receiver, char buffer[1024]){
	uart3_printtab(receiver);
	uart3_print(" : ");
	uart3_println(buffer);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == huart2.Instance){
		rx_buffer[i] = c;
		i++;
		HAL_UART_Receive_IT(&huart2, (uint8_t*) &c, 1);

	}
}

void clear_buffer(char buffer[1024]){
	for (int i = 0; i < 256; i++)
	{
		buffer[i] = '\0';
	}
}
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
void assert_failed(uint8_t *file, uint32_t line)bufferbuffer
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
