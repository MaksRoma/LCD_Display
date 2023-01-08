#include "Display.h"

const char str[] = "probuy gru";

void setup()
{
  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);

  LCD_Setup();
  
  Print_CMD(0x80);
  delay(2);

  millis();
  for(int i = 0; i < 10; i++)
    Print_Data(str[i]);
}

void loop()
{

}
