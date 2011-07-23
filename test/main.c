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

void YourHighPriorityISRCode();
void YourLowPriorityISRCode();

#define REMAPPED_RESET_VECTOR_ADDRESS			0x8000UL
#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x8008UL
#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x8018UL

extern void _startup (void);        // See c018i.c in your C18 compiler dir
#pragma code REMAPPED_RESET_VECTOR = REMAPPED_RESET_VECTOR_ADDRESS
void _reset (void)
{
    _asm goto _startup _endasm
}

#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
void Remapped_High_ISR (void)
{
     _asm goto YourHighPriorityISRCode _endasm
}

#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
void Remapped_Low_ISR (void)
{
     _asm goto YourLowPriorityISRCode _endasm
}

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void High_ISR (void)
{
     _asm goto REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Low_ISR (void)
{
     _asm goto REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS _endasm
}

#pragma code


//These are your actual interrupt handling routines.
#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode()
{
	//Check which interrupt flag caused the interrupt.
	//Service the interrupt
	//Clear the interrupt flag
	//Etc.
}	//This return will be a "retfie fast", since this is in a #pragma interrupt section 

#pragma interruptlow YourHighPriorityISRCode
void YourLowPriorityISRCode()
{
	//Check which interrupt flag caused the interrupt.
	//Service the interrupt
	//Clear the interrupt flag
	//Etc.
}	//This return will be a "retfie", since this is in a #pragma interruptlow section 

#pragma code
void main(void)
{
	return 0;
}
