/*
 * debounce.c
 *
 *  Created on: Nov 12, 2023
 *      Author: ahlsj
 */

#include <util/debounce.h>
#include "printf.h"
#include "systick.h"
#include "GPIO.h"

/* S1 Variables */
static unsigned int S1_last_time_up = 0; // ms passed when S1 was last up.
static unsigned int S1_last_time_down = 0; // ms passed when S1 was last down.
static unsigned int* p_S1_up = &S1_last_time_up;
static unsigned int* p_S1_down = &S1_last_time_down;

/* B1 Variables */
static unsigned int B1_last_time_up = 0; // ms passed when B1 was last up.
static unsigned int B1_last_time_down = 0; // ms passed when B1 was last down.
static unsigned int* p_B1_up = &B1_last_time_up;
static unsigned int* p_B1_down = &B1_last_time_down;

/*
 * Returns the number of ms that had passed when S1 was last UP.
 */
unsigned int getS1LastTimeUp(){
	return S1_last_time_up;
}

/*
 * Returns the number of ms that had passed when S1 was last DOWN.
 */
unsigned int getS1LastTimeDown(){
	return S1_last_time_down;
}

/*
 * Returns true if S1 is up
 */
unsigned int isUpS1(){
	return HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin) == GPIO_PIN_RESET;
}

/*
 * Returns true if B1 is up
 */
unsigned int isUpB1(){
	return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET;
}

/*
 * Calls the button handler with the correct info to determine if the
 * button was pressed or if bounce created the interrupt.
 */
uint8_t handleBtn(uint16_t GPIO_Pin){
	switch (GPIO_Pin){
		case S1_Pin:{
			// Check the state of the pin for the last event.
			unsigned int* last_event = isUpS1() ? p_S1_up : p_S1_down;
			return filterInterrupt(S1_Pin, last_event);
		}
		case B1_Pin:{
			unsigned int* last_event = isUpB1() ? p_B1_down : p_B1_up;
			return filterInterrupt(B1_Pin, last_event);
		}
	}
	return 0;
}

/*
 * Checks to see if at least 50 ms has passed between interrupts to
 * filter out bounces from button presses. Returns 1 if the interrupt
 * was an actual button press and 0 otherwise. Updates times for last
 * button up and last button down.
 */
uint8_t filterInterrupt(uint16_t GPIO_Pin, unsigned int* last_event){
	unsigned int curr_time = getCount(); // The time in microseconds
	if((curr_time - (*last_event) >= 50000) || *last_event == 0){
		*last_event = curr_time;
		return 1; // Return successful button press.
	}
	return 0;
}
