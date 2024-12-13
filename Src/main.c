/*
 * main.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */

#include "main.h"
#include "sys_clocks.h"
#include "led.h"
#include "software_timers.h"
#include "button_hw.h"

SoftTimer_t TimerLD2;

void TaskLD2(void);

int main(void)
{
	SystemClockSetup();
	// Init global NVIC Group configuration
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_SELECTED);

	LED_LD2_Init();

	SoftTimerAction(&TimerLD2, TaskLD2);
	SoftTimerStart(&TimerLD2, 500);

	// Init B1 button and EXTI for it
	B1_GPIO_Init();
	B1_EXTI_Init();
	B1_NVIC_Config();

    /* Loop forever */
	while(1)
	{
		SoftTimerEvent(&TimerLD2);
	}
}

void TaskLD2(void)
{
	LED_LD2_Toggle();
}



