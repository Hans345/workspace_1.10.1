/*
 * STM32H7Led.cpp
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#include "STM32H7Led.h"

STM32H7Led::STM32H7Led() {
	// TODO Auto-generated constructor stub
	STM32H7Led::Port = GPIOB;
	STM32H7Led::Pin = GPIO_Pin_7;
}

STM32H7Led::~STM32H7Led() {
	// TODO Auto-generated destructor stub
}

