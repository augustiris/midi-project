/*
 * header.h
 *
 *  Created on: Dec 6, 2023
 *      Author: ahlsj
 */

#ifndef INC_MIDI_HEADER_H_
#define INC_MIDI_HEADER_H_

#include <stdint.h>

typedef struct {
	char type[4];
	uint32_t length;
	uint16_t format;
	uint16_t tracks;
	uint16_t division;
} header;

header* getHeader(uint8_t song_number);
uint32_t getLength(header* header);
uint16_t getFormat(header* header);
uint16_t getTracks(header* header);
uint16_t getDivision(header* header);

#endif /* INC_MIDI_HEADER_H_ */
