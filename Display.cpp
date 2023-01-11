#include "Arduino.h"
//--------------------------------------------------------------------------------------------------------------
#include "Display.h"
//--------------------------------------------------------------------------------------------------------------
void Print_DBus(uint8_t num)
{
  digitalWrite(DB4,(num & 0x1) >> 0);
  digitalWrite(DB5,(num & 0x2) >> 1);
  digitalWrite(DB6,(num & 0x4) >> 2);
  digitalWrite(DB7,(num & 0x8) >> 3);
}
//--------------------------------------------------------------------------------------------------------------
void Print_Data(uint8_t data)
{
  digitalWrite(RS, HIGH);
  //print MSB 4 bits
  Print_DBus((data & 0xF0) >> 4);
  delay(2);
  digitalWrite(E,HIGH);
  delay(2);
  digitalWrite(E,LOW);
  delay(2);
  //print LSB 4 bits
  Print_DBus(data & 0x0F);
  delay(2);
  digitalWrite(E,HIGH);
  delay(2);
  digitalWrite(E,LOW);
  delay(2);
}
//--------------------------------------------------------------------------------------------------------------
void Print_CMD(uint8_t cmd)
{
  digitalWrite(RS, LOW);
  //print MSB 4 bits
  Print_DBus((cmd & 0xF0) >> 4);
  //---latching----
  delay(2);
  digitalWrite(E,HIGH);
  delay(2);
  digitalWrite(E,LOW);
  delay(2);
  //print LSB 4 bits
  Print_DBus(cmd & 0x0F);
  //---latching----
  delay(2);
  digitalWrite(E,HIGH);
  delay(2);
  digitalWrite(E,LOW);
  delay(2);
}
//--------------------------------------------------------------------------------------------------------------
void LCD_Setup()
{
  delay(50);
  Print_CMD(0x2);
  delay(50);
  Print_CMD(0x2);
  delay(50);
  Print_CMD(0x28); //4 bit mode, 2-line display mode, 5x8 dots0
  delay(50);
  Print_CMD(0x0C); //turn on display (without cursor)
  delay(50);
  Print_CMD(0x06); //set entry mode (in which direction the LCD will print characters)
  delay(50);
  Print_CMD(0x01); //clear display
  delay(50);
  
}
//--------------------------------------------------------------------------------------------------------------
void Set_CGRAM(uint8_t* Char_Arr)
{
  Print_Data(Char_Arr[0]);
  Print_Data(Char_Arr[1]);
  Print_Data(Char_Arr[2]);
  Print_Data(Char_Arr[3]);
  Print_Data(Char_Arr[4]);
  Print_Data(Char_Arr[5]);
  Print_Data(Char_Arr[6]);
  Print_Data(Char_Arr[7]);
}
//--------------------------------------------------------------------------------------------------------------

