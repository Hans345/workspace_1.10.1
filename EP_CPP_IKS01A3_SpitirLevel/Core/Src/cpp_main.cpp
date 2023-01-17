/*
 * cpp_main.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "cpp_main.h"
#include "main.h"		//For. HAL-Functions
#include "stdio.h"		//For. printf()
#include "SpiritLevelSignelAxis3LED.h"
#include "stm32f7xx_hal_gpio.h"

/* Private function prototypes -----------------------------------------------*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin); // Overwrite interrupt callback function Button interrupt handling

SpiritLevelSignelAxis3LED ObjAccSensor;

void cpp_main(){
	// Output to Console
	int cnt = 0;
	printf("CPP Main started!\n");
	printf("Cnt=%d",cnt); printf("\n");

	ObjAccSensor.init();
	#ifdef STD_ARRAY // Buffer array
	for(int i=0;i<BUFFERSIZE;i++) //fill the Ringbuffer's
		ObjAccSensor.updateValues();
	#else // Buffer vector
	for(int i=0;i<BUFFERSIZE;i++) //fill the Ringbuffer's
		ObjAccSensor.updateValues();
	#endif

	while (1)
		{
			ObjAccSensor.updateValues();
			ObjAccSensor.show();
			/*if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin))
				ObjAccSensor.setZero();*/
			HAL_Delay(100);
		}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  // reset values to 0
  ObjAccSensor.setZero();
}


