/*
 * hw4.c
 *
 *  Created on: Oct 15, 2023
 *      Author: ahlsj
 */

#include "printf.h"
#include "UART.h"
#include "LED.h"
#include "systick.h"

static char buffer [128];

void hw4_readline () {
	uint8_t byte;
	int count = 0;
	byte = USART_Read_Nonblocking (USART2);
	if(byte){
		USART_Write(USART2, &byte, 1);
		buffer[count] = (char)byte;
		if(byte == '\r'){
			USART_Write(USART2, (unsigned char*)"\n", 1);
			buffer[count] = 0;
		}
		count++;
	}
}

void hw4_start(){

	init_systick ();
	int count = 0;

	while (1) {
		count++;
		hw4_readline ();

		// Move 10 count from delay
		delay_systick();

		// To while loop, only toggle every 1000
		if(count == 1000){
			LED_Toggle(D7);
			count = 0;
		}

	}
}
