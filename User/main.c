/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   用3.5.0版本库建的工程模板
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "led.h"

void vTaskFunctionForTaskInFo(void *pvParameters)
{
  uint8_t pcWriteBuffer[500];

  printf("=================================================\r\n");
  printf("任务名 任务状态 优先级 剩余栈 任务序号\r\n");
  vTaskList((char *)&pcWriteBuffer);
  printf("%s\r\n", pcWriteBuffer);
}

void vTaskFunction1(void *pvParameters)
{
	for(;;)
	{
		LED1(ON);
		vTaskDelay(250);
		LED1(OFF);
		vTaskDelay(250);
	}
}

void vTaskFunction2(void *pvParameters)
{
	for(;;)
	{
		LED2_TOGGLE();
		vTaskDelay(1000);
	}
}

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	__set_PRIMASK(1);
	LED_GPIO_Config();
	xTaskCreate(vTaskFunction1, "Task 1", 1000, NULL, 1, NULL);
	xTaskCreate(vTaskFunction2, "Task 2", 1000, NULL, 1, NULL);
	
	vTaskStartScheduler();
  for(;;);
}

/*********************************************END OF FILE**********************/
