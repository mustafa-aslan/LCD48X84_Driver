/**
  * @File    lcd48x84.h
  * @Author  Mustafa Aslan
  * @Date    9-7-2016
*/

#ifndef __NOKIA_5110_H
#define __NOKIA_5110_H

#include "stm32f10x.h"

/**
 __________________
| ________________ |        	NOKIA 5110
||                ||            1  RST   (Reset)
||   NOKIA 5110		||            2  CE    (Chip Sec)
||    48X84LCD		||            3  DC    (Data/Komut)
||  maelektronik  ||            4  DIN   (Data cikis)
||    blog.com    ||            5  CLK   (Clock hiz)
||________________||            6  3.3V  (Vcc)
|                  |            7  LIGHT (Arkaplan ekran aydinlatmasi)
|__________________|            8  GND   (Ground)
  | | | | | | | |
  1 2 3 4 5 6 7 8
*/

/**
	@Pinler
*/
#define LCD_GPIO GPIOA
#define RST_PIN  GPIO_Pin_0
#define CE_PIN	 GPIO_Pin_1
#define DC_PIN   GPIO_Pin_2
#define DIN_PIN  GPIO_Pin_3
#define CLK_PIN  GPIO_Pin_4


typedef struct{
	unsigned char Chip_Mode;    				
	unsigned char Addressing;  					
	unsigned char Display_Mode;					
	unsigned char Temperature_Control;   
	unsigned char Bias_System;
	unsigned char Set_Vop;
}LCD48x84_InitTypedef;

/**
	@defgroup ChipMode
*/
#define Chip_Active 		0x20 // Chip aktif
#define Power_Down_Mode 0x24 // Power down modu

/**
	@defgroup Adressing
*//*
	VERTICAL ADDRESSING             HORIZONTAL ADRESSING    
	0 	6		.		.		.								0		1		2		.		.		.
	1		7		.		.		.								84	85  86	.		.		.
	2		.		.		.		.								.		.		.		.		.		.
	3		. 	.		.		.								.		.		.		.		.		.
	4		.		.		.		.								.		.		.		.		.		.
	5		.		.		.		504							.		.		.		.		.		504
*/
#define Vertical_Adressing   0x22 // Dikey adresleme
#define Horizontal_Adressing 0x20 // Yatay adresleme

/**
	@defgroup DisplayMode
*/
#define Display_Blank           0x08 // Tum pikseller kapali.
#define Normal_Mode							0x0C // Beyaz fon uzerine siyah karakterler yazmak icin.
#define All_Display_Segment_On  0x09 // Tum pikseller acik.
#define Inverse_Video_Mode   		0x0D // Siyah fon uzerine beyaz karakterler yazmak icin.


/**
	@defgroup TemperatureControl
*/
#define Vlcd_Temp_Coef_0	0x04
#define Vlcd_Temp_Coef_1  0x05
#define Vlcd_Temp_Coef_2  0x06
#define Vlcd_Temp_Coef_3  0x07

/**
	@defgroup InstructionSet
*/
#define Use_Basic_Instruction_Set 		0x20
#define Use_Extended_Instruction_Set  0x21


/**
	@defgroup align
*/
#define ALIGN_LEFT   0x00
#define ALIGN_RIGHT  0x01
#define ALIGN_CENTER 0x02

/**

*/
#define PIXEL_SET   0x01
#define PIXEL_RESET 0x00


static void Basic_spi(unsigned char d);
void Send_Data(unsigned char d);
static void Send_Command(unsigned char c);
unsigned char align(unsigned char a, unsigned char n);
static void Write_Char(unsigned char c);
void Write_A_Pixel(unsigned char x, unsigned char y, unsigned char sr);
void Write_String(unsigned char x, unsigned char y, char s[]);
void Write_Number(unsigned char x, unsigned char y, unsigned short int n);
void Set_Address(unsigned char x, unsigned char y);
void Clear_Display(void);
void LCD48x84_Init(LCD48x84_InitTypedef *LCD48x84_InitStruct);




#endif /* __NOKIA_5110_H */

