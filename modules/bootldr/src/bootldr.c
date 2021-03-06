// FILE:		bootldr.c
// AUTHOR: 		Kevin Sidwar
// DATE:   		6-3-2011
// DESCRIPTION:         Bootloader module
// LICENSE:		see main.c for license info
// CHANGELOG:
// MM-DD-YYYY
// 06-3-2011: initial version created.

#define BOOTLDR_GLOBALS
#include "INCLUDES.h"


// ============================================================================
//                            CORE FUNCTIONS
//
// The following functions are the core functions for the bootloader and should
// not need to be changed.  They rely on the supporting functions below.  The
// public functions are:
//
// Bootldr_Initialize(void) - initialize the bootloader and open the data source
// Bootldr_Erase(void) - erase the flash memory where applications reside
// Bootldr_Verify(void) - verify that the data programmed matches the hex data provided
// Bootldr_Program(void) - program the device using the configured data source
// Bootldr_TestHarness(void) - only used for testing.  Should not be in production build
//
// ============================================================================

#pragma code
void Bootldr_Initialize(void)
{
    // Perform any initialization here
	// Turn on the timer that will call disk_timerproc
	T0CONbits.TMR0ON = 1;
    
	// Initialize the SD Card
    SDCARD_Initialize();
}

void Bootldr_Erase(void)
{
    flash_erase();
}

BOOL Bootldr_Verify(void)
{
    HexRecord currentRecord;
    CHAR programData[MAX_HEX_PAYLOAD_SIZE_IN_BYTES];
    UINT08 i;

    // Open the data source to compare with
    open_source();
    
    read_record(&currentRecord);
    while(currentRecord.RecordType != HR_EOF)
    {
        if(currentRecord.RecordType == HR_DATA)
        {
            if((currentRecord.Address >= USER_PROGRAM_START_ADDRESS) && (currentRecord.Address < USER_PROGRAM_END_ADDRESS))
            {
                // Read the program memmory that corresponds to the current hex record
                flash_read(programData, currentRecord.Address, currentRecord.ByteCount);
                
                // Compare program memory to the hex record data
                for(i = 0; i < currentRecord.ByteCount; i++)
                {
                    if(programData[i] != currentRecord.data[i])
                    {
                        close_source();
						return FALSE;
                    }
                }   
            }
        }
        read_record(&currentRecord);
    }
    
    close_source();
    return TRUE;
}

void Bootldr_Program(void)
{
    HexRecord currentRecord;
    Bootloader bootLoader;
    UINT08 bytesWritten;

    // Open the data source
    open_source();
    
    // Erase the user program area
    Bootldr_Erase();
    
    //Bootloader will start programming at the user program start address
    bootLoader.start_address = USER_PROGRAM_START_ADDRESS;
    bootLoader.end_address = bootLoader.start_address + PROGRAM_BLOCK_SIZE_IN_BYTES;
    initialize_buffer_data(&bootLoader);

    // Process each record in the data source.
    read_record(&currentRecord);
    while(currentRecord.RecordType != HR_EOF)
    {
        if(currentRecord.RecordType == HR_DATA)
        {
            // Verify we are in the user program range
            if((currentRecord.Address >= USER_PROGRAM_START_ADDRESS) && (currentRecord.Address < USER_PROGRAM_END_ADDRESS))
            {
                if(currentRecord.Address < bootLoader.end_address)
                {
                    if((currentRecord.Address + currentRecord.ByteCount) <= bootLoader.end_address)
                    {
                        mystrncpy(&bootLoader.data_buffer[currentRecord.Address - bootLoader.start_address], currentRecord.data, currentRecord.ByteCount);
                        read_record(&currentRecord);
                    }
                    else
                    {
                        // We need to split the data between two program blocks
                        bytesWritten = bootLoader.end_address - currentRecord.Address;
                        mystrncpy(&bootLoader.data_buffer[currentRecord.Address - bootLoader.start_address], currentRecord.data, bytesWritten);
                        flash_write(bootLoader.data_buffer, bootLoader.start_address, PROGRAM_BLOCK_SIZE_IN_BYTES);
                        
                        // Move a block ahead
                        bootLoader.start_address += PROGRAM_BLOCK_SIZE_IN_BYTES;
                        bootLoader.end_address = bootLoader.start_address + PROGRAM_BLOCK_SIZE_IN_BYTES;
                        initialize_buffer_data(&bootLoader);
						
                        // Put the remaining data from the HexRecord in the buffer
                        mystrncpy(bootLoader.data_buffer, &currentRecord.data[bytesWritten], currentRecord.ByteCount - bytesWritten);
                        read_record(&currentRecord);
                    }
                }
                else
                {
                    // Write what we've got in the buffer
                    flash_write(bootLoader.data_buffer, bootLoader.start_address, PROGRAM_BLOCK_SIZE_IN_BYTES);
                    initialize_buffer_data(&bootLoader);
                    
                    // Set the program block address
                    bootLoader.start_address = currentRecord.Address & BLOCK_ALIGN_CONSTANT;
                    bootLoader.end_address = bootLoader.start_address + PROGRAM_BLOCK_SIZE_IN_BYTES;
                }
            }
            else
            {
                // We're outside the user program space so move to the next record unless we've passed the end
				// in which case write what's left in the buffer and exit the loop
				if(currentRecord.Address >= USER_PROGRAM_END_ADDRESS)
				{
					flash_write(bootLoader.data_buffer, bootLoader.start_address, PROGRAM_BLOCK_SIZE_IN_BYTES);
                    initialize_buffer_data(&bootLoader);
					break;	
				}
                read_record(&currentRecord);
            }
        }
        else
        {
            // Any other record type is either handled in the parser or ignored
            read_record(&currentRecord);
        }
    }

	// Write what's in the buffer
	flash_write(bootLoader.data_buffer, bootLoader.start_address, PROGRAM_BLOCK_SIZE_IN_BYTES);

    // Close/cleanup the data source
    close_source();
}

#ifdef TEST
BOOL Bootldr_TestHarness(void)
{
    CHAR buffer[PROGRAM_BLOCK_SIZE_IN_BYTES];
    
    // A program and verify should succeed
	Bootldr_Program();
	if(!Bootldr_Verify())
	    return FALSE;
	
	// Change some data and call verify again.  It should fail this time
	buffer[5] = 0xEE;
	flash_write(buffer, USER_PROGRAM_START_ADDRESS, PROGRAM_BLOCK_SIZE_IN_BYTES);
	if(Bootldr_Verify())
	    return FALSE;
	    
	return TRUE;
}
#endif

// ============================================================================
//                            SUPPORTING FUNCTIONS
//
// The following functions will need to change depending on the platform.  The
// core bootloader functionality depends on the expected behavior of these
// functions.  The functions currently contain code for an SD card based
// bootloader however they can be modified to use any hex data source and target
// any PIC device.  Simply modify the functions below to suite your application.
//
//
// ============================================================================

// ============================================================================
//                           ERASE FLASH PROGRAM MEMORY
//
// Description  : Erases the application area of flash memory on the device
// Arguments    : None
// Returns      : None
// Notes        : This function should take care not to overwrite the bootloader
//                area of flash memory.
//
// ============================================================================
void flash_erase(void)
{
    UINT08 blocksErased = 0;
    
    TBLPTR = USER_PROGRAM_START_ADDRESS;
    EECON1bits.WREN = ENABLE;
    EECON1bits.FREE = ENABLE;
    while(blocksErased++ <= NUM_BLOCKS_TO_ERASE)
    {
        flash_commit();
        TBLPTR += ERASE_BLOCK_SIZE_IN_BYTES;
    }
    EECON1bits.WREN = DISABLE;
    EECON1bits.FREE = DISABLE;
}

// ============================================================================
//                           READ FLASH PROGRAM MEMORY
//
// Description  : Read a segment of flash memory
// Arguments    : buffer - the buffer used to store the data read
//                address - the starting address of the segment to read
//                numberOfBytesToRead - ok, this one is self explanatory
//
// Returns      : None
// Notes        : This function assumes that buffer has enough space to hold
//                numberOfBytesToRead worth of data.
//
// ============================================================================
void flash_read(char *buffer, UINT24 address, UINT08 numberOfBytesToRead)
{
    UINT08 numBytesRead = 0;

    TBLPTR = address;
    while(numBytesRead++ < numberOfBytesToRead)
    {
        _asm tblrdpostinc _endasm
        *buffer++ = TABLAT;
    }
}

// ============================================================================
//                           WRITE FLASH PROGRAM MEMORY
//
// Description  : Write a segment of flash memory
// Arguments    : buffer - the buffer containing the data to write
//                address - the starting address of the segment to write
//                numberOfBytesToRead - ok, this one is self explanatory
//
// Returns      : None
// Notes        : address should be block aligned according to the requirements
//                of the target platform.  If numberOfBytesToWrite is less than
//                the programming block size this routine should write 0xFF
//                in the unused locations.
//
// ============================================================================
void flash_write(char *buffer, UINT24 address, UINT08 numberOfBytesToWrite)
{
    UINT08 bytesWritten = 0;

    TBLPTR = address;

    // Fill the holding registers
    while(bytesWritten < PROGRAM_BLOCK_SIZE_IN_BYTES)
    {
        if(bytesWritten < numberOfBytesToWrite)
        {
            TABLAT = *buffer++;
        }
        else
        {
            TABLAT = 0xFF;
        }
        _asm tblwtpostinc _endasm
        bytesWritten++;
    }

    // Put the TBLPTR back in the holding register space.
    _asm tblrdpostdec _endasm

    EECON1bits.WREN = ENABLE;
    flash_commit();
    //EECON1bits.WREN = DISABLE;
}

// ============================================================================
//                     COMMIT ROUTINE FOR FLASH OPERATIONS
//
// Description  : This function contains shared steps between the different
//                flash memory operations
// Arguments    : None
// Returns      : None
// Notes        : 
//
// ============================================================================
void flash_commit(void)
{
    INTCONbits.GIE = 0;     //Make certain interrupts disabled for unlock process.
    
    _asm
    MOVLW 0x55
    MOVWF EECON2, 0
    MOVLW 0xAA
    MOVWF EECON2, 0
    BSF EECON1, 1, 0        //Performs write
    _endasm

    while(EECON1bits.WR);   //Wait until complete (relevant when programming EEPROM, not important when programming flash since processor stalls during flash program)
    INTCONbits.GIE = 1;     // Re-enable interrupts
}

void initialize_buffer_data(Bootloader *bootldr)
{
    UINT08 i = 0;
    for(i = 0; i < PROGRAM_BLOCK_SIZE_IN_BYTES; i++)
    {
        bootldr->data_buffer[i] = 0xFF;
    }
}

void mystrncpy(CHAR *dest, CHAR *src, UINT08 count)
{
    UINT08 i;
    for(i = 0; i < count; i++)
    {
        *dest++ = *src++;
    }
}
