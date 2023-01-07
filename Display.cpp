//--------------------------------------------------------------------------------------------------------------
#include "Display.h"
//--------------------------------------------------------------------------------------------------------------
void Print_DBus(uint8_t data)
{
  digitalWrite(DB7,data & 0x1);
  digitalWrite(DB6,data & 0x2);
  digitalWrite(DB5,data & 0x4);
  digitalWrite(DB4,data & 0x8);
}
//--------------------------------------------------------------------------------------------------------------
void LCD_Setup()
{
  delay(50);
  //set 8-bit mode
  Print_DBus(0xC);
  delayMicroseconds(50);
  //set 4-bit mode,N = 1, 5x8 dot
  Print_DBus(0x4);
  Print_DBus(0x1);
  delayMicroseconds(50);
  //set 4-bit mode,N = 1, 5x8 dot
  Print_DBus(0x4);
  Print_DBus(0x1);
  delayMicroseconds(50);
  //turn on display
  Print_DBus(0x0);
  Print_DBus(0xF);
  delayMicroseconds(50);
  //clear display
  Print_DBus(0x0);
  Print_DBus(0x1);
  delay(50);
  //Entry mode set
  Print_DBus(0x0);
  Print_DBus(0x7);
}
//--------------------------------------------------------------------------------------------------------------
