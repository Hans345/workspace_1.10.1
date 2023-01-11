/*
 * AccGyroSensor.h
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#ifndef ACCGYROSENSOR_H_
#define ACCGYROSENSOR_H_

#include "IKS01A3Motion.h"

class AccGyroSensor {
private:
	const uint32_t INSTANCE = 0;
	const uint32_t FUNCTION_INIT_ACC_GYRO = MOTION_ACCELERO|MOTION_GYRO;
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
	const uint32_t FUNCTION_GYRO = MOTION_GYRO;
public:
	IKS01A3_Motion Gyro; 	//Composition
	IKS01A3_Motion Acc; 	//Composition
	AccGyroSensor();
	virtual ~AccGyroSensor();
	void initSensor();
	void updateValues();
};

#endif /* ACCGYROSENSOR_H_ */
