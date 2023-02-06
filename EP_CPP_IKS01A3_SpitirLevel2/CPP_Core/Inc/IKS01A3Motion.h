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
#define BUFFERSIZE 6
#else
#include <map>
#include <vector>
#include <iterator>
#define BUFFERSIZE 6				// >6 -> Valueproblems
#endif

#include <stdio.h>					//For printf()
#include <numeric>					//For std::accumulate()
#include "util_ring_allocator.h" 	//For util::ring_allocator<>
#include "iks01a3_motion_sensors.h"
#include <algorithm>				//For std::rotate() & std::minmax_element
#include <functional>
#include <cstring>

//for container map when searching the key
struct StrCompare : public std::binary_function<const char*, const char*, bool> {
public:
    bool operator() (const char* str1, const char* str2) const
    { return std::strcmp(str1, str2) < 0; }
};

//alternatively with ring allocator, has some issues with allocation
//typedef std::map<const char*, int32_t, StrCompare, util::ring_allocator< std::pair<const char*, int32_t> > > StatAxis_t;

//using a map with char (C-String) as key to reduce complexity, therefore a compare operator is needed see: StrCompare
typedef std::map<const char*, int32_t, StrCompare> StatAxis_t;

class IKS01A3_Motion {
	private:
		IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
		IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;

	#ifdef STD_ARRAY
		std::array<int32_t,BUFFERSIZE> RingBufferAxisX={0,0,0,0,0,0};
		std::array<int32_t,BUFFERSIZE> RingBufferAxisY={0,0,0,0,0,0};
		std::array<int32_t,BUFFERSIZE> RingBufferAxisZ={0,0,0,0,0,0};
	#else
	    std::vector<int32_t , util::ring_allocator<int32_t>>  RingBufferAxisX;
	    std::vector<int32_t , util::ring_allocator<int32_t>>  RingBufferAxisY;
	    std::vector<int32_t , util::ring_allocator<int32_t>>  RingBufferAxisZ;
	    StatAxis_t StatsAxisX;
	    StatAxis_t StatsAxisY;
	    StatAxis_t StatsAxisZ;
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
	    void getMinValues(int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
	    void getMaxValues(int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
};

#endif /* INC_IKS01A3MOTION_H_ */