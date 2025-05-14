/*
 * LCD.h
 *
 * Created: 2/3/2025 12:09:26 PM
 *  Author: yaraa
 */ 


#ifndef LCD_H_
#define LCD_H_

void Init_LCD();
void WriteData(u16);
void WriteCommand(u16);
void GotoXY(u8 x, u8 y);
void Goto_CGRAM(u8 BlockNumber);
void StoreSpecialChar(u8 BlockNumber ,u8* pattern);
void DisplaySpecialChar(u8 *pattern , u8 BlockNum , u8 x , u8 y);
void WriteString(char * str);
void WriteNumber(u16 num);



#endif /* LCD_H_ */