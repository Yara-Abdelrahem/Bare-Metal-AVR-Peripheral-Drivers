/*
 * LCD.c
 *
 * Created: 2/3/2025 12:09:13 PM
 *  Author: yaraa
 */ 
#define NULL ((void*)0)
#include "../../../STD_TYPES.h"
#include "../../../BIT_MATH.h"
#include "LCD.h"
#include "LCDCfg.h"
#include "../../../MCAL/MPORT/MPORT.h"
#include "../../../MCAL/MDIO/MDIO.h"
#include <util/delay.h>

#define FunctionSet_8bit_2line_7dots	((u8)0b00111000)
#define FunctionSet_4bit_2line_7dots	((u8)0b00101000)
#define DisplayOnOff					((u8)0b00001111)
#define DisplayClear					((u8)0b00000001)
#define EntryModeSet					((u8)0b00000110)
typedef enum{
	LCD_enu_OK,
	LCD_enu_NOK
}LCD_enuErrorStatus_t;

extern LCDCFG_t LCD;

void Init_LCD(){
	// Set the pins as OUTPUT
	//MPORT_enuSetPinDirection(LCD.VEE, MPORT_OUTPUT);
	MPORT_enuSetPinDirection(LCD.RS, MPORT_OUTPUT);
	MPORT_enuSetPinDirection(LCD.RW , MPORT_OUTPUT);
	MPORT_enuSetPinDirection(LCD.E , MPORT_OUTPUT);
	for (int i = 0 ; i<LCD_NUM_PINS ; i++)
	{
		MPORT_enuSetPinDirection(LCD.D_arr[i],MPORT_OUTPUT);
	}
	_delay_ms(30);
	WriteCommand(FunctionSet_8bit_2line_7dots);
	_delay_ms(1);
	WriteCommand(DisplayOnOff);
	_delay_ms(1);
	WriteCommand(DisplayClear);
	_delay_ms(2);
	WriteCommand(EntryModeSet);	
}
void WriteData(u16  copyData){
	//rw-> low
	//rs -> high
	// copydata
	//enable
	u8 PORTNUM_RS = (LCD.RS & 0xF0)>>4;
	u8 PINNUM_RS = LCD.RS& 0x0F;
	u8 PORTNUM_RW = (LCD.RW & 0xF0)>>4;
	u8 PINNUM_RW = LCD.RW& 0x0F;
	MDIO_enuSetPinValue(PORTNUM_RW ,PINNUM_RW,MDIO_LOW);
	MDIO_enuSetPinValue(PORTNUM_RS , PINNUM_RS,MDIO_HIGH);
	for (int i = 0 ; i<LCD_NUM_PINS ; i++)
	{
		u8 pinState = GET_BIT(copyData, i);
		u8 PORTNUM = (LCD.D_arr[i] & 0xF0)>>4;
		u8 PINNUM = LCD.D_arr[i]& 0x0F;
		MDIO_enuSetPinValue(PORTNUM , PINNUM,pinState);
	}
	u8 PORTNUM_E = (LCD.E & 0xF0) >> 4;
	u8 PINNUM_E = LCD.E & 0x0F;

	MDIO_enuSetPinValue(PORTNUM_E, PINNUM_E, MDIO_HIGH);
	_delay_us(1); // Small delay for LCD
	MDIO_enuSetPinValue(PORTNUM_E, PINNUM_E, MDIO_LOW);

	
}
void WriteCommand(u16 copyCommand){
		//rw-> low
		//rs -> low
		// copydata
		//enable
	u8 PORTNUM_RS = (LCD.RS & 0xF0)>>4;
	u8 PINNUM_RS = LCD.RS& 0x0F;
	u8 PORTNUM_RW = (LCD.RW & 0xF0)>>4;
	u8 PINNUM_RW = LCD.RW& 0x0F;
	MDIO_enuSetPinValue(PORTNUM_RW ,PINNUM_RW,MDIO_LOW);
	MDIO_enuSetPinValue(PORTNUM_RS , PINNUM_RS,MDIO_LOW);
	for (int i = 0 ; i<LCD_NUM_PINS ; i++)
	{
		u8 pinState = GET_BIT(copyCommand, i);
		u8 PORTNUM = (LCD.D_arr[i] & 0xF0)>>4;
		u8 PINNUM = LCD.D_arr[i]& 0x0F;
		MDIO_enuSetPinValue(PORTNUM , PINNUM,pinState);
	}
	u8 PORTNUM_E = (LCD.E & 0xF0) >> 4;
	u8 PINNUM_E = LCD.E & 0x0F;

	MDIO_enuSetPinValue(PORTNUM_E, PINNUM_E, MDIO_HIGH);
	_delay_us(1); // Small delay for LCD
	MDIO_enuSetPinValue(PORTNUM_E, PINNUM_E, MDIO_LOW);

}
void GotoXY(u8 x, u8 y){
	u8 location =0;
	if (x==FirstLine)
	{
		location= y;
	}else if (x==SecondLine)
	{
		location =y+0x40;
	}
	WriteCommand(128+location);
}

void Goto_CGRAM(u8 BlockNumber){
	u8 location = BlockNumber*8;
	WriteCommand(location+64);
}
void StoreSpecialChar(u8 BlockNumber ,u8* pattern){
	Goto_CGRAM(BlockNumber);
	for (int i=0; i<LCD_NUM_PINS;i++)
	{
		WriteData(pattern[i]);
	}
}
void DisplaySpecialChar(u8 *pattern , u8 BlockNum , u8 x , u8 y){
	if (BlockNum >=0 && BlockNum<8)
	{
		StoreSpecialChar(BlockNum , pattern);
		GotoXY(x,y);
		WriteData(BlockNum); 
	}else if (BlockNum >= 8 && BlockNum<255)
	{
		GotoXY(x,y);
		WriteData(BlockNum);
	}
}

void WriteString(char * str){
	int i=0;
	 while (str[i] != '\0')
	{
		WriteData(str[i]);
		i++;
	}
}
void WriteNumber(u16 num){
	// u8 = > 3 digit
	// u16 => 5 digit
	u8 arr_num[5];
	int i = 0;
	if (num == 0)
	{
		WriteData('0');
		return;
	}
	while(num != 0){
		arr_num[i]= (num%10)+'0';
		num /=10;
		i++;
	}
	for (int j = i-1 ; j>=0;j--)
	{
		WriteData(arr_num[j]);
	}
}
