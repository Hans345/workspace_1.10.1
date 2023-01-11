#include "../../Core_CPP/Inc/cpp_main.h"

#include "main.h"
#include <stdio.h> 		//For: printf()
#include <stdint.h> 	//For: int16_t

void cpp_main(){
	printf("CPP Main started!\n");

	// Output to Console
	int16_t cnt = 0;
	printf("Cnt=%d",cnt); printf("\n");

	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		HAL_Delay(250);
	}
}
