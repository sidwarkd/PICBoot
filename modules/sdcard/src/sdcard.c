// FILE:		sdcard.c
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION: SD card module functions

// LICENSE:		http://creativecommons.org/licenses/by-nc-sa/3.0/
// CHANGELOG:
// MM-DD-YYYY
// 08-05-2011: initial version created.

#include "INCLUDES.h"
#include "delays.h"

static FATFS fileSystem;
CHAR dataBuffer[64];
static CHAR currentFile[32];

BOOL SDCARD_Initialize(void)
{
    SD_CS_TRIS = OUTPUT_PIN;		// SD chip select (inv)
	//SD_WP_TRIS = INPUT_PIN;			// Card Write Protect (inv)
	//SD_CD_TRIS = INPUT_PIN;			// Card Detect (inv)
	
	SPI_SCK_TRIS = OUTPUT_PIN;		// SPI-SCK
	SPI_MISO_TRIS = INPUT_PIN; 		// SPI-MISO	
	SPI_MOSI_TRIS = OUTPUT_PIN;		// SPI-MOSI
	
	// start values
	SD_CS = 1;		// CS is inverted

	memset(currentFile, 0, 32); 
	
	if(disk_initialize() == FR_OK)
	{
	    if(pf_mount(&fileSystem) == FR_OK)
	    {
	        DelayMS(200);
	        return TRUE;
	    }
	    else
	    {
	        return FALSE;
	    }
	}
	else
	{
	    return FALSE;
	}
}

BOOL SDCARD_OpenFile(void *filename)
{
    // Only one file can be open at a time with the Petit FatFS module so
    // there is no CloseFile function. Opening a second file closes the
    // currently open file 
	if(strcmp(currentFile, (char*)filename) == 0)
	{
		pf_lseek(0);
	}
	else
	{
		strcpy(currentFile, (char*)filename);
	    if (pf_open((char*)filename) == FR_OK)
	    {
	        DelayMS(200);
	        return TRUE;
	    }
	    else
	    {
	        return FALSE;
	    }
	}
}

CHAR* SDCARD_ReadLine(void)
{
    // Read in one byte at a time until we hit the newline character
    // We will consider a newline to be hex 0x0D 0x0A;
    WORD bytesRead;
    UINT08 index;
    BYTE currentChar;
    BYTE previousChar;

	currentChar = 0;    
    index = 0;
    do
	{
	    previousChar = currentChar;
	    
		if( pf_read(&currentChar, 1, &bytesRead) == FR_OK )
		{
			if(bytesRead == 1)
			{
		    	dataBuffer[index++] = currentChar;
			}
			else
			{
				// Reached EOF and data is in buffer
				if(index > 0)
				{
					dataBuffer[index] = NULL;
					return dataBuffer;
				}
				else
				{
					return NULL;
				}	
			}
		}
		else
		{
			return NULL;
		}
	} while( !(previousChar == 0x0D && currentChar == 0x0A));
	
	
	/*if(pf_read(dataBuffer, 20, &bytesRead) == FR_OK)
	{
	    dataBuffer[bytesRead] = 0;
	}
	else
	{
	    dataBuffer[0] = 'e';
	    dataBuffer[1] = 'r';
	    dataBuffer[2] = 'r';
	    dataBuffer[3] = 'o';
	    dataBuffer[4] = 'r';
	    dataBuffer[5] = 0;
	}*/
	
	// C-String null terminate
	dataBuffer[index] = NULL;
	return dataBuffer;
}

void SDCARD_Dispose(void)
{
    pf_mount(0);
}
