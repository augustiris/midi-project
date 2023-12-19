/*
 * buttontest.c
 *
 *  Created on: Nov 2, 2023
 *      Author: ahlsj
 */

#include "LED.h"
#include "printf.h"
#include "GPIO.h"

void testButton(){
	// GPIO_Init();

	while(1){
		unsigned char value = HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin);
		printf("%d", value);
		if(value){ // If GPIOA-9 is 1 turn on LED
			LED_On(D7);
		}
		else{ // Else turn off LED
			LED_Off(D7);
		}
	}
}
