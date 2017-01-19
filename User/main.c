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

#include<stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

const char *pcTextForTask1 = "Task 1 is runing\r\n";
const char *pcTextForTask2 = "Task 2 is runing\r\n";

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	
	pcTaskName = (char *)pvParameters;
	
	for(;;)
	{
		printf("%s", pcTaskName);
		vTaskDelay(250/portTICK_PERIOD_MS);
	}
}

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void *)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void *)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
  for(;;);
}

/*********************************************END OF FILE**********************/
