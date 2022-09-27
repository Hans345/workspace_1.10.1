/*
 * STM32H7Led.h
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#ifndef SRC_STM32H7LED_H_
#define SRC_STM32H7LED_H_

#include "BlinkingLed.h"

class STM32H7Led: public BlinkingLed {
private:
	GPIO_TypeDef* Port;
	uint16_t Pin;
public:
	STM32H7Led();
	virtual ~STM32H7Led();

	void toggleLED(void) {
		HAL_GPIO_TogglePin(Port, Pin);
	}
};

#endif /* SRC_STM32H7LED_H_ */
