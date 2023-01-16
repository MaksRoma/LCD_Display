#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "Arduino.h"
/*--------------------------------------------------------------------------------------------------------------*/
#ifndef Display_h
#define Display_h
/*--------------------------------------------------------------------------------------------------------------*/
//Port D
#define DB7   2
#define DB6   3
#define DB5   4
#define DB4   5
//Port B
#define E     11
#define RS    12
/*--------------------------------------------------------------------------------------------------------------*/
#define DEC 10
#define HEX 16
/*--------------------------------------------------------------------------------------------------------------*/
//print data to screen
void Print_Data(uint8_t data);
//print command to lcd
void Print_CMD(uint8_t cmd);
//Setup Display
void LCD_Setup();
//set custom character to CGRAM
void Set_CGRAM(uint8_t* Char_Arr);
//print some data (string,number etc.) to lcd
void Print_To_LCD(char* str);
void Print_To_LCD(const char* str);
void Print_To_LCD(int32_t num, uint8_t base = DEC);
/*--------------------------------------------------------------------------------------------------------------*/
#endif
