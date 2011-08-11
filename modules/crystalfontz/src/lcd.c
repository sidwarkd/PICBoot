// FILE:		lcd.c
// AUTHOR: 		Kevin Sidwar
// DATE:   		07-23-2011
// DESCRIPTION: Crystalfontz LCD module
// LICENSE:		see main.c for license info
// CHANGELOG:
// MM-DD-YYYY
// 07-23-2011: initial version created.

#define LCD_GLOBALS
#include "INCLUDES.h"

#pragma code
// ============================================================================
//                            CORE FUNCTIONS
//
// The following functions are the core functions for the module and should
// not need to be changed.  The public functions are:
//
// LCD_Initialize - Configure the display and get it ready
// LCD_WriteFromROM - Display a string located in program memory on the display
// LCD_WriteFromRAM - Dispaly a string located in data memory on the display
//
// ============================================================================
void LCD_Initialize()
{
	// Setup pins
	LCD_CS = 1;
	LCD_CLK = 1;
}

void LCD_WriteFromROM(const rom CHAR *data)
{
	while(*data)
	{
		WriteLCDSPIByte(*data++);
	}
}

void LCD_WriteFromRAM(const ram CHAR *data)
{
	while(*data)
	{
		WriteLCDSPIByte(*data++);
	}
}

void LCD_ClearScreen(void)
{
    // Restore Display
    WriteLCDSPIByte((CHAR) 0x0C);
}

void WriteLCDSPIByte(CHAR b)
{
	CHAR BitCount = 8;
	static CHAR data;
	data = b;
	// Assert CS
	LCD_CS = 0;

	do                       // Loop 8 times
    {
	    LCD_DATA = 0;        // Set Dout to the next bit according to
	    if(data&0x80)        // the MSB of data
	            LCD_DATA = 1;
		LCD_CLK = 0;
		DelayMS(1);
		LCD_CLK = 1;
		DelayMS(1);
		_asm
	    rlcf  data,1,1
	    _endasm
	    BitCount--;             // Count iterations through loop
    } while(BitCount);
	LCD_CS = 1;
}

void DelayMS(UINT08 x)
{
	while(x--)Delay100TCYx(40);
}
