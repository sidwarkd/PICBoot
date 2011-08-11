// FILE:		hexreader.c
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION:         Code to read and parse hex files
// LICENSE:		http://creativecommons.org/licenses/by-nc-sa/3.0/
// CHANGELOG:
// MM-DD-YYYY
// 07-14-2011: initial version re-created.

#include "INCLUDES.h"

#pragma udata
UINT24 currentHighAddress;

#pragma code
BOOL parse_hex_line(CHAR *data, HexRecord *record);
UINT16 convert_hex_digit(CHAR hexCharacter);
#ifdef TEST
char* get_fake_hex_line();
#pragma udata 
UINT08 hexIndex;
#pragma code
#endif
// ============================================================================
//                           READ THE NEXT HEX RECORD
//
// Description  : This function fetches and parses the next hex record from the
//                data source.
// Arguments    : None
//
// Returns      : A populated HexRecord structure
// Notes        : 
//
// ============================================================================
void read_record(HexRecord *record)
{
	CHAR *data;
	#ifdef TEST
		parse_hex_line(get_fake_hex_line(), record);
	#else
		// Read a line from the hex file
		if(data = SDCARD_ReadLine())
		{
			parse_hex_line(data, record);
		}
		else
		{
			record->RecordType = HR_EOF;
		}
	#endif
}

// ============================================================================
//                           OPEN THE HEX DATA SOURCE
//
// Description  : This function opens the data source that contains the hex
//                records for programming the device.  The source can be
//                anything like USB, Serial Connection, SPI, or SD card.
// Arguments    : None
//
// Returns      : A populated HexRecord structure
// Notes        : This function should handle all initialization of the data
//                source to be used for programming the target device.  This
//                function needs to ensure that the data source is at the
//                beginning of the hex records to read.
//
// ============================================================================
void open_source(void)
{
	// Open file on SD card and initialize cursor to beginning
	CHAR hexFile[13]={"platform.hex"};
	currentHighAddress = 0;

	#ifdef TEST
		hexIndex = 0;
	#else
		SDCARD_OpenFile(hexFile);
	#endif
}

// ============================================================================
//                           CLOSE THE HEX DATA SOURCE
//
// Description  : This function closes the data source that contains the hex
//                records for programming the device.
// Arguments    : None
//
// Returns      : A populated HexRecord structure
// Notes        : The close_source function should handle all aspects of closing
//                the data source including the cleanup of any resources used.
//
// ============================================================================
void close_source(void)
{
    // Nothing needs to be done here with Petit FatFS
}

// ============================================================================
//                           PARSE A LINE FROM HEX FILE
//
// Description  : This function takes a line from a hex file and parses it into
//				  a HexRecord struct
// Arguments    : data - the line from the hex file
//				: record - the HexRecord structure to populate
//
// Returns      : TRUE if it parses the line successfully.  FALSE, otherwise
// Notes        : 
//
// ============================================================================
BOOL parse_hex_line(CHAR *data, HexRecord* record)
{
	UINT24 temp = 0;

	// Initialize record
	record->ByteCount = 0;
	record->Address = currentHighAddress;
	for(temp = 0; temp < MAX_HEX_PAYLOAD_SIZE_IN_BYTES; temp++)
	{
		record->data[temp] = 0;
	}
	record->Checksum = 0;

	// The line must start with a colon.  Otherwise something is wrong;
	if(*data++ == ':')
	{
		record->ByteCount += (convert_hex_digit(*data++) << 4);
		record->ByteCount += convert_hex_digit(*data++);
		record->Address += (convert_hex_digit(*data++) << 12);
		record->Address += (convert_hex_digit(*data++) << 8);
		record->Address += (convert_hex_digit(*data++) << 4);
		record->Address += convert_hex_digit(*data++);
		temp = 0;
		temp += (convert_hex_digit(*data++) << 1);
		temp += convert_hex_digit(*data++);
		record->RecordType = temp;
		
		// Read the data portion
		for(temp = 0; temp < (2*record->ByteCount); temp+=2)
		{
			record->data[temp/2] += (convert_hex_digit(*data++) << 4);
			record->data[temp/2] += convert_hex_digit(*data++);
		}

		record->Checksum += convert_hex_digit(*data++) << 4;
		record->Checksum += convert_hex_digit(*data++);
		
		// If the record type is an Extended Linear Address Record
		// then let's set the currentHighAddress variable here
		if(record->RecordType == HR_EXT_LINEAR_ADDRESS)
        {
            currentHighAddress = 0;
			temp = record->data[0];
            currentHighAddress += (temp << 24);
			temp = record->data[1];
		    currentHighAddress += (temp << 16);
        }
	}
	else
		return FALSE;
	
}

// ============================================================================
//                           CONVERT HEX DIGIT TO NUMBER
//
// Description  : This function converts a hex digit to a number
// Arguments    : hexCharacter - the hex char to convert
//
// Returns      : The UINT08 value of the hex digit
// Notes        : 
//
// ============================================================================
UINT16 convert_hex_digit(CHAR hexCharacter)
{
    //TODO: Increase the efficiency and reduce code of convert_hex_digit()
	UINT08 ret = -1;
	switch(hexCharacter)
	{
		case ('0'):
			ret = 0;
			break;
		case ('1'):
			ret = 1;
			break;
		case ('2'):
			ret = 2;
			break;
		case ('3'):
			ret = 3;
			break;
		case ('4'):
			ret = 4;
			break;
		case ('5'):
			ret = 5;
			break;
		case ('6'):
			ret = 6;
			break;
		case ('7'):
			ret = 7;
			break;
		case ('8'):
			ret = 8;
			break;
		case ('9'):
			ret = 9;
			break;
		case ('a'):
			ret = 10;
			break;
		case ('b'):
			ret = 11;
			break;
		case ('c'):
			ret = 12;
			break;
		case ('d'):
			ret = 13;
			break;
		case ('e'):
			ret = 14;
			break;
		case ('f'):
			ret = 15;
			break;
		case ('A'):
			ret = 10;
			break;
		case ('B'):
			ret = 11;
			break;
		case ('C'):
			ret = 12;
			break;
		case ('D'):
			ret = 13;
			break;
		case ('E'):
			ret = 14;
			break;
		case ('F'):
			ret = 15;
			break;
		default:
			ret = -1;
			break;
	}
	return ret;
}

// ============================================================================
//                                TEST FUNCTIONS
//
// Description  : The following functions are used for testing only
//
// Notes        : The close_source function should handle all aspects of closing
//                the data source including the cleanup of any resources used.
//
// ============================================================================
#ifdef TEST
// Sample hex file to be used by the test routines
rom const CHAR *rom table[] = 
{
":020000040000FA",
":0600000075EF40F0120054",
":0600080004EF40F01200BD",
":060018000CEF40F01200A5",
":0680000075EF40F01200D4",
":0680080083EF40F01200BE",
":068018008CEF40F01200A5",
":02802900000055",
":04802C00290EF66EB5",
":10803000800EF76E000EF86E00010900F550656FB6",
":108040000900F550666F03E1656701D03DD0090076",
":10805000F550606F0900F550616F0900F550626FCF",
":1080600009000900F550E96E0900F550EA6E0900B3",
":1080700009000900F550636F0900F550646F0900AD",
":108080000900F6CF67F0F7CF68F0F8CF69F060C06D",
":10809000F6FF61C0F7FF62C0F8FF0001635302E121",
":1080A000645307E00900F550EE6E6307F8E26407D9",
":1080B000F9D767C0F6FF68C0F7FF69C0F8FF000195",
":0A80C0006507000E665BBFD71200D3",
":0680CA00B00EF36E00EEA3",
":1080D00000F00E0E01D81200EA6002D0EE6AFCD762",
":0A80E000F350E9601200EE6AFCD7CD",
":0680EA001CEE00F02CEE7C",
":1080F00000F0F86A019C16EC40F08FEC40F08DEC3B",
":0681000040F0FBD7120065",
":0A810600DACFE4FFE2CFDAFFE65221",
":0E811000E552E5CFDAFF1100120000D0120098",
":02811E0012004D",
":020000040001F9",
":01FFF800AC5C",
":01FFF900F512",
":01FFFA0012F4",
":01FFFB00FF06",
":01FFFC007193",
":01FFFD00F211",
":01FFFE00FF03",
":01FFFF00FB06",
":00000001FF"};

void str2ram(static CHAR *dest, static CHAR rom *src)
{
	while ((*dest++ = *src++) != '\0');
}

CHAR* get_fake_hex_line()
{
	static CHAR line[50];
	str2ram(line, table[hexIndex++]);

	return line;
}
#endif
