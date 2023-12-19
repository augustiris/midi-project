/*
 * remote.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#include "remote.h"
#include <string.h>
#include <stdint.h>
#include <util/debounce.h>
#include <util/messages.h>
#include "systick.h"
#include "GPIO.h"
#include "LED.h"
#include "UART.h"
#include "printf.h"
#include "menu.h"

/*
 * This is a struct for storing valid user commands.
 */
static struct commands USER_CMD = {
	.help = "HELP",
	.next = "NEXT",
	.play = "PLAY",
	.pause = "PAUSE",
	.stop = "STOP"
};

/*
 * Whenever a key is pressed check for valid commands.
 */
void USART2_IRQHandler(){
	getCmd();
}

/*
 * This function gets the next line of user input and
 * looks for valid commands. It calls the correct helper
 * function for when commands are found and if invalid
 * input is entered.
 */
char* getCmd(){
	// If in MANUAL mode readline() without echo.
	char* line = (getMode() == MANUAL) ? strupr(readline(0)) : strupr(readline(1));

	if(getMode() == REMOTE && (line != 0)){ // Only attempt to execute cmd if in REMOTE mode and a valid line is entered.
		if(strcmp(USER_CMD.help, line) == 0){
			printPrompt();
		}
		else if(strcmp(USER_CMD.next, line) == 0){
			next();
		}
		else if(strcmp(USER_CMD.play, line) == 0){
			printf("LED On\n\r");
			setMusicState(PLAYING);
		}
		else if(strcmp(USER_CMD.pause, line) == 0){
			printf("LED Flashing\n\r");
			setMusicState(PAUSED);
		}
		else if(strcmp(USER_CMD.stop, line) == 0){
			printf("LED Off\n\r");
			setMusicState(FINISHED);
		}
		else{
			printInvalidCmd();
		}
	}
	return line;
}

int isPlay(char* cmd){
	return (strcmp(USER_CMD.play, cmd) == 0);
}

int isPause(char* cmd){
	return (strcmp(USER_CMD.pause, cmd) == 0);
}

int isStop(char* cmd){
	return (strcmp(USER_CMD.stop, cmd) == 0);
}
