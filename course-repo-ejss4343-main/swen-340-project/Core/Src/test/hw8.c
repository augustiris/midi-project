///*
// * hw8.c
// *
// *  Created on: Nov 28, 2023
// *      Author: ahlsj
// */
//
//#include "hw8.h"
//#include "printf.h"
//
//static int BITS_IN_BYTE = 8;
//
//static unsigned char delay0[] = {
//		0x3B, 0x80, 0x27, 0x00
//}; // 59
//static unsigned char delay1[] = {
//		0x83, 0x18, 0x91, 0x54, 0x64
//}; // 408
//static unsigned char delay2[] = {
//		0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12
//}; // 1132916
//static unsigned char delay3[] = {
//		0x90, 0x82, 0x93, 0x64, 0xD3, 0x89
//}; // 33589372
//
//uint32_t parseDelay (uint8_t* delay){
//	uint32_t result = 0; // The delay
//	uint8_t msb = 1 << (BITS_IN_BYTE - 1); // 1000 0000
//	int i = 0;
//	int data_length = BITS_IN_BYTE - 1; // The length of a section of data for a delay.
//
//	// While MSB in each byte is set
//	while(delay[i] & msb){
//		// Shift previous bytes
//		result = result << (data_length);
//
//		// Add 7 bits of data to result
//		uint8_t byte = delay[i] &= ~msb; // Clear MSB
//		result += byte;
//
//		// Get next byte
//		i++;
//	}
//
//	// Add last byte of data
//	result = result << (data_length);
//	result += delay[i];
//
//	return result;
//
//}
//
//void runParse(){
//	printf("%ld\n\r", parseDelay(delay0));
//	printf("%ld\n\r", parseDelay(delay1));
//	printf("%ld\n\r", parseDelay(delay2));
//	printf("%ld\n\r", parseDelay(delay3));
//}

// Print all of the attributes
//printf("Type: %s\n\r", buff);
//printf("Length: %ld\n\r", getLength(header));
//printf("Format: %d\n\r", getFormat(header));
//printf("Tracks: %d\n\r", getTracks(header));
//printf("Division: %d\n\r", getDivision(header));
