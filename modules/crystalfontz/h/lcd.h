#ifndef LCD_H
#define LCD_H

// ============================================================================
// PLATFORM SPECIFIC ITEMS
// The following items will vary per project and need to be configured
//
// ============================================================================

#define LCD_CS	LATCbits.LATC0
#define LCD_CLK	LATCbits.LATC1
#define LCD_DATA LATCbits.LATC2

// ============================================================================
// ****** YOU SHOULD NOT NEED TO MAKE CHANGES BELOW THIS POINT ******
// ============================================================================

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
void LCD_Initialize(void);
void LCD_WriteFromROM(const rom CHAR *data);
void LCD_WriteFromRAM(const ram CHAR *data);
void LCD_ClearScreen(void);
void WriteLCDSPIByte(CHAR b);
void DelayMS(UINT08);
#endif
