/*
 * remote.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ahlsj
 */

#ifndef INC_DEMOS_REMOTE_H_
#define INC_DEMOS_REMOTE_H_

struct commands {
	char* help;
	char* next;
	char* play;
	char* pause;
	char* stop;
};

void USART2_IRQHandler();
char* getCmd();
int isPlay(char* cmd);
int isPause(char* cmd);

#endif /* INC_DEMOS_REMOTE_H_ */
