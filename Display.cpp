#include "Arduino.h"
#include "Display.h"
//--------------------------------------------------------------------------------------------------------------
void Print_DBus(uint8_t num)
{
  digitalWrite(DB4,(num & 0x1) >> 0);
  digitalWrite(DB5,(num & 0x2) >> 1);
  digitalWrite(DB6,(num & 0x4) >> 2);
  digitalWrite(DB7,(num & 0x8) >> 3);
  //latching
  delayMicroseconds(500);
  digitalWrite(E,HIGH);
  delayMicroseconds(500);
  digitalWrite(E,LOW);
  delayMicroseconds(500);
}
//--------------------------------------------------------------------------------------------------------------
void Print_Data(uint8_t data)
{
  digitalWrite(RS, HIGH);
  //print MSB 4 bits
  Print_DBus((data & 0xF0) >> 4);
  //print LSB 4 bits
  Print_DBus(data & 0x0F);
}
//--------------------------------------------------------------------------------------------------------------
void Print_CMD(uint8_t cmd)
{
  digitalWrite(RS, LOW);
  //print MSB 4 bits
  Print_DBus((cmd & 0xF0) >> 4);
  //print LSB 4 bits
  Print_DBus(cmd & 0x0F);
}
//--------------------------------------------------------------------------------------------------------------
void LCD_Setup()
{
  // delay(50);

  digitalWrite(RS, LOW);

  //Sets to 4-bit operation. otherwise, next instructions will be wrong execute
  Print_DBus(0x3);
  delay(5);
  Print_DBus(0x3);
  delayMicroseconds(100);
  Print_DBus(0x3);
  delayMicroseconds(100);

  Print_DBus(0x2);
  delayMicroseconds(100);
  Print_CMD(0x28); //4 bit mode, 2-line display mode, 5x8 dots
  Print_CMD(0x0C); //turn on display (without cursor)
  Print_CMD(0x06); //set entry mode (in which direction the LCD will print characters)
  Print_CMD(0x01); //clear display
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
void Print_To_LCD(uint8_t* str)
{
  for(uint8_t i = 0; str[i] != '\0'; i++)
    Print_Data(str[i]);
}
//--------------------------------------------------------------------------------------------------------------
void Print_To_LCD(const char* str)
{
  for(uint8_t i = 0; str[i] != '\0'; i++)
    Print_Data(str[i]);
}
//--------------------------------------------------------------------------------------------------------------

void Print_To_LCD(int64_t num)
{
  int64_t temp = num;
  int64_t mod = 10;
  int64_t div = 1;
  while(temp != 0)
  {
    temp = (num % mod) / div;
    Print_Data(temp + '0');
    mod *= 10;
    div *= 10;
  }
}
//--------------------------------------------------------------------------------------------------------------

