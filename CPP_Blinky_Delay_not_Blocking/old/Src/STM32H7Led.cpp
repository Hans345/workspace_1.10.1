/*
 * STM32H7Led.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#include "../../Core_CPP/Inc/STM32H7Led.h"

STM32H7Led::STM32H7Led(GPIO_TypeDef* aPort, uint16_t aPin)	:
Port(aPort), Pin(aPin)
{
}

STM32H7Led::~STM32H7Led() {
}

