#include "Display.h"
#include "CGRAM.h"
/*--------------------------------------------------------------------------------------------------------------*/
bool PB_0, STATE_PB0_0, STATE_PB0_1;
bool PB_1, STATE_PB1_0, STATE_PB1_1;
const char welcome[] = "Hello, World!";
const char str[] = "MaksRoma here";
uint8_t i;
uint32_t time;
/*--------------------------------------------------------------------------------------------------------------*/
void setup()
{

  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);
  pinMode(DB4,OUTPUT);
  
  pinMode(PB_LEFT,INPUT_PULLUP);
  pinMode(PB_RIGHT,INPUT_PULLUP);

  pinMode(0, INPUT_PULLUP);

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
  for(i = 0; i < sizeof(welcome) - 1; i++)
    Print_Data(welcome[i]);
  delay(1000);

  time = millis();
}
/*--------------------------------------------------------------------------------------------------------------*/
void loop()
{
  PB_0 = digitalRead(PB_RIGHT);
  PB_1 = digitalRead(PB_LEFT);
  
  if(millis() > time + 50)
  {
    //PB_0 == 1
    if(PB_0 == 0) 
    {
      if(STATE_PB0_0 == 0 && STATE_PB0_1 == 0)
        STATE_PB0_0 = 1; 

      else if(STATE_PB0_0 == 1 && STATE_PB0_1 == 0)
      {
        Print_CMD(CURSOR_SHIFT | DISPLAY_MOVE | MOVE_RIGHT);
        delay(50);
        STATE_PB0_1 = 1;
      }
      
      else if(STATE_PB0_0 == 1 && STATE_PB0_1 == 1)
        ;
    }
    //PB_0 == 0
    else if(PB_0 == 1)
    {
      if(STATE_PB0_0 == 1 && STATE_PB0_1 == 1)
        STATE_PB0_0 = 0;

      else if(STATE_PB0_0 == 0 && STATE_PB0_1 == 1)
        STATE_PB0_1 = 0;
    }


    //PB_1 == 1
    if(PB_1 == 0) 
    {
      if(STATE_PB1_0 == 0 && STATE_PB1_1 == 0)
      {
        STATE_PB1_0 = 1; 
      }
      else if(STATE_PB1_0 == 1 && STATE_PB1_1 == 0)
      {
        Print_CMD(CURSOR_SHIFT | DISPLAY_MOVE | MOVE_LEFT);
        delay(50);
        STATE_PB1_1 = 1;
      }
      else if(STATE_PB1_0 == 1 && STATE_PB1_1 == 1)
      {
        ;
      }
    }
    //PB_1 == 0
    else if(PB_1 == 1)
    {
      if(STATE_PB1_0 == 1 && STATE_PB1_1 == 1)
      {
        STATE_PB1_0 = 0;
      }
      else if(STATE_PB1_0 == 0 && STATE_PB1_1 == 1)
      {
        STATE_PB1_1 = 0;
      }
    }
  }
}
/*--------------------------------------------------------------------------------------------------------------*/