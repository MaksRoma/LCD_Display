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
  Print_DBus((data & 0xF0) >> 4);    //print MSB 4 bits
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
  Print_DBus(data & 0x0F);           //print LSB 4 bits
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
}
//--------------------------------------------------------------------------------------------------------------
void Print_CMD(uint8_t cmd)
{
  digitalWrite(RS, LOW);
  Print_DBus((cmd & 0xF0) >> 4);    //print MSB 4 bits
  //---latching----
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
  Print_DBus(cmd & 0x0F);           //print LSB 4 bits
  //---latching----
  delay(0.5);
  digitalWrite(E,HIGH);
  delay(0.5);
  digitalWrite(E,LOW);
  delay(0.5);
}
//--------------------------------------------------------------------------------------------------------------
void LCD_Setup()
{
  Print_CMD(0x28); //4 bit mode, 2-line display mode, 5x8 dots0
  delay(0.5);
  Print_CMD(0x0C); //turn on display (without cursor)
  delay(0.5);
  Print_CMD(0x06); //set entry mode (in which direction the LCD will print characters)
  delay(0.5);
  Print_CMD(0x01); //clear display
  delay(0.5);
}
//--------------------------------------------------------------------------------------------------------------

