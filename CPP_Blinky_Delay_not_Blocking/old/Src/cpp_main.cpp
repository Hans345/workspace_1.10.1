#include "../../Core_CPP/Inc/cpp_main.h"

#include "main.h"
#include <stdio.h> //For: printf()
#include "BlinkingLed.h"

// #define INTERVALL 500 // intervall in ms
// uint32_t last_time;

void cpp_main(){
	printf("CPP Main started!\n");
	// last_time = HAL_GetTick();
	while(1){
		// Delay not blocking
		// if(HAL_GetTick() - INTERVALL > last_time)
		// {
		//	last_time = HAL_GetTick();
		//	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
		// }
		// Delay Blocking
		// HAL_Delay(250);
		BlinkingLed LED1(GPIOB, GPIO_PIN_7);
		LED1.processBlinking();
	}
}
