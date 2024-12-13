/*
 * button_hw.h
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
#ifndef BUTTON_HW_H_
#define BUTTON_HW_H_

void B1_GPIO_Init(void);
void B1_EXTI_Init(void);
void B1_NVIC_Config(void);

uint8_t B1_IsPressed(void);

#endif /* BUTTON_HW_H_ */
