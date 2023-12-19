/*
 * printf.h
 *
 *  Created on: Sep 12, 2023
 *      Author: ahlsj
 */

#ifndef INC_SYSTEM_PRINTF_H_
#define INC_SYSTEM_PRINTF_H_

#include <stdint.h>

int printf (const char* format, ...);
int puts (const char* string);
int	putchar (int character);
void print_unsigned(uint8_t* string);

#endif /* INC_SYSTEM_PRINTF_H_ */
