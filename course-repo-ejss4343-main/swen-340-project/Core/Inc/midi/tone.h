/*
 * tone.h
 *
 *  Created on: May 14, 2022
 *      Author: bruce
 */

#ifndef INC_TONE_H_
#define INC_TONE_H_

#include "dac.h"

typedef struct {
	uint32_t duration;
	uint16_t power;
} tone_info;

/**
 * Utility function that converts a frequency into a duration.
 */
uint32_t hertz_to_duration (float hertz);

/**
 * Adds a tone to be played.
 */
uint8_t add_tone (tone_info info);

/**
 * Removes a tone from the current group of tones that can be played.
 */
uint8_t remove_tone (tone_info info);


/**
 * Starts playing any tones that have been added.
 */
void play_tones ();

/**
 * Utility function that converts a key into a duration.
 */
uint32_t key_to_duration (uint8_t key);

#endif /* INC_TONE_H_ */
