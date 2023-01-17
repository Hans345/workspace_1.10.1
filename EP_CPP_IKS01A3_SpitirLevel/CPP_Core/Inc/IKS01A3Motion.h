/*
 * IKS01A3Motion.h
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#ifndef INC_IKS01A3MOTION_H_
#define INC_IKS01A3MOTION_H_

//#define Pre-processor macro: STD_ARRAY (see Properties/Tool Settings/Preprocessor)
#ifdef STD_ARRAY
#include <array>
#include <algorithm>				//For std::rotate()
#define BUFFERSIZE 6
#else
#include <vector>
#include <iterator>
#define BUFFERSIZE 6				// >6 -> Valueproblems
#endif

#include <stdio.h>					//For printf()
#include <numeric>					//For std::accumulate()
#include "util_ring_allocator.h" 	//For util::ring_allocator<>
#include "iks01a3_motion_sensors.h"

class IKS01A3_Motion {
	private:
		IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
		IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;

	#ifdef STD_ARRAY
		std::array<int32_t,BUFFERSIZE> RingBufferAxisX={0,0,0,0,0,0};
		std::array<int32_t,BUFFERSIZE> RingBufferAxisY={0,0,0,0,0,0};
		std::array<int32_t,BUFFERSIZE> RingBufferAxisZ={0,0,0,0,0,0};
	#else
		std::vector<int32_t, util::ring_allocator<int32_t>>  RingBufferAxisX;
		std::vector<int32_t, util::ring_allocator<int32_t>>  RingBufferAxisY;
		std::vector<int32_t, util::ring_allocator<int32_t>>  RingBufferAxisZ;
	#endif
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
