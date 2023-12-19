/*
 * endian_conversions.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#ifndef INC_UTIL_ENDIAN_CONVERSIONS_H_
#define INC_UTIL_ENDIAN_CONVERSIONS_H_

uint16_t convert_to_uint16 (uint8_t* p_value);
uint32_t convert_to_uint24 (uint8_t* p_value);
uint32_t convert_to_uint32 (uint8_t* p_value);

#endif /* INC_UTIL_ENDIAN_CONVERSIONS_H_ */
