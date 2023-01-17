/*
 * SpiritLevelSignelAxis3LED.cpp
 *
 *  Created on: 11.01.2023
 *      Author: raphael.baumeler
 */

#include "SpiritLevelSignelAxis3LED.h"

SpiritLevelSignelAxis3LED::SpiritLevelSignelAxis3LED() {
	// TODO Auto-generated constructor stub
}

SpiritLevelSignelAxis3LED::~SpiritLevelSignelAxis3LED() {
	// TODO Auto-generated destructor stub
}

void SpiritLevelSignelAxis3LED::init(void) {
	SpiritLevelSignelAxis3LED::accGyro.initSensor();
	SpiritLevelSignelAxis3LED::ledNegAngle = STM32H7Led(GPIOB, GPIO_PIN_0); //Green
	SpiritLevelSignelAxis3LED::ledBalanced = STM32H7Led(GPIOB, GPIO_PIN_7); //Blue
	SpiritLevelSignelAxis3LED::ledPosAngle = STM32H7Led(GPIOB, GPIO_PIN_14);//Red
}

void SpiritLevelSignelAxis3LED::updateValues(void) {
	SpiritLevelSignelAxis3LED::accGyro.updateValues();
}

void SpiritLevelSignelAxis3LED::show(void) {
	int32_t AccAvgXAxis;
	int32_t AccAvgYAxis;
	int32_t AccAvgZAxis;

	accGyro.Acc.getAVGValues(&AccAvgXAxis, &AccAvgYAxis, &AccAvgZAxis);

	if(AccAvgYAxis>200){
		ledNegAngle.unsetLED();
		ledBalanced.unsetLED();
		ledPosAngle.setLED();
	}
	else {
		if((AccAvgYAxis< (-200))){
			ledNegAngle.setLED();
			ledBalanced.unsetLED();
			ledPosAngle.unsetLED();
		}
		else
		{
			ledNegAngle.unsetLED();
			ledBalanced.setLED();
			ledPosAngle.unsetLED();

		}
	}
#ifdef COUT
    std::cout<<"YAxisValue = "<< AccAvgYAxis << (char) ASCII_TAB;
    std::cout<< (char) ASCII_LF << (char) ASCII_CR;
    fflush(stdout);
#else
	printf("YAxisValue = %d\n",(int)AccAvgYAxis);
#endif
}

void SpiritLevelSignelAxis3LED::setZero(void) {
	accGyro.setZero();
}
