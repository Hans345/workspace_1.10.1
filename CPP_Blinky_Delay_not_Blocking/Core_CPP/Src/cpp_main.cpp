#include "../../Core_CPP/Inc/cpp_main.h"

#include "main.h"
#include <stdio.h> //For: printf()
#include "BlinkingLed.h"

void cpp_main(){
	printf("CPP Main started!\n");
	BlinkingLed LED1(LD1_green_GPIO_Port, LD1_green_Pin);
	LED1.setFrequency(2);	//PB_0:  2Hz, toggle every 250ms
	BlinkingLed LED2(LD2_blue_GPIO_Port, LD2_blue_Pin);
	LED2.setFrequency(1);	//PB_7:  1Hz, toggle every 500ms
	BlinkingLed LED3(LD3_red_GPIO_Port, LD3_red_Pin);
	LED3.setFrequency(0.5);	//PB_14: 0.5Hz, toggle every 1000ms
	while(1){
		LED1.processBlinking();
		LED2.processBlinking();
		LED3.processBlinking();
	}
}
