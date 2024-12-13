/*
 * interrupts.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"

void EXTI15_10_IRQHandler(void)
{
	// Check if EXTI13 is pending
	if(EXTI->PR1 & EXTI_PR1_PIF13)
	{
		EXTI->PR1 = EXTI_PR1_PIF13;
		// Interrupt Routine
	}

//	if(EXTI->PR1 & EXTI_PR1_PIF10)
//	{
//
//	}
}
