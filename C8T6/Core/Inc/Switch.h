/*
 * Switch.h
 *
 *  Created on: Aug 17, 2024
 *      Author: king
 */

#ifndef INC_SWITCH_H_
#define INC_SWITCH_H_

#include "stm32f1xx_hal.h"


void Fan_Init(TIM_HandleTypeDef* htim2);
void Fan_Fast(TIM_HandleTypeDef* htim2, uint16_t Fan_Pin);
void Fan_Slow(TIM_HandleTypeDef* htim2, uint16_t Fan_Pin);

#endif /* INC_SWITCH_H_ */
