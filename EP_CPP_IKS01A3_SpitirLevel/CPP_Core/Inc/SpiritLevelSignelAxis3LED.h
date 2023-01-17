/*
 * SpiritLevelSignelAxis3LED.h
 *
 *  Created on: 11.01.2023
 *      Author: raphael.baumeler
 */

#ifndef SPIRITLEVELSIGNELAXIS3LED_H_
#define SPIRITLEVELSIGNELAXIS3LED_H_

#include "AccGyroSensor.h"
#include "stm32f7xx_hal.h"
#include "STM32H7Led.h"

#ifdef COUT
#define ASCII_TAB 	(0x09)
#define ASCII_LF 	(0x0A)
#define ASCII_CR	(0x0D)
#include <iostream>		//For std::cout
#else
#include <stdio.h>		//For printf()
#endif

class SpiritLevelSignelAxis3LED {
private:
	const int32_t Threshold = 200;
public:
	AccGyroSensor accGyro;
	STM32H7Led ledNegAngle;
	STM32H7Led ledBalanced;
	STM32H7Led ledPosAngle;
	SpiritLevelSignelAxis3LED();
	virtual ~SpiritLevelSignelAxis3LED();
	void init(void);
	void updateValues(void);
	void show(void);
	void setZero(void);
};

#endif /* SPIRITLEVELSIGNELAXIS3LED_H_ */
