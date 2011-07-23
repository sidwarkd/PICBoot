// FILE:		main.c
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION: Main entry point for the bootloader application

// LICENSE:		http://creativecommons.org/licenses/by-nc-sa/3.0/
// CHANGELOG:
// MM-DD-YYYY
// 06-03-2011: initial version re-created.

#include "INCLUDES.h"

// C O N F I G U R A T I O N
// Note: For a complete list of the available config pragmas and their values,
// see the compiler documentation.  These config bits are not changeable by
// the user program because that could potentially break the behavior of the 
// bootloader.  If necessary, most of these settings can be modified 
// programmatically in the user program.

#pragma config WDTEN	= OFF		// Watchdog disabled
#pragma config PLLDIV	= 2		// 8 MHz crystal
#pragma config CFGPLLEN = ON		// PLL Enabled
#pragma config STVREN	= ON		// Stack over/underflow reset enabled
#pragma config XINST	= OFF		// Extended instruction set off
#pragma config CPUDIV	= OSC3_PLL3	// CPU system clock divide by 3
#pragma config CP0	= OFF		// Disable code protect
#pragma config OSC	= INTOSCPLL	// Use internal oscillator
#pragma config SOSCSEL 	= DIG
#pragma config CLKOEC	= OFF		// CLKO output disabled on RA6
#pragma config FCMEN	= OFF		// Fail-Safe clock monitor off
#pragma config IESO	= OFF		// Internal/External osc switch over mode
#pragma config WDTPS 	= 32768		// WD post scalar
#pragma config DSWDTOSC	= INTOSCREF	// DSWDT uses INTRC
#pragma config RTCOSC	= INTOSCREF	// RTCC clock select
#pragma config DSBOREN	= OFF		// Deep Sleep BOR
#pragma config DSWDTEN	= OFF		// Deep Sleep WDT
#pragma config DSWDTPS	= K32		// Deep Sleep WDT Postscalar
#pragma config IOL1WAY	= OFF		// IOCLOCK one-way enable
#pragma config ADCSEL	= BIT10		// ADC 10 bit
#pragma config MSSP7B_EN = MSK5		// MSSP address masking
#pragma config WPCFG	= OFF		// Config words page write protect
#pragma config WPDIS	= OFF		// WPCFG bits ignored
#pragma config LS48MHZ	= SYS48X8

void main (void)
{
    #ifndef TEST
    //TODO: Determine whether or not it's bootloader mode and react accordingly
    //TODO: Remap reset and interrupt vectors
    LCD_WriteFromROM("Starting App");
    
    #else
    LCD_WriteFromROM("Test Mode");
    if(Bootldr_TestHarness())
	{
        ClrWdt();
        while(1);
	}
    else
	{
        Sleep();
        while(1);
	}
	#endif
}
