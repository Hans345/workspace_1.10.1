/*
 * AccSensor.h
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#ifndef ACCSENSOR_H_
#define ACCSENSOR_H_

#include "IKS01A3Motion.h"

class AccSensor {
private:
	const uint32_t INSTANCE = 1;
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
public:
	IKS01A3_Motion Acc; //Composition
	AccSensor();
	virtual ~AccSensor();
	void initSensor();
	void updateValues();
};

#endif /* ACCSENSOR_H_ */
