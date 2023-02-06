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
    int32_t AccAvgXAxis=0;
    int32_t AccAvgYAxis=0;
    int32_t AccAvgZAxis=0;
    int32_t AccMinXAxis=0;
    int32_t AccMinYAxis=0;
    int32_t AccMinZAxis=0;
    int32_t AccMaxXAxis=0;
    int32_t AccMaxYAxis=0;
    int32_t AccMaxZAxis=0;

	accGyro.Acc.getAVGValues(&AccAvgXAxis, &AccAvgYAxis, &AccAvgZAxis);
	accGyro.Acc.getMinValues(&AccMinXAxis, &AccMinYAxis, &AccMinZAxis);
	accGyro.Acc.getMaxValues(&AccMaxXAxis, &AccMaxYAxis, &AccMaxZAxis);

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
    std::cout<<"Acc.: \t";
    std::cout<<"X-Axis: "<< AccAvgXAxis << (char) ASCII_TAB;
    std::cout<<"Min: "<< AccMinXAxis << (char) ASCII_TAB;
    std::cout<<"Max: "<< AccMaxXAxis << (char) ASCII_TAB;
    fflush(stdout);
    std::cout<<"Y-Axis: "<< AccAvgYAxis << (char) ASCII_TAB;
    std::cout<<"Min: "<< AccMinYAxis << (char) ASCII_TAB;
    std::cout<<"Max: "<< AccMaxYAxis << (char) ASCII_TAB;
    fflush(stdout);
    std::cout<<"Z-Axis: "<< AccAvgZAxis << (char) ASCII_TAB;
    std::cout<<"Min: "<< AccMinZAxis << (char) ASCII_TAB;
    std::cout<<"Max: "<< AccMaxZAxis << (char) ASCII_TAB;

    std::cout<< (char) ASCII_LF << (char) ASCII_CR;
    fflush(stdout);
#else
	printf("YAxisValue = %d\n",(int)AccAvgYAxis);
#endif
}

void SpiritLevelSignelAxis3LED::setZero(void) {
	accGyro.setZero();
}