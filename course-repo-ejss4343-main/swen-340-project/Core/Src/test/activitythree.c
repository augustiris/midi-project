/*
 * reading.c
 *
 *  Created on: Sep 14, 2023
 *      Author: ahlsj
 */

#include "UART.h"
#include "printf.h"

static char buffer [128];

char* readline2 () {
	uint8_t byte;
	int count = 0;
	while(1) {
		byte = USART_Read (USART2);
		USART_Write(USART2, &byte, 1);
		buffer[count] = (char)byte;
		if(byte == '\r'){
			USART_Write(USART2, (unsigned char*)"\n", 1);
			buffer[count] = 0;
			return buffer;
		}
		count++;
	}
}

void run() {
	while(1){
//		 uint8_t  byte = USART_Read (USART2);
//		 puts ((char*) &byte);
//		 USART_Write(USART2, &byte, 1);
//		uint8_t byte = USART_Read(USART2);
//		putchar((int)byte);

		char* line = readline2();
		puts(line);

	}

}
