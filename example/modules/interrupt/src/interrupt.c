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

#pragma code
		
//These are your actual interrupt handling routines.
#pragma interrupt ProcessHighPriorityInterrupt
void ProcessHighPriorityInterrupt()
{
    
}

#pragma interruptlow ProcessLowPriorityInterrupt
void ProcessLowPriorityInterrupt()
{		
	// TMR2 Interrupt?
	if( INTCONbits.TMR0IF && INTCONbits.TMR0IE )
	{
		// Clear Interruptflag
		INTCONbits.TMR0IF = 0;		
		disk_timerproc();
	}	
}

void INTERRUPTS_Initialize()
{
    RCONbits.IPEN = 1;
    NextLowInterruptIndex = 0;
    NextHighInterruptIndex = 0;
}

void EnableInterrupt(UINT08 interruptID, INT_PRIORITY priority, UINT08 options);
{
    // Set priority
    // Enable interrupt
    switch(interruptID)
    {
        case INTERRUPT_TIMER0:
            INTCON2bits.TMR0IP = priority;
            INTCONbits.TMR0IE = 1;
            break;
        case INTERRUPT_TIMER1:
            
            PIE1bits.TMR1IE = 1;
            break;
        case INTERRUPT_INT0:
            // Always high priority.  No need to set
            INTCONbits.INT0IE = 1;
            break;
        default:
            break;
    }
}

BOOL UnregsiterInterrupt(UINT08 interruptID);

