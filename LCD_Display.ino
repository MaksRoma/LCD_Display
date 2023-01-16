#include "Display.h"
#include "CGRAM.h"
#include <LiquidCrystal.h>
//--------------------------------------------------------------------------------------------------------------
const char welcome[] = "Hello, World!";
const char str[] = "MaksRoma here";
uint8_t i;
//--------------------------------------------------------------------------------------------------------------
void setup()
{

  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);

  LCD_Setup();

  //uncomment, if you want use custom characters
  // Print_CMD(0x40);
  // Set_CGRAM(_Pattern_1);
  // Set_CGRAM(_Pattern_2);
  // Set_CGRAM(_Pattern_3);
  // Set_CGRAM(_Pattern_4);
  // Set_CGRAM(_Pattern_5);
  // Set_CGRAM(_Pattern_6);
  // Set_CGRAM(_Pattern_7);
  // Set_CGRAM(_Pattern_8);
  
  Print_CMD(0x80);

  Print_CMD(0xC0);
}
//--------------------------------------------------------------------------------------------------------------
void loop()
{

}
//--------------------------------------------------------------------------------------------------------------