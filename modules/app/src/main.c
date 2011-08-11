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

void HighPriorityISRCode();
void LowPriorityISRCode();

/** V E C T O R  R E M A P P I N G *******************************************/

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void Remapped_High_ISR (void)
{
     _asm goto HighPriorityISRCode _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Remapped_Low_ISR (void)
{
     _asm goto LowPriorityISRCode _endasm
}
#pragma code
		
//These are your actual interrupt handling routines.
#pragma interrupt HighPriorityISRCode
void HighPriorityISRCode()
{
}

#pragma interruptlow LowPriorityISRCode
void LowPriorityISRCode()
{		
	// TMR2 Interrupt?
	if( INTCONbits.TMR0IF && INTCONbits.TMR0IE )
	{
		// Clear Interruptflag
		INTCONbits.TMR0IF = 0;		
		disk_timerproc();
	}	
}

void main (void)
{
    #ifndef TEST
    CHAR *line;
	
	InitializeApplication();
	
	// Check for the bootloader switch
	if(BOOTLDR_SWITCH == SWITCH_ON)
	{
	    Bootldr_Initialize();
	    LCD_WriteFromROM("Program:");
        Bootldr_Program();
	    LCD_WriteFromROM("DONE");
	    LCD_WriteFromROM("\n\rVerify:");
	    if(Bootldr_Verify())
	    {
            LCD_WriteFromROM("PASS");
            //while(1);
	    }
        else
	    {
            LCD_WriteFromROM("FAIL");
            //while(1);
	    }
	    SDCARD_Dispose();
	}
	else
	{
	    // Go to the user application
	    _asm
	    goto USER_PROGRAM_START_ADDRESS
	    _endasm
	}

    //TODO: Determine whether or not it's bootloader mode and react accordingly
    //TODO: Remap reset and interrupt vectors

    
	while(1);
    
    #else
	InitializeApplication();
    LCD_WriteFromROM("Test Mode");
    if(Bootldr_TestHarness())
	{
        LCD_WriteFromROM("\r\nPASS");
        while(1);
	}
    else
	{
        LCD_WriteFromROM("\r\nFAILED");
        while(1);
	}
	#endif
}

void InitializeApplication()
{
    BOOL result;
    
	ADCON0 = 0x00;
	ADCON1 = 0x0F;  	// Make all pins digital
	ANCON0 = 0xFF;
	ANCON1 = 0xFF;
	LATA = 0x00;
	LATB = 0x00;
	LATC = 0x00;
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	
	// Enable internal PORTB pull-ups
    INTCON2bits.RBPU = 0;
    
    // Set up RA1 to be a switch
    TRISAbits.TRISA1 = INPUT_PIN;
    
    // Setup the TIMR0 module and enable interrupts
	T0CON = 0x43;
	INTCONbits.TMR0IE = 1;
	INTCON2bits.TMR0IP = 0;
	RCONbits.IPEN = 1;
	TMR0L = 0x00;
	INTCONbits.GIEH = 1;	// Turn on high priority interrupts
	INTCONbits.GIEL = 1;	// Turn on low priority interrupts
	T0CONbits.TMR0ON = 1;
    
    result = SDCARD_Initialize();
	LCD_Initialize();
	
	LCD_WriteFromROM("LCD: OK\r\n");
	if(result == TRUE)
	{
	    LCD_WriteFromROM("SD: OK\r\n");
	}
	else
	{
	    LCD_WriteFromROM("SD: FAIL\r\n");
	}

	DelayMS(20);
}
