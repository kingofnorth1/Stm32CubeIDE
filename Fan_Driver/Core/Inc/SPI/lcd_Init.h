/*
 * Lcd_Init.h
 *
 *  Created on: Aug 18, 2024
 *      Author: king
 */

#ifndef INC_LCD_INIT_H_
#define INC_LCD_INIT_H_

#include "stm32f1xx_hal.h"
#include "gpio.h"

#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
#define LCD_COLUMN_OFFSET 0

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 135
#define LCD_H 240

#else
#define LCD_W 240
#define LCD_H 135
#endif


#define LCD_SCLK_Clr() HAL_GPIO_WritePin(GPIOB,LCD_SCL_Pin,GPIO_PIN_SET)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(GPIOB,LCD_SCL_Pin,GPIO_PIN_RESET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(GPIOB,LCD_SDA_Pin,GPIO_PIN_SET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(GPIOB,LCD_SDA_Pin,GPIO_PIN_RESET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIOB,LCD_RST_Pin,GPIO_PIN_SET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(GPIOB,LCD_RST_Pin,GPIO_PIN_RESET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIOB,LCD_DC_Pin,GPIO_PIN_SET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(GPIOB,LCD_DC_Pin,GPIO_PIN_RESET)

#define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOA,LCD_CS_Pin,GPIO_PIN_SET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOA,LCD_CS_Pin,GPIO_PIN_RESET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOB,LCD_BL_Pin,GPIO_PIN_SET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOB,LCD_BL_Pin,GPIO_PIN_RESET)



void LCD_Writ_Bus(uint8_t dat);//模拟SPI时序
void LCD_WR_DATA8(uint8_t dat);//写入一个字节
void LCD_WR_DATA(uint16_t dat);//写入两个字节
void LCD_WR_REG(uint8_t dat);//写入一个指令
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//设置坐标函数
void LCD_clear(void);
void LCD_full(unsigned int color);
void LCD_Init(void);//LCD初始化
void LCD_Clear_Address(uint16_t startx,uint16_t starty,uint16_t endx,uint16_t endy);

#endif /* INC_LCD_INIT_H_ */
