/*
 * AccSensor.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "AccSensor.h"

AccSensor::AccSensor() {
	// TODO Auto-generated constructor stub

}

AccSensor::~AccSensor() {
	// TODO Auto-generated destructor stub
}

void AccSensor::initSensor() {
	AccSensor::Acc.init(INSTANCE, FUNCTION_ACC);
}

void AccSensor::updateValues() {
	AccSensor::Acc.updateValues(INSTANCE, FUNCTION_ACC);
}
