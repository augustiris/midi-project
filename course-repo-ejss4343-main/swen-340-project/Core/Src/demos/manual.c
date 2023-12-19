/*
 * manual.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#include "manual.h"
#include "menu.h"
#include "systick.h"
#include "GPIO.h"
#include "LED.h"
#include <stdint.h>
#include "printf.h"
#include <util/debounce.h>

static uint32_t curr_event; // Get time in microseconds
static uint32_t lastEventTime = 0; // The last time an event happened in ms.
static uint32_t lastTimeDown = 0; // The last time the button was down.
static int isStartOfPeriod = 1; // A period is 1 second.

/*
 * Handler for S1. Covers functionality for various button presses
 * when in manual mode.
 */
void EXTI9_5_IRQHandler(){
	if(getMode() == MANUAL){
		curr_event = getCount(); // Get time in microseconds

		if(isUpS1()){ // The button has been released.
			if(isStartOfPeriod){ // This is the first button press of the period of 1 second.
				togglePlayPause();
				isStartOfPeriod = 0;
				// printf("%s\n\r", "First press");
			}
			else{ // This is the second button press of the period of 1 second.
				if(curr_event - lastEventTime >= 1000000){ // 1 button event in 1 second
					// printf("%s\n\r", "2 slow");
					togglePlayPause();
				}
				else{ // 2 button events in 1 second
					// printf("%s\n\r", "2 fast");
					LED_Off(D7); // Override last button presses.
					next();
				}
				isStartOfPeriod = 1;
			}
			lastEventTime = curr_event; // Update last event to current one.

			uint32_t timeHeld = curr_event - lastTimeDown;
			if((timeHeld >= 1000000) && (lastTimeDown != 0)){ // If held for a second or longer and is not first btn press.
				// printf("%s\n\r", "1 held");
				setMusicState(FINISHED); // Turn off LED
				isStartOfPeriod = 1; // Reset start of period.
				lastEventTime = curr_event; // Update last event to current one.
			}

		}
		else{ // The button is down
			lastTimeDown = curr_event;
		}
	}

	HAL_GPIO_EXTI_IRQHandler(S1_Pin); // Clear interrupt
}

void manualPause(){
	uint32_t count = 0;

	while (1){
		curr_event = getCount() + count; // Get time in microseconds plus count because systick trigger is stalled.

		uint32_t timeHeld = curr_event - lastTimeDown; // Check for time held when first entering loop
		if(timeHeld >= 1000000 && count == 0){ // If held for a second or longer
			// printf("%s\n\r", "2 held");
			stop(); // Turn off LED
			isStartOfPeriod = 1; // Reset start of period.
			lastEventTime = curr_event; // Update last event to current one.
			break;
		}

		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET){ // B1 pressed
			setLEDState(OFF);
			break;
		}
		if(HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin) == GPIO_PIN_SET){ // S1 down
			lastTimeDown = curr_event; // Update last time down
			isStartOfPeriod = 0; // False as this is the first event
			setLEDState(OFF);
			break;
		}

		pause();
	}
}
