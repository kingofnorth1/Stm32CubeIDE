/*
 * MAX30102.H
 *
 *  Created on: Jun 25, 2024
 *      Author: king
 */

#ifndef INC_MAX30102_H_
#define INC_MAX30102_H_

#include "i2c.h"
#include "stdint.h"
#include "string.h"
#include "stdio.h"

uint8_t MAX_State(void);
uint8_t MAX_Read_Byte(uint8_t reg);
void MAX_Write_Byte(uint8_t reg, uint8_t value);
void MAX_Init(void);

#endif /* INC_MAX30102_H_ */
