/*
 * header.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ahlsj
 */

#include "header.h"
#include <stdint.h>
#include <util/endian_conversions.h>
#include "song.h"
#include <string.h>

/*
 * Given the start of a song returns a header struct with the song's
 * length, format, tracks, and division.
 */
header* getHeader(uint8_t song_number){
	header* ptr_head;
	// Assign ptr_head to the start of the song
	ptr_head = (header*) get_song(song_number).p_song;

	char buff[5];
	strncpy(buff, ptr_head->type, sizeof (char[4]));
	buff[sizeof (ptr_head->type)] = 0;

	return ptr_head;
}

uint32_t getLength(header* header){
	return convert_to_uint32((uint8_t*)&header->length);
}

uint16_t getFormat(header* header){
	return convert_to_uint16((uint8_t*)&header->format);
}

uint16_t getTracks(header* header){
	return convert_to_uint16((uint8_t*)&header->tracks);
}

uint16_t getDivision(header* header){
	return convert_to_uint16((uint8_t*)&header->division);
}
