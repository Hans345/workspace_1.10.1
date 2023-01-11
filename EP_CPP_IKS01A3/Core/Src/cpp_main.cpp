/*
 * cpp_main.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "cpp_main.h"
#include "main.h"		//For. HAL-Functions
#include "stdio.h"		//For. printf()
#include "AccGyroSensor.h"

int32_t AccAvgXAxis;
int32_t AccAvgYAxis;
int32_t AccAvgZAxis;
int32_t GyrAvgXAxis;
int32_t GyrAvgYAxis;
int32_t GyrAvgZAxis;
AccGyroSensor ObjAccGyroSensor;

void cpp_main(){
	// Output to Console
	int cnt = 0;
	printf("CPP Main started!\n");
	printf("Cnt=%d",cnt); printf("\n");

	ObjAccGyroSensor.initSensor();
	for(int i=0;i<6;i++) //fill the Ringbuffers
	ObjAccGyroSensor.updateValues();

	while (1)
		{
			ObjAccGyroSensor.updateValues();

			ObjAccGyroSensor.Acc.getAVGValues(&AccAvgXAxis, &AccAvgYAxis, &AccAvgZAxis);
		    ObjAccGyroSensor.Gyro.getAVGValues(&GyrAvgXAxis, &GyrAvgYAxis, &GyrAvgZAxis);

			if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin))
			{
				ObjAccGyroSensor.Acc.setZero();
				ObjAccGyroSensor.Gyro.setZero();
			}

		    printf("Acc.: \n");
		    printf("X-Axis: %d\n", (int)AccAvgXAxis);
		    printf("Y-Axis: %d\n", (int)AccAvgYAxis);
		    printf("Z-Axis: %d\n", (int)AccAvgZAxis);

		    printf("Gyro.: \n");
		    printf("X-Axis: %d\n", (int)GyrAvgXAxis);
		    printf("Y-Axis: %d\n", (int)GyrAvgYAxis);
		    printf("Z-Axis: %d\n", (int)GyrAvgZAxis);

			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			HAL_Delay(500);
		}
}


