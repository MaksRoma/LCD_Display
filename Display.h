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
//Function for print data to screen
void Print_Data(uint8_t data);
//Function for print command to lcd
void Print_CMD(uint8_t data);
//Setup Display
void LCD_Setup();
//--------------------------------------------------------------------------------------------------------------
#endif
