/*
 * BlinkingLed.h
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#ifndef SRC_BLINKINGLED_H_
#define SRC_BLINKINGLED_H_

#include <stdint.h>

class BlinkingLed {
private:
	float_t Frequency;
	uint8_t DutyCycle;
public:
	BlinkingLed();
	virtual ~BlinkingLed();

	void setDutyCycle(uint8_t dutyCycle) {
		DutyCycle = dutyCycle;
	}

	void setFrequency(float_t frequency) {
		Frequency = frequency;
	}
};

#endif /* SRC_BLINKINGLED_H_ */
