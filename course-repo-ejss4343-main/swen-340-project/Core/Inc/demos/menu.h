/*
 * menu.h
 *
 *  Created on: Oct 8, 2023
 *      Author: ahlsj
 */

#ifndef INC_DEMOS_MENU_H_
#define INC_DEMOS_MENU_H_

#include "song.h"
#include <stdint.h>

typedef enum{
	OFF,
	ON,
	FLASHING
}led_state;

typedef enum{
	FINISHED,
	PLAYING,
	PAUSED
}music_state;

typedef enum{
	REMOTE,
	MANUAL
}menu_mode;

void EXTI15_10_IRQHandler();

void play();
void stop();
void next();
void pause();
void run_menu();
void start_menu();
void togglePlayPause();

menu_mode getMode();
uint8_t getCurrentSong();
led_state getLEDState();
void setLEDState(led_state state);
music_state getMusicState();
void setMusicState(music_state state);

#endif /* INC_DEMOS_MENU_H_ */
