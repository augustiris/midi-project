/*
 * song_translator.h
 *
 *  Created on: Dec 4, 2023
 *      Author: ahlsj
 */

#ifndef INC_MIDI_PLAYER_H_
#define INC_MIDI_PLAYER_H_

#include <stdint.h>
#include "song.h"

void useCurrentNote();
void playNotes();
void run_wave(float freq, uint8_t velocity);

#endif /* INC_MIDI_PLAYER_H_ */
