/*
 * clock.c
 *
 *  Created on: Nov 7, 2023
 *      Author: ahlsj
 */

#include "systick.h"
#include "printf.h"

static int count = 0;

//void SysTick_Handler(){
//	// This is called whenever the systick roll over
//	count++;
//}

void clock() {
	// initilization
	init_systick();

	// print out time every second
	int seconds = 0;

	while(1){
		if(count == 1000){
			seconds++;
			count = 0;
			printf("%d\r\n", seconds);
		}
	}

}
