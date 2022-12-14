/*
 * BlinkingLed.h
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#ifndef SRC_BLINKINGLED_H_
#define SRC_BLINKINGLED_H_

// for Types: uint8_t: stdint.h
#include <stdint.h>
// for Types: float_t: stdint.h, float.h
#include <float.h>
#include <math.h>

class BlinkingLed{
private:
	float_t Frequency;
	uint8_t DutyCycle;
public:
	BlinkingLed(GPIO_TypeDef* aPort,
				uint16_t aPin,
			    float_t aFrequency=1,
			    uint8_t aDutyCycle=50);
	virtual ~BlinkingLed();

	void processBlinking();

	void setDutyCycle(uint8_t dutyCycle) {
		DutyCycle = dutyCycle;
	}

	void setFrequency(float_t frequency) {
		Frequency = frequency;
	}
};

#endif /* SRC_BLINKINGLED_H_ */
