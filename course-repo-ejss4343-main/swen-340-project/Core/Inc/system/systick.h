/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "stdint.h"

#define TICKS_IN_SECOND (1000000)

// Create a systick struct here
struct systick {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

void init_systick();

// This function is to create delay using SysTick timer counter
void delay_systick();

void SysTick_Handler();
uint32_t getCount();
void Error_Handler();

#endif /* INC_SYSTICK_H_ */
