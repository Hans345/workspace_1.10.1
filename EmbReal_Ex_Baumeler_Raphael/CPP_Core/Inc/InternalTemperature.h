/*
 * InternalTemperature.h
 *
 *  Created on: Feb 7, 2023
 *      Author: raphael.baumeler
 */
// My Code starts here
#ifndef INTERNALTEMPERATURE_H_
#define INTERNALTEMPERATURE_H_

#define BUFFERSIZE 20

#include <vector>
#include <numeric>					//For std::accumulate()
#include <iostream>					//For std::cout
#include "util_ring_allocator.h" 	//For util::ring_allocator<>
#include "main.h"


class InternalTemperature {
private:
	std::vector<float , util::ring_allocator<float>>  MeasValues;
	float min;
	float max;
	float avg;
	float currValue;
	float prevValue;

public:
	InternalTemperature();
	virtual ~InternalTemperature();
	float getAvg();
	float getMin();
	float getMax();
	void aquireNStoreTemperature();
	void calcMinMaxAvg();
};

#endif /* INTERNALTEMPERATURE_H_ */
// My Code ends here
