#include "cpp_main.h"
#include "main.h"

#define INTERVALL 100 // intervall in ms
uint32_t last_time;

void cpp_main(){
	last_time = HAL_GetTick();
	while(1){
		// Delay not blocking
		if(HAL_GetTick() - INTERVALL > last_time)
		{
			last_time = HAL_GetTick();
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		}
		// Delay Blocking
		// HAL_Delay(250);
	}
}
