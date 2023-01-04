//--------------------------------------------------------------------------------------------------------------
#include "Display.h"
//--------------------------------------------------------------------------------------------------------------
void Clear_Display()
{
	digitalWrite(DB0,1);

	digitalWrite(DB1,0);
	digitalWrite(DB2,0);
	digitalWrite(DB3,0);
	digitalWrite(DB4,0);
	digitalWrite(DB5,0);
	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Return_Home()
{
	digitalWrite(DB0,1);
	digitalWrite(DB1,1);

	digitalWrite(DB2,0);
	digitalWrite(DB3,0);
	digitalWrite(DB4,0);
	digitalWrite(DB5,0);
	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Set_Entry_Mode(bool db0,bool db1)
{
	digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,1);

	digitalWrite(DB3,0);
	digitalWrite(DB4,0);
	digitalWrite(DB5,0);
	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Set_Display(bool db0, bool db1, bool db2)
{
	digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,1);
  
	digitalWrite(DB4,0);
	digitalWrite(DB5,0);
	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Shift_Display_OR_Cursor(bool db0, bool db1, bool db2, bool db3)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,1);

	digitalWrite(DB5,0);
	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Set_Function(bool db0, bool db1, bool db2, bool db3, bool db4)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,1);

	digitalWrite(DB6,0);
	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Set_CGRAM_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,db5);
	digitalWrite(DB6,1);

	digitalWrite(DB7,0);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Set_DDRAM_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,db5);
	digitalWrite(DB6,db6);
	digitalWrite(DB7,1);

	digitalWrite(RS,0);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Read_BF_and_Address(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,db5);
	digitalWrite(DB6,db6);
	digitalWrite(DB7,db7);

	digitalWrite(RS,0);
  digitalWrite(RW,1);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Write_To_RAM(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,db5);
	digitalWrite(DB6,db6);
	digitalWrite(DB7,db7);

	digitalWrite(RS,1);
  digitalWrite(RW,0);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
void Read_From_RAM(bool db0, bool db1, bool db2, bool db3, bool db4, bool db5, bool db6, bool db7)
{
  digitalWrite(DB0,db0);
	digitalWrite(DB1,db1);
	digitalWrite(DB2,db2);
	digitalWrite(DB3,db3);
	digitalWrite(DB4,db4);
	digitalWrite(DB5,db5);
	digitalWrite(DB6,db6);
	digitalWrite(DB7,db7);

	digitalWrite(RS,1);
  digitalWrite(RW,1);
	digitalWrite(E,0);
}
//--------------------------------------------------------------------------------------------------------------
