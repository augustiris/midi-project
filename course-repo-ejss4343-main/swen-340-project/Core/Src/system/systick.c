/*
 * systick.c
 *
 *  Created on: Oct 8, 2023
 *      Author: ahlsj
 */

#include "stdint.h"
#include "systick.h"

static struct systick* SYST_TICK = (struct systick*)0xE000E010;

static uint32_t count = 0;

void SysTick_Handler(){
	count++;
}

uint32_t getCount(){
	return count;
}

void Error_Handler(){}

// This function is to Initialize SysTick registers
// Use the SysTick global structure pointer to do the following in this
// exact order with separate lines for each step:
void init_systick()
{
	// Disable SysTick by clearing the CTRL (CSR) register.
	SYST_TICK->CSR &= ~(1 << 0); // Disable

	// Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer (.1 seconds).
	// SYST_TICK->RVR = 7999999;
	// SYST_TICK->RVR = 79; // Set timer to 1 usec
	//	SYST_TICK->RVR = 79999; // Set timer to 1 ms
	SYST_TICK->RVR = 79;

	// Set the clock source bit in the CTRL (CSR) to the internal clock.
	SYST_TICK->CSR |= (1 << 2);

	SYST_TICK->CSR |= (1 << 1); // Enable interrupts

	// Set the enable bit in the CTRL (CSR) to start the timer.
	SYST_TICK->CSR |= (1 << 0); // Enable
}

// This function is to create delay using SysTick timer counter
// for 1 microsecond.
void delay_systick()
{
	while(!(SYST_TICK->CSR & (1 << 16)));
}
