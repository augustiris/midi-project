/*
 * printf.c
 *
 *  Created on: Sep 12, 2023
 *      Author: ahlsj
 */

#include "UART.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static char buffer [128];

static void print_string(const char* string, int len){
	USART_Write (USART2, (unsigned char*)string, len);
}

void print_unsigned(uint8_t* string){
	puts((const char*)string);

//	int len = strlen((char*)string);
//
//	uint8_t uint8_array[2];
//	uint8_t* uint8_ptr = uint8_array;
//	uint8_ptr[0] = string;
//	uint8_ptr[1] = 0;
//	USART_Write (USART2, uint8_ptr, len);
}

int puts (const char* string){
	int len = strlen(string);
	print_string(string, len);
	// print_string("\r\n", 2);
	return len;
}

int	putchar (int character){
	char char_array[2];
	char* char_ptr = char_array;
	char_ptr[0] = (char)character;
	char_ptr[1] = '\0';
	return puts(char_ptr);
}

int printf (const char* format, ...){

	va_list aptr;
	int ret;

	va_start(aptr, format);
	ret = vsprintf(buffer, format, aptr);
	va_end(aptr);

	print_string (buffer, ret);

	return(ret);
}
