/*
 * IKS01A3Motion.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "IKS01A3Motion.h"

IKS01A3_Motion::IKS01A3_Motion() {
    AxisOffsets.x=0;
    AxisValues.x=0;
    AxisOffsets.y=0;
    AxisValues.y=0;
    AxisOffsets.z=0;
    AxisValues.z=0;
}

IKS01A3_Motion::~IKS01A3_Motion() {
	// TODO Auto-generated destructor stub
}

void IKS01A3_Motion::init(uint32_t instance, uint32_t function) {
	IKS01A3_MOTION_SENSOR_Init(instance, function);
}

void IKS01A3_Motion::enable(uint32_t instance, uint32_t function) {
	IKS01A3_MOTION_SENSOR_Enable(instance, function);
}

void IKS01A3_Motion::getValue(uint32_t instance, uint32_t function,
		int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis) {
	IKS01A3_MOTION_SENSOR_GetAxes(instance, function, &AxisValues);
	*XAxis = AxisValues.x;
	*YAxis = AxisValues.y;
	*ZAxis = AxisValues.z;
}

void IKS01A3_Motion::setZero() {
    AxisOffsets.x=-AxisValues.x;
    AxisOffsets.y=-AxisValues.y;
    AxisOffsets.z=-AxisValues.z;
}

void IKS01A3_Motion::updateValues(uint32_t instance, uint32_t function) {
	IKS01A3_MOTION_SENSOR_Axes_t CurrentAxisValues;

    IKS01A3_MOTION_SENSOR_GetAxes(instance, function, &CurrentAxisValues);

    #ifdef STD_ARRAY
    	// Fill array Buffer's
        std::rotate(RingBufferAxisX.begin(),RingBufferAxisX.begin()+1,RingBufferAxisX.end());
        RingBufferAxisX[BUFFERSIZE-1]=CurrentAxisValues.x;

        std::rotate(RingBufferAxisY.begin(),RingBufferAxisY.begin()+1,RingBufferAxisY.end());
        RingBufferAxisY[BUFFERSIZE-1]=CurrentAxisValues.y;

        std::rotate(RingBufferAxisZ.begin(),RingBufferAxisZ.begin()+1,RingBufferAxisZ.end());
        RingBufferAxisZ[BUFFERSIZE-1]=CurrentAxisValues.z;

    #else
        std::basic_string<char,std::char_traits<char>,util::ring_allocator<char>> MyStringObj;
        // Fill vector Buffer's
        if(RingBufferAxisX.size()>BUFFERSIZE-1){RingBufferAxisX.erase(RingBufferAxisX.begin());}
        RingBufferAxisX.push_back(CurrentAxisValues.x);
        if(RingBufferAxisY.size()>BUFFERSIZE-1){RingBufferAxisY.erase(RingBufferAxisY.begin());}
        RingBufferAxisY.push_back(CurrentAxisValues.y);
		if(RingBufferAxisZ.size()>BUFFERSIZE-1){RingBufferAxisZ.erase(RingBufferAxisZ.begin());}
		RingBufferAxisZ.push_back(CurrentAxisValues.z);

    #endif

    // Create mean Value's
    AxisValues.x = std::accumulate(RingBufferAxisX.begin(), RingBufferAxisX.end(), 0LL) / RingBufferAxisX.size();
    AxisValues.y= std::accumulate(RingBufferAxisY.begin(), RingBufferAxisY.end(), 0LL) / RingBufferAxisY.size();
    AxisValues.z = std::accumulate(RingBufferAxisZ.begin(), RingBufferAxisZ.end(), 0LL) / RingBufferAxisZ.size();
}

void IKS01A3_Motion::getAVGValues(int32_t *XAxis, int32_t *YAxis,
		int32_t *ZAxis) {
    *XAxis=AxisValues.x+AxisOffsets.x;
    *YAxis=AxisValues.y+AxisOffsets.y;
    *ZAxis=AxisValues.z+AxisOffsets.z;
}
