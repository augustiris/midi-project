/*
 * endian_conversions.c
 *
 *  Created on: Nov 17, 2023
 *      Author: ahlsj
 */

#include <stdint.h>
#include <util/endian_conversions.h>

static int BITS_IN_BYTE = 8;
static int BITS_IN_UNIT_16 = 16;
static int BITS_IN_UNIT_24 = 24;
static int BITS_IN_UNIT_32 = 32;

uint16_t convert_to_uint16 (uint8_t* p_value){
	int16_t result = 0;
	int length = BITS_IN_UNIT_16 / BITS_IN_BYTE;
	for(int i = 0; i < length; i++){
		result += (p_value[i] << (8 * ((length - 1) - i)));
	}
	return result;
}

uint32_t convert_to_uint24 (uint8_t* p_value){
	uint32_t result = 0;
	int length = BITS_IN_UNIT_24 / BITS_IN_BYTE;
	for(int i = 0; i < length; i++){
		result += (p_value[i] << (8 * ((length - 1) - i)));
	}
	return result;
}

uint32_t convert_to_uint32 (uint8_t* p_value){
	uint32_t result = 0;
	int length = BITS_IN_UNIT_32 / BITS_IN_BYTE;
	for(int i = 0; i < length; i++){
		result += (p_value[i] << (8 * ((length - 1) - i)));
	}
	return result;
}
