/*
 * STM32H7Led.h
 *
 *  Created on: 11.01.2023
 *      Author: raphael.baumeler
 */

#ifndef STM32H7LED_H_
#define STM32H7LED_H_

#include "stm32f7xx_hal.h"

class STM32H7Led {
private:
	GPIO_TypeDef* Port;
	uint16_t Pin;
public:
	STM32H7Led();
	STM32H7Led(GPIO_TypeDef *Port, uint16_t Pin);
	virtual ~STM32H7Led();
	void toggleLED(void);
	void setLED(void);
	void unsetLED(void);
};

#endif /* STM32H7LED_H_ */
