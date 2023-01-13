#include <stdint.h>
#ifndef Display_h
#define Display_h
//--------------------------------------------------------------------------------------------------------------
#include "Arduino.h"
//--------------------------------------------------------------------------------------------------------------
//Port D
#define DB7   2
#define DB6   3
#define DB5   4
#define DB4   5
//Port B
#define E     11
#define RS    12
//--------------------------------------------------------------------------------------------------------------
//print data to screen
void Print_Data(uint8_t data);
//print command to lcd
void Print_CMD(uint8_t cmd);
//Setup Display
void LCD_Setup();
//set custom character to CGRAM
void Set_CGRAM(uint8_t* Char_Arr);
//print string to lcd
void Print_To_LCD(uint8_t* str);
void Print_To_LCD(const char* str);
//same function for print integer numbers to lcd
void Print_To_LCD(int64_t num);
//--------------------------------------------------------------------------------------------------------------
#endif
