/*
 * BlinkingLed.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#include "../../Core_CPP/Inc/BlinkingLed.h"

BlinkingLed::BlinkingLed(GPIO_TypeDef* aPort, uint16_t aPin, float_t aFrequency, uint8_t aDutyCycle)	:
STM32H7Led(aPort, aPin), Frequency(aFrequency), DutyCycle(aDutyCycle)
{
	uint32_t Delay = (1000/aFrequency)*(aDutyCycle/100); //in ms
	NoneBlockSystemTickDelay::DelayNonBlocking_Init(Delay);
}

BlinkingLed::~BlinkingLed() {

}


void BlinkingLed::processBlinking() {
	if(NoneBlockSystemTickDelay::DelayNonBlocking_CheckExpiration())
	{
		STM32H7Led::toggleLED();
	}
}
