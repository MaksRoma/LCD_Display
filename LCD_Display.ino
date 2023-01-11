#include "Display.h"
#include "CGRAM.h"

const char str[] = "probuy gru";
uint8_t i = 0;


void setup()
{
  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);

  LCD_Setup();
  delay(1000);


  Print_CMD(0x80);
  delay(50);

  Print_Data(0x41);

}

void loop()
{

}