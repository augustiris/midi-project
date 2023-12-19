/*
 * song_translator.c
 *
 *  Created on: Dec 4, 2023
 *      Author: ahlsj
 */

#include <player.h>
#include <stdint.h>
#include <util/parser.h>
#include "tone.h"
#include "systick.h"
#include "song.h"
#include <util/endian_conversions.h>
#include "printf.h"
#include "menu.h"

/**
 * Plays all the note events in the MIDI file.
 */
void playNotes(){
	int num_notes = getNumNotes(); // The total number of note events.
	uint32_t* timing = getTiming(); // An array of the delays between each note event.
	int current_note = 0; // The index of the current note event.
	uint32_t lastEventTime = 0; // The system time of the last time a note event was executed.

	while(current_note < num_notes && getMusicState() == PLAYING){
		uint32_t curr_time = getCount(); // Current system time.
		if(timing[current_note] < (curr_time - lastEventTime)){ // If the delay for the current note event has been reached.
			useCurrentNote(current_note); // Add the note to tones.
			current_note++; // Move to the next note event.
			lastEventTime = curr_time; // Update last event time.
		}
		play_tones(); // Play the tones.
	}
}

/**
 * Given a note event, if note ON add to tones, else if note OFF remove from tones.
 */
void useCurrentNote(int note_num){
	tone_info* note_info = getSongInfo();
	int* note_on_event = getNoteOnEvent();

	if(note_on_event[note_num]){
		add_tone(note_info[note_num]); // Add tone
	}
	else{
		remove_tone(note_info[note_num]); // Remove note
	}
}

/**
 * Function for testing the volume and frequency of a note.
 * Given a frequency and velocity a note is played indefinitely.
 */
void run_wave(float freq, uint8_t velocity) {
	uint32_t duration = hertz_to_duration (freq);

	while(1){
		if((getCount() % duration) < (duration >> 1)){
			DAC_Set_Value (velocity);
		}
		else{
			DAC_Set_Value (0);
		}
	}
}
