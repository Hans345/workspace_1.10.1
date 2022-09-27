/*
 * NoneBlockSystemTickDelay.h
 *
 *  Created on: Sep 27, 2022
 *      Author: raphael.baumeler
 */

#ifndef SRC_NONEBLOCKSYSTEMTICKDELAY_H_
#define SRC_NONEBLOCKSYSTEMTICKDELAY_H_

#include "BlinkingLed.h"

class NoneBlockSystemTickDelay: public BlinkingLed {
protected:
	DelayNoneBlocking_wait uint32_t = 0; 		// Intervall in ms
	DelayNoneBlocking_tickstart uint32_t = 0; 	// last_time
public:
	NoneBlockSystemTickDelay();
	virtual ~NoneBlockSystemTickDelay();

	void DelayNonBlocking_Init(uint32_t Delay) {
		DelayNoneBlocking_tickstart = HAL_GetTick();
		wait = Delay;
	}

	uint8_t DelayNonBlocking_CheckExpiration() {
		// TODO
		// 1: Toggle LED!
		// 0: Don't Toggle LED!
		if(HAL_GetTick() - DelayNoneBlocking_wait > DelayNoneBlocking_tickstart)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

#endif /* SRC_NONEBLOCKSYSTEMTICKDELAY_H_ */
