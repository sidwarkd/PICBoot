// The main entry point of your program

#include "INCLUDES.h"

#pragma udata access bootloader_variable=0x50
volatile short MainAppRunning;
#pragma udata

short msCounter;

extern void _startup (void);        // See c018i.c in your C18 compiler dir
#pragma code _RESET_INTERRUPT_VECTOR = PROGRAM_START_ADDRESS  //0x000800
void _reset (void)
{
    _asm goto _startup _endasm
}

#pragma code HIGH_INTERRUPT_VECTOR = HIGH_INTERRUPT_ADDRESS
void Remapped_High_ISR (void)
{
    _asm goto ProcessHighPriorityInterrupt _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = LOW_INTERRUPT_ADDRESS
void Remapped_Low_ISR (void)
{
    _asm goto ProcessLowPriorityInterrupt _endasm
}

//These are your actual interrupt handling routines.
#pragma interrupt ProcessHighPriorityInterrupt
void ProcessHighPriorityInterrupt()
{
    
}

#pragma interruptlow ProcessLowPriorityInterrupt
void ProcessLowPriorityInterrupt()
{		
	// TMR0 Interrupt
	if( INTCONbits.TMR0IF && INTCONbits.TMR0IE )
	{
		// Clear Interruptflag
		INTCONbits.TMR0IF = 0;		
		if(++msCounter == 1000)
		{
		    msCounter = 0;
		    LCD_WriteFromROM(".");
		}
	}	
}

#pragma code
void main (void)
{
	InitializeApplication();
	LCD_WriteFromROM("Starting..");
	while(1);
}

void InitializeApplication()
{
    msCounter = 0;
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

	// Set up RA1 to be a switch
    TRISAbits.TRISA1 = 1;

    T0CON = 0x43;
	LCD_Initialize();
	INTCONbits.TMR0IE = 1;
	INTCON2bits.TMR0IP = 0;
	RCONbits.IPEN = 1;
	TMR0L = 0x00;
	INTCONbits.GIEH = 1;	// Turn on high priority interrupts
	INTCONbits.GIEL = 1;	// Turn on low priority interrupts
	T0CONbits.TMR0ON = 1;
}
