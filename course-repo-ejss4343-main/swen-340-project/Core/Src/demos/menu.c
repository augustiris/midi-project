/*
 * menu.c
 *
 *  Created on: Oct 8, 2023
 *      Author: ahlsj
 */

#include "menu.h"
#include <player.h>
#include <util/debounce.h>
#include <util/endian_conversions.h>
#include <util/parser.h>
#include <util/messages.h>
#include "printf.h"
#include "UART.h"
#include "LED.h"
#include "systick.h"
#include "GPIO.h"
#include "remote.h"
#include "manual.h"

static uint8_t CURRENT_SONG = 0; // This is the index of the current song from songs[] in song.c.
static menu_mode ACTIVE_MODE = REMOTE; // The current mode of the menu.
static led_state LED_STATE = OFF; // The current status of the LED.
static music_state MUSIC_STATE = OFF; // The current status of the sound.

menu_mode getMode(){
	return ACTIVE_MODE;
}

uint8_t getCurrentSong(){
	return CURRENT_SONG;
}

led_state getLEDState(){
	return LED_STATE;
}

void setLEDState(led_state state){
	LED_STATE = state;
}

music_state getMusicState(){
	return MUSIC_STATE;
}

void setMusicState(music_state state){
	MUSIC_STATE = state;
}

/*
 * Handler for the Blue Button. Pressing it toggles modes.
 */
void EXTI15_10_IRQHandler(){
	if(handleBtn(B1_Pin) && isUpB1()){ // Check for bounce
		ACTIVE_MODE = !ACTIVE_MODE; // Toggle modes
		stop(); // Turn off LED
		setMusicState(FINISHED);
		start_menu();
	}
	HAL_GPIO_EXTI_IRQHandler(B1_Pin); // Clear interrupt
}

/*
 * Toggles PLAYING and PAUSED music state.
 */
void togglePlayPause(){
	if(MUSIC_STATE == PLAYING){
		printf("LED Flashing\n\r");
		MUSIC_STATE = PAUSED;
	}
	else{
		MUSIC_STATE = PLAYING;
	}
}

/*
 * This function turns the LED on.
 */
void play(){
	LED_On(D7); // Turns the LED on.
	song_init(); // Initalizes all song info to 0.
	parseSong(CURRENT_SONG); // Parses MIDI file for song info.
	playNotes();

	switch (MUSIC_STATE){
			case PLAYING:{
				printf("Song #%d Finished.\n\r", CURRENT_SONG);
				setMusicState(FINISHED);
				break;
			}
			case FINISHED:{
				printf("Song #%d Stopped.\n\r", CURRENT_SONG);
				setMusicState(FINISHED);
				break;
			}
			case PAUSED:{
				printf("Song #%d Paused. Use PLAY/PAUSE to continue.\n\r", CURRENT_SONG);
				break;
			}
	}

}

/*
 * This function turns the LED off.
 */
void stop(){
	LED_Off(D7);
}

/*
 * This function makes the LED flash once every second.
 */
void pause(){
	if((getCount() % TICKS_IN_SECOND) == 0)
		LED_Toggle(D7);
}

/*
 * This function prints the next song and moves to the next song in the list.
 */
void next(){
	CURRENT_SONG = CURRENT_SONG == (get_num_songs() - 1) ? 0 : CURRENT_SONG + 1; // Move to the next song.
	printSong();
}


void start_menu(){
	if(ACTIVE_MODE == REMOTE)
		printPrompt();

	printMode();
}

/*
 * This function has an infinite loop which calls the correct method depending on which state the music is in.
 */
void run_menu() {
	start_menu();

	while(1){
		switch (MUSIC_STATE){
				case PLAYING:{
					play();
					break;
				}
				case FINISHED:{
					stop();
					break;
				}
				case PAUSED:{
					pause();
					break;
				}
			}
	}

}
