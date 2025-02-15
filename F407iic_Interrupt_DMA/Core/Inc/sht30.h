/*
 * aht20.h
 *
 *  Created on: Jun 12, 2024
 *      Author: bzah
 */

#ifndef INC_SHT30_H_
#define INC_SHT30_H_

#include "i2c.h"

void SHT30_Init();

void SHT30_RepeatReadReg(float* temperture, float* huminess);

void SHT30_Measure();

void SHT30_Get();

void SHT30_Analysis(float* temperture, float* huminess);

#endif /* INC_SHT30_H_ */
