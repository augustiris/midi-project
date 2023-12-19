/*
 * messages.h
 *
 *  Created on: Dec 6, 2023
 *      Author: ahlsj
 */

#ifndef INC_UTIL_MESSAGES_H_
#define INC_UTIL_MESSAGES_H_

#include "song.h"

void printMode();
void printPrompt();
void printSong();
void printInvalidCmd();
int printMetaEvent(song piece, unsigned char type);

#endif /* INC_UTIL_MESSAGES_H_ */
