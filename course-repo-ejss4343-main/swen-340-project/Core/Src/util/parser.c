/*
 * parser.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#include <player.h>
#include <util/parser.h>
#include <util/endian_conversions.h>
#include <stdint.h>
#include "printf.h"
#include "systick.h"
#include "song.h"
#include "tone.h"
#include "header.h"

#define MAX_NOTE_EVENTS (200)

static uint32_t NOTE_TIMING[MAX_NOTE_EVENTS]; // An array that holds the start time of every note event in microseconds.
static tone_info NOTE_INFO[MAX_NOTE_EVENTS]; // An array that holds the key and velocity of all note events.
static int NOTE_ON_EVENT[MAX_NOTE_EVENTS]; // An array that holds whether a note event is of type ON or OFF.
static int NUM_NOTE_EVENTS; // The total number of note events in the current song.

int getMaxNotes(){
	return MAX_NOTE_EVENTS;
}

uint32_t* getTiming(){
	return NOTE_TIMING;
}

tone_info* getSongInfo(){
	return NOTE_INFO;
}

int* getNoteOnEvent(){
	return NOTE_ON_EVENT;
}

int getNumNotes(){
	return NUM_NOTE_EVENTS;
}

/*
 * Initializes all note event info to 0.
 */
void song_init(){
	for(int i = 0; i < (MAX_NOTE_EVENTS*2); i++){
		NOTE_TIMING[i] = 0;
		NOTE_INFO[i] = (tone_info){0,0};
		NOTE_ON_EVENT[i] = 0;
	}
	NUM_NOTE_EVENTS = 0;
}

/*
 * Testing function for checking MIDI data was parsed correctly.
 */
void printParsedInfo(){
	for(int i = 0; i < NUM_NOTE_EVENTS; i++){
		printf("Time:%ld\n\rDuration:%ld\n\rPower:%d\n\rType:%d\n\n\r",
				NOTE_TIMING[i],
				NOTE_INFO[i].duration,
				(NOTE_INFO[i].power),
				NOTE_ON_EVENT[i]
		);

	}
	printf("# Notes:%d\n\r", NUM_NOTE_EVENTS);
}

/*
 * Parses a song at the given index and gets the song's header info and tempo.
 * All note events data is recorded in:
 * 	NOTE_TIMING - An array that holds the start time of every note event in microseconds.
 * 	NOTE_INFO - An array that holds the key and velocity of all note events.
 * 	NOTE_ON_EVENT - An array that holds whether a note event is of type ON or OFF.
 * 	NUM_NOTE_EVENTS - The number of note events in a song.
 */
void parseSong(uint8_t song_number){
	song piece = get_song(song_number);

	// Get header info
	int header_length = 14; // A chunk with a length of 6 occupies 14 bytes.
	header* ptr_head = getHeader(song_number);
	uint16_t division = getDivision(ptr_head);
	uint16_t tracks = getTracks(ptr_head);

	// Get tick info
	uint32_t tempo = getTempo(piece);
	uint32_t microseconds_in_a_midi_tick = tempo / division;

	int i = header_length; // Index for song info

	// Iterate over each track after header
	for (int k = 0; k < tracks; k++){
		i += 4; // Skip Track Chunk Bytes 0x4d,0x54,0x72,0x6b

		uint32_t chunk_length = convert_to_uint32(&piece.p_song[i]);
		i += 4; // Each chunk has a 32-bit length, skip ahead.

		int j = i; // New index for parsing individual chunks.
		while(j < (i + chunk_length)){ // Iterate through events in chuck.
			// Get event delay
			var_len_quantity delay_result = parse_var_len(piece.p_song, j);
			uint32_t delay = delay_result.value;
			j = delay_result.index; // Move to start of event type

			uint32_t microseconds_in_delay = delay * microseconds_in_a_midi_tick; // The amount of time before the following event.

			if(piece.p_song[j] == META_EVENT){
				j = skipMetaEvent(piece.p_song, j); // Skip all meta event and update pointer to end of event.
			}
			else{
				j = filterMidiEvent(piece.p_song, j, microseconds_in_delay); // Handle MIDI event and updates j pointer to end of event.
			}

		}
		i = j; // Update i pointer to j pointer (end of event)

	}

	printf("Song #%d Loaded.\n\r", song_number);
}

/*
 * Parses a MIDI variable length quantity where the first bit of 8 is
 * a continuation bit and the 7 others are data. Returns a var_len_quantity
 * struct that holds the data and the index after the quantity in the given array.
 */
var_len_quantity parse_var_len(uint8_t* quantity, int index) {
    uint8_t curr = quantity [index];
    uint32_t parsed_quantity = 0;
    while (curr >> 7) {
        parsed_quantity += (curr & 0x7F) << 7;
        curr = quantity [++index];
    }
    parsed_quantity += curr & 0x7F;
    index++;

    return (var_len_quantity){parsed_quantity, index};
}

/*
 * Parses MIDI events for note ON and OFF events and updates
 * NOTE_TIMING, NOTE_INFO, NOTE_ON_EVENT, and NUM_NOTE_EVENTS.
 */
int filterMidiEvent(uint8_t* song, int index, uint32_t delay){
	uint8_t type = (song[index] >> 4); // Look at status bits
	switch (type){
		case NOTE_OFF:{
			index++; // Skip status and channel number byte
			uint8_t key = song[index];
			index++; // Skip key
			uint8_t velocity = song[index];
			index++; // Skip velocity

			NOTE_TIMING[NUM_NOTE_EVENTS] = delay;
			NOTE_INFO[NUM_NOTE_EVENTS] = (tone_info){key_to_duration(key), velocity};
			NOTE_ON_EVENT[NUM_NOTE_EVENTS] = 0;
			NUM_NOTE_EVENTS++; // Increase number of note events.
			return index;
		}
		case NOTE_ON:{
			index++; // Skip status and channel number byte
			uint8_t key = song[index];
			index++; // Skip key
			uint8_t velocity = song[index];
			index++; // Skip velocity

			NOTE_TIMING[NUM_NOTE_EVENTS] = delay;
			NOTE_INFO[NUM_NOTE_EVENTS] = (tone_info){key_to_duration(key), velocity};
			NOTE_ON_EVENT[NUM_NOTE_EVENTS] = 1;
			NUM_NOTE_EVENTS++; // Increase number of note events.
			return index;
		}
		case KEY_PRESSURE:{
			return skipThreeByteEvent(index);
		}
		case CONTROL_CHANGE:{
			return skipThreeByteEvent(index);
		}
		case PROGRAM_CHANGE:{
			return skipTwoByteEvent(index);
		}
		case CHANNEL_PRESSURE:{
			return skipTwoByteEvent(index);
		}
		case PITCH_WHEEL:{
			return skipThreeByteEvent(index);
		}
		case SYS_EXCLUSIVE:{
			return skipThreeByteEvent(index);
		}
		default:
			return 0;
	}
}

int skipMetaEvent(uint8_t* song, int index){
	index += 2; // Skip 0xff and event type

	var_len_quantity event_len_result = parse_var_len(song, index);

	// Update index to end of event by adding the length of the event to the index where the length ends.
	return event_len_result.index + event_len_result.value;
}

int skipThreeByteEvent(int index){
	return index += 3;
}

int skipTwoByteEvent(int index){
	return index += 2;
}

/*
 * Parses song data for tempo.
 */
uint32_t getTempo(song piece) {
	int i = 0;
	int song_length = piece.size / sizeof(unsigned char);

	while((i + 1) < song_length){
		unsigned char byte = piece.p_song[i];
		if(byte == 0xff && piece.p_song[i+1] == TEMPO){
			i += 3; // Skip 0xff, event type, and length
			return convert_to_uint24 (piece.p_song + i);
		}
		i++;
	}
	return 0;
}
