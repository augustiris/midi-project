/*
 * timer.c
 *
 *  Created on: Oct 3, 2023
 *      Author: ahlsj
 */

#include "systick.h"
#include "printf.h"

static struct systick* SYST_TICK = (struct systick*)0xE000E010;

void init_syst(){
	printf("0x%x\n", (unsigned int)SYST_TICK);

	// Set timer to 10 ms
	SYST_TICK->RVR = 7999999;
	// Turn on timer
	SYST_TICK->CSR |= (1 << 2); // Use pc source
	SYST_TICK->CSR |= (1 << 0); // Enable
}

void timer_clock(){
	init_syst();

	int count = 0;
	int seconds = 0;

	while(1){
		if((SYST_TICK->CSR >> 16) == 1){
			count++;
			if(count == 1000){
				seconds++;
				count = 0;
				printf("%d\r\n", seconds);
			}

		}
	}
}
