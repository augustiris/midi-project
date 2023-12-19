/*

 * bounceexample.c
 *
 *  Created on: Nov 12, 2023
 *      Author: ahlsj


typedef enum{
          NOT_PRESSED,
          BOUNCE,
          PRESSED
}button_state_t;

static button_state_t btn_sm_state = NOT_PRESSED;
static uint32_t curr_time = millis();

static uint8_t process_button_pad_value(uint8_t btn_pad_value)
{
   switch(btn_sm_state){
   	   case NOT_PRESSED:{
   		   if(btn_pad_value){
   			   btn_sm_state = BOUNCE;
   			   curr_time = millis();
   		   }
   		   break;
   	   }
   	   case BOUNCE:{
   		  if(millis() - curr_time >= 50 ){
			  //50ms has passed
			  if(btn_pad_value){
				  btn_sm_state = PRESSED;
				  return btn_pad_value;
			  }
			  else
				  btn_sm_state = NOT_PRESSED;
   		  }
   		  break;
   	   }
   	   case PRESSED:{
   		   if(!btn_pad_value){
   			   btn_sm_state = BOUNCE;
   			   curr_time = millis();
   		   }
   		   break;
   	   }
   }
   return 0;
}

//static uint16_t delayTime = 500; // Time in ms for interrupt delays.
//static unsigned char flgTone = 0; // Number of valid presses.
//// static unsigned char intsFound = 0; // Total number of interrupts detected.
//
//static uint16_t state = 1; // 1 for pressed and 0 otherwise.
//static uint32_t lastButtonTime = 0; // The number of ms passed the last time an interrupt was created.
//
//void EXTI9_5_IRQHandler(){ // S1 Handler
//	HAL_GPIO_EXTI_IRQHandler(S1_Pin); // Clear interrupt
//
//	// Filter out too quick buttons = errors.
//	if (milliseconds - lastButtonTime > 300) {
//		state = !state;
//		if (state)
//			delayTime = 500;
//		else
//			delayTime = 50;
//		flgTone++;
//		lastButtonTime = milliseconds;
//	}
//	// intsFound++;
//	delay_by_ms(delayTime);
//}

*/
