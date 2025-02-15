/*
 * Lcd_Init.c
 *
 *  Created on: Aug 18, 2024
 *      Author: king
 */

#include "SPI/lcd_Init.h"

//LCD写入函数
void LCD_Writ_Bus(uint8_t dat)
{
	uint8_t i;
	for (i=0;i<8;i++)
	{
		LCD_SCLK_Set();
		if (dat&0x80){
			LCD_MOSI_Clr();
		}else {
			LCD_MOSI_Set();
		}
		LCD_SCLK_Clr();
		dat<<=1;
	}
	LCD_SCLK_Set();
}

//LCD写入8位数据
void LCD_WR_DATA8(uint8_t dat)
{
	LCD_DC_Clr();
	LCD_CS_Set();
	LCD_Writ_Bus(dat);
	LCD_CS_Clr();
}

//LCD写入16位数据
void LCD_WR_DATA(uint16_t dat)
{
	LCD_DC_Clr();
	LCD_CS_Set();
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat&0xFF);
	LCD_CS_Clr();
}

//LCD写入命令
void LCD_WR_REG(uint8_t dat)
{
	LCD_DC_Set();
	LCD_CS_Set();
	LCD_Writ_Bus(dat);
	LCD_CS_Clr();
}

//设置起始和结束地址
//入口数据：x1,x2 设置列的起始和结束地址
//         y1,y2 设置行的起始和结束地址
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+52);
		LCD_WR_DATA(x2+52);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+40);
		LCD_WR_DATA(y2+40);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+53);
		LCD_WR_DATA(x2+53);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+40);
		LCD_WR_DATA(y2+40);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+40);
		LCD_WR_DATA(x2+40);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+53);
		LCD_WR_DATA(y2+53);
		LCD_WR_REG(0x2c);//储存器写
	}
	else
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+40);
		LCD_WR_DATA(x2+40);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+52);
		LCD_WR_DATA(y2+52);
		LCD_WR_REG(0x2c);//储存器写
	}
}

void LCD_clear(void)
  {
    unsigned int ROW,column;
  LCD_WR_REG(0x2a);     //Column address set
  LCD_WR_DATA8(0x00);    //start column
  LCD_WR_DATA8(0x34);
//  LCD_WR_DATA8(0x28);
  LCD_WR_DATA8(0x00);    //end column
  LCD_WR_DATA8(0xBA);
//  LCD_WR_DATA8(0x17);

  LCD_WR_REG(0x2b);     //Row address set
  LCD_WR_DATA8(0x00);    //start row
  LCD_WR_DATA8(0x28);
//  LCD_WR_DATA8(0x34);
  LCD_WR_DATA8(0x01);    //end row
  LCD_WR_DATA8(0x17);
//  LCD_WR_DATA8(0xBA);
    LCD_WR_REG(0x2C);     //Memory write
    for(ROW=0;ROW<LCD_H;ROW++)             //ROW loop
      {
          for(column=0;column<LCD_W;column++)  //column loop
            {
				LCD_WR_DATA8(0x00);
				LCD_WR_DATA8(0x00);
            }
      }
  }


void LCD_full(unsigned int color)
  {
	unsigned int ROW,column;
	LCD_WR_REG(0x2a);     //Column address set
	LCD_WR_DATA8(0x00);    //start column
	LCD_WR_DATA8(0x34);
	LCD_WR_DATA8(0x00);    //end column
	LCD_WR_DATA8(0xBA);

	LCD_WR_REG(0x2b);     //Row address set
	LCD_WR_DATA8(0x00);    //start row
	LCD_WR_DATA8(0x28);
	LCD_WR_DATA8(0x01);    //end row
	LCD_WR_DATA8(0x17);
	LCD_WR_REG(0x2C);     //Memory write
	for(ROW=0;ROW<LCD_H;ROW++)             //ROW loop
	{
		for(column=0;column<LCD_W ;column++) //column loop
		{
			LCD_WR_DATA8(color>>8);
			LCD_WR_DATA8(color);
		}
	}
  }


//LCD初始化函数
void LCD_Init(void)
{
		LCD_SCLK_Clr();
		LCD_RES_Set();//复位
		HAL_Delay(100);
		LCD_RES_Clr();
		HAL_Delay(100);

		LCD_BLK_Set();//打开背光
		HAL_Delay(100);

		LCD_WR_REG(0x11);
		HAL_Delay(120);
		//-----------------------ST7789V Frame rate setting-----------------//
		//************************************************
		LCD_WR_REG(0x3A);        //65k mode
		LCD_WR_DATA8(0x05);
		LCD_WR_REG(0xC5); 		//VCOM
		LCD_WR_DATA8(0x1A);
		LCD_WR_REG(0x36);
		if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
		else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
		else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
		else LCD_WR_DATA8(0xA0);

		//-------------ST7789V Frame rate setting-----------//
		LCD_WR_REG(0xb2);		//Porch Setting
		LCD_WR_DATA8(0x05);
		LCD_WR_DATA8(0x05);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x33);
		LCD_WR_DATA8(0x33);

		LCD_WR_REG(0xb7);			//Gate Control
		LCD_WR_DATA8(0x05);			//12.2v   -10.43v
		//--------------ST7789V Power setting---------------//
		LCD_WR_REG(0xBB);//VCOM
		LCD_WR_DATA8(0x3F);

		LCD_WR_REG(0xC0); //Power control
		LCD_WR_DATA8(0x2c);

		LCD_WR_REG(0xC2);		//VDV and VRH Command Enable
		LCD_WR_DATA8(0x01);

		LCD_WR_REG(0xC3);			//VRH Set
		LCD_WR_DATA8(0x0F);		//4.3+( vcom+vcom offset+vdv)

		LCD_WR_REG(0xC4);			//VDV Set
		LCD_WR_DATA8(0x20);				//0v

		LCD_WR_REG(0xC6);				//Frame Rate Control in Normal Mode
		LCD_WR_DATA8(0X01);			//111Hz

		LCD_WR_REG(0xd0);				//Power Control 1
		LCD_WR_DATA8(0xa4);
		LCD_WR_DATA8(0xa1);

		LCD_WR_REG(0xE8);				//Power Control 1
		LCD_WR_DATA8(0x03);

		LCD_WR_REG(0xE9);				//Equalize time control
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x08);
		//---------------ST7789V gamma setting-------------//
		LCD_WR_REG(0xE0); //Set Gamma
		LCD_WR_DATA8(0xD0);
		LCD_WR_DATA8(0x05);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x08);
		LCD_WR_DATA8(0x14);
		LCD_WR_DATA8(0x28);
		LCD_WR_DATA8(0x33);
		LCD_WR_DATA8(0x3F);
		LCD_WR_DATA8(0x07);
		LCD_WR_DATA8(0x13);
		LCD_WR_DATA8(0x14);
		LCD_WR_DATA8(0x28);
		LCD_WR_DATA8(0x30);

		LCD_WR_REG(0XE1); //Set Gamma
		LCD_WR_DATA8(0xD0);
		LCD_WR_DATA8(0x05);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x08);
		LCD_WR_DATA8(0x03);
		LCD_WR_DATA8(0x24);
		LCD_WR_DATA8(0x32);
		LCD_WR_DATA8(0x32);
		LCD_WR_DATA8(0x3B);
		LCD_WR_DATA8(0x14);
		LCD_WR_DATA8(0x13);
		LCD_WR_DATA8(0x28);
		LCD_WR_DATA8(0x2F);

		LCD_WR_REG(0x21); 		//反显

		LCD_WR_REG(0x29);         //开启显示
}

void LCD_Clear_Address(uint16_t startx,uint16_t starty,uint16_t endx,uint16_t endy)
  {
    unsigned int ROW,column;
  LCD_WR_REG(0x2a);     //Column address set
  LCD_WR_DATA8(0x00);    //start column
  LCD_WR_DATA(startx);
  LCD_WR_DATA8(0x01);    //end column
  LCD_WR_DATA(endx);

  LCD_WR_REG(0x2b);     //Row address set
  LCD_WR_DATA8(0x00);    //start row
  LCD_WR_DATA(starty);
  LCD_WR_DATA8(0x00);    //end row
  LCD_WR_DATA(endy);
    LCD_WR_REG(0x2C);     //Memory write
    for(ROW=0;ROW<LCD_H;ROW++)             //ROW loop
      {
          for(column=0;column<LCD_W;column++)  //column loop
            {
				LCD_WR_DATA8(0x00);
				LCD_WR_DATA8(0x00);
            }
      }
  }
