/*
 * debounce.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#ifndef INC_UTIL_DEBOUNCE_H_
#define INC_UTIL_DEBOUNCE_H_

#include <stdint.h>

uint8_t handleBtn(uint16_t GPIO_Pin);
uint8_t filterInterrupt(uint16_t GPIO_Pin, unsigned int* last_event);
unsigned int getS1LastTimeUp();
unsigned int getS1LastTimeDown();
unsigned int isUpS1();
unsigned int isUpB1();

#endif /* INC_UTIL_DEBOUNCE_H_ */
