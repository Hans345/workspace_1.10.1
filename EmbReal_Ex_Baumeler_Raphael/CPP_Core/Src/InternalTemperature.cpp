/*
 * InternalTemperature.cpp
 *
 *  Created on: Feb 7, 2023
 *      Author: raphael.baumeler
 */
// My Code starts here
#include "InternalTemperature.h"

InternalTemperature::InternalTemperature() {
	// TODO Auto-generated constructor stub

}

InternalTemperature::~InternalTemperature() {
	// TODO Auto-generated destructor stub
}

float InternalTemperature::getMin() {
	return min;
}

float InternalTemperature::getAvg() {
    return avg;
}

float InternalTemperature::getMax() {
    return max;
}

void InternalTemperature::aquireNStoreTemperature() {
	float value = ADC_ReadTemperature();
    if(MeasValues.size()>BUFFERSIZE-1){MeasValues.erase(MeasValues.begin());}
    MeasValues.push_back(value);
    currValue = value;
}

void InternalTemperature::calcMinMaxAvg() {
	//Min
    if(currValue<prevValue){
    	min = currValue;
    	prevValue = currValue;
    }
	//Max
    if(currValue>prevValue){
        	max = currValue;
        	prevValue = currValue;
    }
	//Avg
	avg = std::accumulate(MeasValues.begin(), MeasValues.end(), 0LL) / MeasValues.size();
}
// My Code ends here