#ifndef Display_h
#define Display_h
//--------------------------------------------------------------------------------------------------------------
#include "Arduino.h"
//--------------------------------------------------------------------------------------------------------------
// Use an enum for pin constants, for instance
enum LCD_Interface
{ 
  //Port D (0-7 pins)
  DB7, DB6, DB5, DB4, DB3, DB2, DB1, DB0,

  //Port B (8-9 pins)
  E, RS, RW
};
//--------------------------------------------------------------------------------------------------------------


//DB0 = 1;
//DDRAM = 020H (space)
void Clear_Display();
//--------------------------------------------------------------------------------------------------------------


//DB1 = 1, DB0 = X;
//X = "1" or "0" (does not affect on instruction result);
//DDRAM address = 00H
void Return_Home();
//--------------------------------------------------------------------------------------------------------------


// DB2 = 1, DB1 - I/D, DB0 = S;
// I/D = Increment/Decrement (1/0);
// S: Shift of entire display:
// |---|-----|------------------------------|;
// | S | I/D |       Description            |;
// |---|-----|------------------------------|;
// | H |  H  |Shift the display to the left |;
// |---|-----|------------------------------|;
// | H |  L  |Shift the display to the right|;
// |----------------------------------------|;
void Set_Entry_Mode(bool db0,bool db1);
//--------------------------------------------------------------------------------------------------------------


//DB3 = 1, DB2 = D, DB1 = C, DB0 = B;
//---------------------------------------------------------------;
//D - Display control bit: ;
//"1" - entire display is turned on;
//"0" - display is turned off, but display data remained in DDRAM;
//---------------------------------------------------------------;
//C - Cursor control bit: ;
//"1" - cursor is turned on;
//"0" - display is turned off, but display data remained in DDRAM;
//---------------------------------------------------------------;
//B - Blink control bit: ;
//"1" - entire display is turned on;
//"0" - display is turned off, but display data remained in DDRAM;
void Set_Display(bool db0, bool db1, bool db2);
//--------------------------------------------------------------------------------------------------------------


//DB4 = 1, DB3 = S/C, DB2 = R/L, DB1 = X, DB0 = X;
//S/C - Screen/Cursor: ;
//  - "1" - Display handling;
//  - "0" - Cursor handling;
//R/L - side of shifting;
//  - "1" - Right shift;
//  - "0" - Left shift;
//X - any value ("0" or "1");
// |-----|-----|---------------------------------------------------------|--------------|;
// | S/C | R/L |                       Description                       |   AC Value   |;
// |-----|-----|---------------------------------------------------------|--------------|;
// |  L  |  L  |Shift cursor to the left                                 |AC = AC - 1   |;
// |-----|-----|---------------------------------------------------------|--------------|;
// |  L  |  H  |Shift cursor to the right                                |AC = AC + 1   |;
// |-----|-----|---------------------------------------------------------|--------------|;
// |  H  |  L  |Shift display to the left. Cursor follows display shift  |AC = AC       |;
// |-----|-----|---------------------------------------------------------|--------------|;
// |  H  |  H  |Shift display to the right. Cursor follows display shift |AC = AC       |;
// |-----|-----|---------------------------------------------------------|--------------|;
void Shift_Display_Or_Cursor(bool db0, bool db1, bool db2, bool db3);
//--------------------------------------------------------------------------------------------------------------


//DB5 = 1, DB4 = DL, DB3 = N, DB2 = F, DB1 = X, DB0 = X;
//DL - data length control bit: ;
//  - "1" - 8-bit bus mode with MPU; 
//  - "0" - 4-bit bus mode with MPU; 
//N - line number control bit: ;
//  - "1" - 2-line display mode; 
//  - "0" - 1-line mode; 
//F - font type control bitL ;
//  - "1" - 5x8 dots format display mode; 
//  - "0" - 5x11 dots format display mode;
//X - any value ("0" or "1");
// |-----|-----|-----------------------------------|------------------|---------------|;
// |  N  |  F  |      Number of Display lines      |  Character Font  |  Duty Factor  |;
// |-----|-----|-----------------------------------|------------------|---------------|;
// |  L  |  L  |                 1                 |        5x8       |      1/8      |;
// |-----|-----|-----------------------------------|------------------|---------------|;
// |  L  |  H  |                 1                 |        5x11      |      1/11     |;
// |-----|-----|-----------------------------------|------------------|---------------|;
// |  H  |  X  |                 2                 |        5x8       |      1/16     |;
// |-----|-----|-----------------------------------|------------------|---------------|;
void Set_Function(bool db0, bool db1, bool db2, bool db3, bool db4);
//--------------------------------------------------------------------------------------------------------------


//DB6 = 1,DB5 = AC5, DB4 = AC4, DB3 = AC3, DB2 = AC2, DB1 = AC1, DB0 = AC0;
//AC5-AC0 - digits of AC(address counter);
//AC = address of CGRAM;
void Set_CGRAM_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5);
//--------------------------------------------------------------------------------------------------------------


//DB7 = 1,DB6 = AC6,DB5 = AC5, DB4 = AC4, DB3 = AC3, DB2 = AC2, DB1 = AC1, DB0 = AC0;
//AC6-AC0 - digits of AC(address counter);
//AC = address of DDRAM;
//if 1-line display mode(N = 0), DDRAM address = 00H - 4FH;
//;
//if 2-line display mode(N = 1), DDRAM address: ;
//1 line = 00H - 27H;
//2 line = 40H - 67H;
void Set_DDRAM_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6);
//--------------------------------------------------------------------------------------------------------------


//RW = 1, DB7 = BF;
//DB6-DB0 = AC6-AC0;
//;
//
void Read_BF_and_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7);
//--------------------------------------------------------------------------------------------------------------



void Write_To_RAM(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7);
//--------------------------------------------------------------------------------------------------------------



void Read_From_RAM(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7);


#endif
