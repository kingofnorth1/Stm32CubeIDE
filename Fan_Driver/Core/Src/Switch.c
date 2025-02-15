/*
 * Switch.c
 *
 *  Created on: Aug 17, 2024
 *      Author: king
 */
#include "Switch.h"

int16_t CCR2 = 0;
TIM_HandleTypeDef htim;

void Fan_Init(TIM_HandleTypeDef* htim2)
{
	htim = *htim2;
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_2);
}

void Fan_Fast(TIM_HandleTypeDef* htim2, uint16_t Fan_Pin)
{
	while (!HAL_GPIO_ReadPin(GPIOA, Fan_Pin))
	{
		HAL_Delay(50);
//		while (!HAL_GPIO_ReadPin(GPIOA, Fan_Pin));
		CCR2 = __HAL_TIM_GET_COMPARE(htim2, TIM_CHANNEL_2);
		CCR2 += 100;
		if (CCR2 <= 500)
		{

			__HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, CCR2);
		}
		HAL_Delay(50);
	}
}

void Fan_Slow(TIM_HandleTypeDef* htim2, uint16_t Fan_Pin)
{
	while (!HAL_GPIO_ReadPin(GPIOA, Fan_Pin))
	{
		HAL_Delay(50);
//		while (!HAL_GPIO_ReadPin(GPIOA, Fan_Pin));
		CCR2 = __HAL_TIM_GET_COMPARE(htim2, TIM_CHANNEL_2);
		CCR2 -= 100;
		if (CCR2 >= 0)
		{

			__HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, CCR2);
		}
		HAL_Delay(50);
	}
}
