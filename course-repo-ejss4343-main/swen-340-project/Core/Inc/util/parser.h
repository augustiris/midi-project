/*
 * parser.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#ifndef INC_UTIL_PARSER_H_
#define INC_UTIL_PARSER_H_

#include <stdint.h>
#include "song.h"
#include "tone.h"

/* Meta Events */
#define META_EVENT (uint8_t) 0xFF
#define SEQ_NUM (uint8_t) 0x00
#define TEXT (uint8_t) 0x01
#define COPYRIGHT (uint8_t) 0x02
#define SEQ_NAME (uint8_t) 0x03
#define INSTR_NAME (uint8_t) 0x04
#define LYRIC (uint8_t) 0x05
#define MARKER (uint8_t) 0x06
#define CUE_POINT (uint8_t) 0x07
#define CHAN_PREFIX (uint8_t) 0x20
#define END_TRACK (uint8_t) 0x2F
#define TEMPO (uint8_t) 0x51
#define OFFSET (uint8_t) 0x54
#define TIME_SIG (uint8_t) 0x58
#define KEY_SIG (uint8_t) 0x59
#define SEQUENCER (uint8_t) 0x7F

/* MIDI Event Messages */
#define NOTE_OFF (uint8_t) 0x08
#define NOTE_ON (uint8_t) 0x09
#define KEY_PRESSURE (uint8_t) 0x0A
#define CONTROL_CHANGE (uint8_t) 0x0B
#define PROGRAM_CHANGE (uint8_t) 0x0C
#define CHANNEL_PRESSURE (uint8_t) 0x0D
#define PITCH_WHEEL (uint8_t) 0x0E
#define SYS_EXCLUSIVE (uint8_t) 0x0F

typedef struct {
	uint32_t value;
	int index; // The index after the end last byte of the quantity.
} var_len_quantity;

void parseSong(uint8_t song_number);
uint32_t parseDelay (uint8_t* delay, int* index);
var_len_quantity parse_var_len(uint8_t* quantity, int i);

void printParsedInfo();
void song_init();
int filterMidiEvent(uint8_t* song, int index, uint32_t delay);

int skipThreeByteEvent(int index);
int skipTwoByteEvent(int index);
int skipMetaEvent(uint8_t* song, int index);

int getMaxNotes();
uint32_t* getTiming();
uint32_t getTempo(song piece);
tone_info* getSongInfo();
int* getNoteOnEvent();
int getNumNotes();

#endif /* INC_UTIL_PARSER_H_ */
