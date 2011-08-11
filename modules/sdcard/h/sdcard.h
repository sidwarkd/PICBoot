// FILE:		sdcard.h
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION: Master include file for the sd card module.
//
// LICENSE:		see main.c for license info
// CHANGELOG:
// MM-DD-YYYY
// 07-23-2011: initial version created.

#ifndef SDCARD_H
#define	SDCARD_H

#include "diskio.h"
#include "pff.h"

// ============================================================================
// PLATFORM SPECIFIC ITEMS
// The following items will vary per project and need to be configured
//
// ============================================================================

#define GetSystemClock()		(16000000ul)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()
   
#define SD_CS			LATCbits.LATC6		// SD chip select
#define SD_CS_TRIS		TRISCbits.TRISC6	// SD chip select TRIS

#define SPI_SCK_TRIS	TRISBbits.TRISB4	// SPI Clock TRIS
#define SPI_MISO_TRIS	TRISBbits.TRISB5	// SPI Master input/Slave output TRIS
#define SPI_MOSI_TRIS	TRISCbits.TRISC7	// SPI Master output/Slave input TRIS

// ============================================================================
// ****** YOU SHOULD NOT NEED TO MAKE CHANGES BELOW THIS POINT ******
// ============================================================================

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
BOOL SDCARD_Initialize(void);
BOOL SDCARD_OpenFile(void *filename);
CHAR* SDCARD_ReadLine(void);
void SDCARD_Dispose(void);


#endif
