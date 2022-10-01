/*
 * BlinkingLed.h
 *
 *  Created on: Sep 29, 2022
 *      Author: raphael.baumeler
 */

#ifndef BLINKINGLED_H_
#define BLINKINGLED_H_

// for Types: uint8_t: stdint.h
#include <stdint.h>
// for Types: float_t: stdint.h, float.h
#include <float.h>
#include <math.h>

#include "NoneBlockSystemTickDelay.h"
#include "STM32H7Led.h"

class BlinkingLed: public NoneBlockSystemTickDelay, public STM32H7Led {
private:
	float_t Frequency;
	uint16_t DutyCycle;
public:
	BlinkingLed(GPIO_TypeDef* aPort,
				uint16_t aPin,
			    float_t aFrequency=1,
			    uint16_t aDutyCycle=50);
	virtual ~BlinkingLed();

	void processBlinking();

	void setDutyCycle(uint8_t dutyCycle) {
		DutyCycle = dutyCycle;
	}

	void setFrequency(float_t frequency) {
		Frequency = frequency;
	}
};

#endif /* BLINKINGLED_H_ */
