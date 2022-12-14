/*
 * IKS01A3Motion.h
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#ifndef INC_IKS01A3MOTION_H_
#define INC_IKS01A3MOTION_H_

#include <array>
#include <stdio.h>		//For printf()
#include <algorithm>	//For std::rotate()
#include <numeric>		//For std::accumulate()
#include "iks01a3_motion_sensors.h"

#define BUFFERSIZE 6

class IKS01A3_Motion {
	private:
		IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
		IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;
		std::array<int32_t, BUFFERSIZE> RingBufferAxisX={0,0,0,0,0,0};
		std::array<int32_t, BUFFERSIZE> RingBufferAxisY={0,0,0,0,0,0};
		std::array<int32_t, BUFFERSIZE> RingBufferAxisZ={0,0,0,0,0,0};
	public:
		IKS01A3_Motion();
		virtual ~IKS01A3_Motion();
		void init(uint32_t instance, uint32_t function);
		void enable(uint32_t instance, uint32_t function);
		void getValue(uint32_t instance, uint32_t function, int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);
		void setZero();
		void updateValues(uint32_t instance, uint32_t function);
		void getAVGValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);
};

#endif /* INC_IKS01A3MOTION_H_ */
