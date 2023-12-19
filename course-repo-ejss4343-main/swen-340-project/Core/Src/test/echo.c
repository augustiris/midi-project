/*
 * echo.c
 *
 *  Created on: Nov 8, 2023
 *      Author: ahlsj
 */

#include "UART.h"
#include "printf.h"

//void USART2_IRQHandler(){
//	uint8_t byte = USART2_Read(USART2); // Reads the next byte
//	USART_Write(USART2, &byte, 1); // Echo the char
//	if(byte == '\r'){ // Signal that a line has been entered.
//		USART_Write(USART2, (unsigned char*)"\n", 1);
//	}
//}
