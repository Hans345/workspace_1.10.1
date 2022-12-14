/*
 * NoneBlockSystemTickDelay.h
 *
 *  Created on: Sep 29, 2022
 *      Author: raphael.baumeler
 */

#ifndef NONEBLOCKSYSTEMTICKDELAY_H_
#define NONEBLOCKSYSTEMTICKDELAY_H_

#include "stm32f7xx_hal.h" //For HAL_GetTick()
#include <stdint.h>

namespace myHal{
class NoneBlockSystemTickDelay {
private:
	uint32_t DelayNoneBlocking_wait; 		// Intervall in ms
	uint32_t DelayNoneBlocking_tickstart; 	// last_time
public:
	NoneBlockSystemTickDelay();
	virtual ~NoneBlockSystemTickDelay();

	void DelayNonBlocking_Init(uint32_t Delay) {
		DelayNoneBlocking_wait = Delay;
		DelayNoneBlocking_tickstart = HAL_GetTick();
	}

	uint8_t DelayNonBlocking_CheckExpiration() {
		// 1: Toggle LED!
		// 0: Don't Toggle LED!
		if(HAL_GetTick() - DelayNoneBlocking_wait > DelayNoneBlocking_tickstart)
		{
			DelayNoneBlocking_tickstart = HAL_GetTick();
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
}

#endif /* NONEBLOCKSYSTEMTICKDELAY_H_ */
