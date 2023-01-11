/*
 * AccGyroSensor.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

#include "AccGyroSensor.h"

AccGyroSensor::AccGyroSensor() {
	// TODO Auto-generated constructor stub

}

AccGyroSensor::~AccGyroSensor() {
	// TODO Auto-generated destructor stub
}

void AccGyroSensor::initSensor() {
	AccGyroSensor::Gyro.init(INSTANCE, FUNCTION_INIT_ACC_GYRO);
}

void AccGyroSensor::updateValues() {
	AccGyroSensor::Gyro.updateValues(INSTANCE, FUNCTION_GYRO);
	AccGyroSensor::Acc.updateValues(INSTANCE, FUNCTION_ACC);
}

void AccGyroSensor::setZero() {
	AccGyroSensor::Acc.setZero();
	AccGyroSensor::Gyro.setZero();
}
