/*
 * button_hw.c
 *
 *  Created on: Oct 1, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"
#include "button_hw.h"

void B1_GPIO_Init(void)
{
	// PC13 as Input
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
}

void B1_EXTI_Init(void)
{
	// Enable SYSCFG block for EXTI Multiplexer
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	// Select EXTI Multiplexer
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

	// Set Rising Edge for EXTI
	EXTI->RTSR1 |= EXTI_RTSR1_RT13;

	// Unmask EXTI13 line
	EXTI->IMR1 |= EXTI_IMR1_IM13;
}

void B1_NVIC_Config(void)
{
	// Set priority for EXTI15_10 interrupt
	NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(NVIC_PRIORITYGROUP_SELECTED, 0, 0));

	// Enable Interrupt
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

uint8_t B1_IsPressed(void)
{
	// Idle - 0
	// Pushed - 1
	if(GPIOC->IDR & GPIO_IDR_IDR_13)
	{
		return 1;
	}
	return 0;
}










