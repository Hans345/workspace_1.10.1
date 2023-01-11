/*
 * IKS01A3Motion.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "IKS01A3Motion.h"

uint8_t writeValueInRingBuffer(int32_t newValue, uint8_t WriteIndex, int32_t *StartPointer)
{
	WriteIndex++;

    if(WriteIndex>BUFFERSIZE-1){
    	WriteIndex=0;
    }

    StartPointer[WriteIndex]=newValue;
    return(WriteIndex);
}

int32_t avgRingBuffer(int32_t *ReadPointer){
    int32_t avg=0;

    for(int8_t i=0; i<BUFFERSIZE;i++)
    {
        avg+=*ReadPointer;
        ReadPointer++;
    }
    avg=avg/BUFFERSIZE;
    return(avg);
}

IKS01A3_Motion::IKS01A3_Motion() {
	// TODO Auto-generated constructor stub

}

IKS01A3_Motion::~IKS01A3_Motion() {
	// TODO Auto-generated destructor stub
}

void IKS01A3_Motion::init(uint32_t instance, uint32_t function) {
	IKS01A3_MOTION_SENSOR_Init(instance, function);
}

void IKS01A3_Motion::enable(uint32_t instance, uint32_t function) {
}

void IKS01A3_Motion::getValue(uint32_t instance, uint32_t function,
		int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis) {
}

void IKS01A3_Motion::setZero() {
}

void IKS01A3_Motion::updateValues(uint32_t instance, uint32_t function) {
	IKS01A3_MOTION_SENSOR_Axes_t CurrentAxisValues;

    IKS01A3_MOTION_SENSOR_GetAxes(instance, function, &CurrentAxisValues);

    WriteIndexRingBufferAxisX= writeValueInRingBuffer(CurrentAxisValues.x, WriteIndexRingBufferAxisX, &RingBufferAxisX[0]);
    WriteIndexRingBufferAxisY= writeValueInRingBuffer(CurrentAxisValues.y, WriteIndexRingBufferAxisY, &RingBufferAxisY[0]);
    WriteIndexRingBufferAxisZ= writeValueInRingBuffer(CurrentAxisValues.z, WriteIndexRingBufferAxisZ, &RingBufferAxisZ[0]);

    AxisValues.x = avgRingBuffer(&RingBufferAxisX[0]);
    AxisValues.y = avgRingBuffer(&RingBufferAxisY[0]);
    AxisValues.z = avgRingBuffer(&RingBufferAxisZ[0]);
}

void IKS01A3_Motion::getAVGValues(int32_t *XAxis, int32_t *YAxis,
		int32_t *ZAxis) {
}
