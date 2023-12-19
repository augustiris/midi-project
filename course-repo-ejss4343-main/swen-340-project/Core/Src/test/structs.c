///*
// * structs.c
// *
// *  Created on: Nov 14, 2023
// *      Author: ahlsj
// */
//
//#include "song.h"
//#include "printf.h"
//#include <string.h>
//#include "structs.h"
//#include <util/endian_conversions.h>
//#include <stdint.h>
//
//void structs(){
//	header* ptr_head;
//	// Assign ptr_head to the start of the first song
//	ptr_head = (header*) get_song(0).p_song;
//
//	char buff[5];
//	strncpy(buff, ptr_head->type, sizeof (char[4]));
//	// strncpy(buff, ptr_head->type, sizeof (ptr_head->type));
//	buff[sizeof (ptr_head->type)] = 0;
//
//	// Print all of the attributes
//	printf("Type: %s\n\r", buff);
//	printf("Length: %ld\n\r", convert_to_uint32((uint8_t*)&ptr_head->length));
//	printf("Format: %d\n\r", convert_to_uint16((uint8_t*)&ptr_head->format));
//	printf("Tracks: %d\n\r", convert_to_uint16((uint8_t*)&ptr_head->tracks));
//	printf("Division: %d\n\r", convert_to_uint16((uint8_t*)&ptr_head->division));
//
//}
