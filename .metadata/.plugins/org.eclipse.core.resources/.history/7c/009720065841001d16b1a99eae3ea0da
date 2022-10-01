/*
 * BlinkingLed.cpp
 *
 *  Created on: Sep 29, 2022
 *      Author: raphael.baumeler
 */

#include "BlinkingLed.h"

BlinkingLed::BlinkingLed(GPIO_TypeDef *aPort, uint16_t aPin, float_t aFrequency, uint16_t aDutyCycle)	:
STM32H7Led(aPort, aPin), Frequency(aFrequency), DutyCycle(aDutyCycle)
{
	uint32_t Delay = uint32_t((1000.0/aFrequency)*(aDutyCycle/100.0)); //in ms
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
