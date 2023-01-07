#include "Display.h"


void setup()
{
  pinMode(RS,OUTPUT);
  pinMode(E,OUTPUT);

  // pinMode(DB0,OUTPUT);
  // pinMode(DB1,OUTPUT);
  // pinMode(DB2,OUTPUT);
  // pinMode(DB3,OUTPUT);
  pinMode(DB4,OUTPUT);
  pinMode(DB5,OUTPUT);
  pinMode(DB6,OUTPUT);
  pinMode(DB7,OUTPUT);

  LCD_Setup();
}

void loop()
{
  //set cursor
  //. . .


  digitalWrite(RS, HIGH);
  //clear display from previous using
  Print_DBus(0x0);
  Print_DBus(0x1);


  //print upper-case 4-bits
  Print_DBus(0x2);
  //latching
  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
  //print lower-case 4-bits
  Print_DBus(0x8);
  //latching
  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
  
  delay(250);
}
