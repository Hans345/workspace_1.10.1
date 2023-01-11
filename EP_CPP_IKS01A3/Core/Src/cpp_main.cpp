/*
 * cpp_main.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "cpp_main.h"
#include "main.h"		//For. HAL-Functions
#include "stdio.h"		//For. printf()


void cpp_main(){
	// Output to Console
	int cnt = 0;
	printf("CPP Main started!\n");
	printf("Cnt=%d",cnt); printf("\n");

	while (1)
		{
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			HAL_Delay(250);
		}
}


