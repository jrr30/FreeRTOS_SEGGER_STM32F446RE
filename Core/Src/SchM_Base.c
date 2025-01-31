/*
 * SchM_DigitalClock.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Jesus
 */



#include "FreeRTOS.h"
#include "task.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SchM_Base.h>

#include "main.h"

TaskHandle_t Task_20ms_Handler = NULL;
TaskHandle_t Task_200ms_Handler = NULL;
TaskHandle_t Task_400ms_Handler = NULL;
TaskHandle_t Task_500ms_Handler = NULL;

TimerHandle_t buzzer_timer = NULL;
TimerHandle_t SchM_timer_alarm_on = NULL;


static void Task_20ms(void * parameters);
static void Task_200ms(void * parameters);
static void Task_400ms(void * parameters);
static void Task_500ms(void * parameters);


void Task_Generation(void)
{

	xTaskCreate(Task_20ms,   "20ms", 200, NULL, 5, &Task_20ms_Handler );
	xTaskCreate(Task_200ms, "200ms", 200, NULL, 2, &Task_200ms_Handler);
	xTaskCreate(Task_400ms, "400ms", 250, NULL, 2, &Task_400ms_Handler);
	xTaskCreate(Task_500ms, "500ms", 200, NULL, 3, &Task_500ms_Handler);

}



/**
  * @brief  This task run every 5ms by the scheduler.
  *
  * @note   This task will handle all activities that need to run at 5ms
  *
  * @param  None
  * @retval None
  */

void Task_20ms(void * parameters)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	for(;;)
	{
	    printf("20ms\n");
	    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(20));
	}
}

/**
  * @brief  This task run every 20ms by the scheduler.
  *
  * @note   This task will handle all activities that need to run at 20ms
  *
  * @param  None
  * @retval None
  */

void Task_200ms(void * parameters)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
	    printf("200ms\n");
	    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(200));
	}
}

/**
  * @brief  This task run every 20ms by the scheduler.
  *
  * @note   This task will handle all activities that need to run at 20ms
  *
  * @param  None
  * @retval None
  */

void Task_400ms(void * parameters)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
	    printf("400ms\n");
	    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(400));
	}
}

/**
  * @brief  This task run every 100ms by the scheduler.
  *
  * @note   This task will handle all activities that need to run at 100ms
  *
  * @param  None
  * @retval None
  */

void Task_500ms(void * parameters)
{
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  for(;;)
    {
      printf("500ms\n");
      vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(500));
    }
}

