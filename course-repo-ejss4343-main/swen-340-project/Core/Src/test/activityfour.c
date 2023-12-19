/*
 * activityfour.c
 *
 *  Created on: Sep 23, 2023
 *      Author: ahlsj
 */

#include "UART.h"
#include <stdio.h>

uint8_t* msb_set (uint8_t value) {
	if(((value & value) >> 7) & (value >> 7))
		return (unsigned char *)1;
	return (unsigned char *)0;
}
