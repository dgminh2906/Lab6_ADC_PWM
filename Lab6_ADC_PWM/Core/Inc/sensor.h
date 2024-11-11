/*
 * sensor.h
 *
 *  Created on: Nov 11, 2024
 *      Author: LENOVO
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "adc.h"

void sensor_init();

void sensor_Read();

uint16_t sensor_GetLight();

uint16_t sensor_GetPotentiometer();

float sensor_GetVoltage();

float sensor_GetCurrent();

float sensor_GetTemperature();

float sensor_GetPowerConsumption();

float sensor_GetHumidity();

char* sensor_GetLightIntensity();


#endif /* INC_SENSOR_H_ */
