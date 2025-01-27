/*
 * SchM_DigitalClock.h
 *
 *  Created on: Jul 2, 2023
 *      Author: Jesus
 */

#ifndef INC_SCHM_BASE_H_
#define INC_SCHM_BASE_H_

#include "FreeRTOS.h"
#include "timers.h"

extern TimerHandle_t buzzer_timer;

void Task_Generation(void);
void delay_buzzer_start(void);
void ShcM_Alarm_buzzer_start(void);

#endif /* INC_SCHM_BASE_H_ */
