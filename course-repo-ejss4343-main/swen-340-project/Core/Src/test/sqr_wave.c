///*
// * sqr_wave.c
// *
// *  Created on: Nov 28, 2023
// *      Author: ahlsj
// */
//
//#include <stdint.h>
//#include "tone.h"
//#include "printf.h"
//#include "debounce.h"
//#include "systick.h"
//#include "sqr_wave.h"
//#include "sqr_wave.h"
//#include "dac.h"
//
//static int count = 0;
//
//void SysTick_Handler(){
//	count++;
//}
//
//void Error_Handler(){
//
//}
//
//void run_wave(uint32_t freq) {
//	DAC_Init ();
//	DAC_Start ();
//
//	// Continuously print 1 for half the frequency duration and 0 for the other half.
//	uint32_t duration = hertz_to_duration (freq);
//
//	while(1){
//		if((count % duration) < (duration >> 1)){
//			// printf("%d\n\r", 1);
//			DAC_Set_Value (2000);
//		}
//		else{
//			// printf("%d\n\r", 0);
//			DAC_Set_Value (0);
//		}
//
//	}
//
//}
//
//// 1000 vol
