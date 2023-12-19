// main.c with demo
// Updated and refactored Larry Kiser copyright 2021

// include project specific header files
#include <player.h>
#include <stdio.h>
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "systick.h"
#include "GPIO.h"
#include "printf.h"
#include "menu.h"
#include "dac.h"
#include "tone.h"
#include <util/parser.h>

int main(void){

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init(D7);
	UART2_Init();
	init_systick();
	GPIO_Init();
	DAC_Init();
	DAC_Start();

	// demo code
	run_menu();

}
