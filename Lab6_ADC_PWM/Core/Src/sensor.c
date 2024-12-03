/*
 * sensor.c
 *
 *  Created on: Sep 26, 2023
 *      Author: HaHuyen
 */
#include "sensor.h"

uint16_t adc_receive[5];

void sensor_init(){
	HAL_ADC_Start_DMA(&hadc1, (uint16_t*)adc_receive, 5);
}

void sensor_Read(){
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_receive, 5);
}

uint16_t sensor_GetLight(){
	return adc_receive[2];
}

uint16_t sensor_GetPotentiometer(){
	return adc_receive[3];
}

float sensor_GetVoltage(){
	return ((float)adc_receive[0]*3.3*12)/(4095*1.565);
}

float sensor_GetCurrent(){
	return (((float)adc_receive[1]*3.3*1000)/(4095*0.647)-2.5)*5/2.5;
}

float sensor_GetTemperature(){
	return ((float)adc_receive[4]*330)/(4095);
}

float sensor_GetPowerConsumption(){
	return (((float)adc_receive[0]*3.3*12)/(4095*1.565)) * ((((float)adc_receive[1]*3.3*1000)/(4095*0.647)-2.5)*5/2.5);
}

float sensor_GetHumidity(){
	if ((float)adc_receive[3] < 195) return 0;
	else if ((float)adc_receive[3] > 3780) return 100;
	else {
		return ((float)adc_receive[3] - 180) * 100 / (3780 - 195);
	}
}

char* sensor_GetLightIntensity(){
	if (adc_receive[2] > 1800) return "Weak";
	else return "Strong";
}
