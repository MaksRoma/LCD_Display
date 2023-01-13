#include "Display.h"
#include "CGRAM.h"


const char welcome[] = "Hello, World!";
const char str[] = "MaksRoma here";
uint8_t i;


void setup()
{

  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);

  LCD_Setup();

  Print_CMD(0x40);
  Set_CGRAM(_Pattern_1);
  Set_CGRAM(_Pattern_2);  
  Set_CGRAM(_Pattern_3); 
  Set_CGRAM(_Pattern_4);  
  Set_CGRAM(_Pattern_5);  
  Set_CGRAM(_Pattern_6);  
  Set_CGRAM(_Pattern_2);
  
  Print_CMD(0x80);
  // first 4 characters from CGRAM
  for(i = 0; i < 4; i++)
    Print_Data(i);
  Print_Data(0x79);
  //5-th character from CGRAM
  Print_Data(4);
  Print_Data(0x20);
  //6-th character from CGRAM
  Print_Data(5);
  //7-th character from CGRAM
  Print_Data(1);
  Print_Data(0x79);


  Print_CMD(0xC0);
  Print_To_LCD("Hello, World!");
  Print_To_LCD(26);

  // Print_CMD(0xC0);
  // delay(50);
  // for(i = 0; i < sizeof(welcome) - 1;i++)
  //   Print_Data(str[i]);
}

void loop()
{

}
