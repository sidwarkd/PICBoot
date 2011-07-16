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
		parse_hex_line(data, record);
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
	currentHighAddress = 0;

	#ifdef TEST
		hexIndex = 0;
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
    // Close file on SD card
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
//struct HexRecord
//{
//    UINT08 ByteCount;
//    UINT24 Address;
//    enum HexRecordType RecordType;
//    char data[MAX_HEX_PAYLOAD_SIZE_IN_BYTES];
//    BYTE Checksum;
//};
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
		// TODO: set currentHighAddress
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
":060000003CEF09F01200C4",
":0600080064EF08F0120095",
":060018006CEF08F012007D",
":0610C0003CEF09F01200F4",
":0610C80076EF08F01200B3",
":0610D8007FEF08F012009A",
":0210EA00000004",
":0410EC00DACFE4FF74",
":1010F000E2CFDAFFE652E552E5CFDAFF1100120047",
":101100000F0EC112896A010E926E928080B002D0D9",
":1011100004D801D08992FAD712008972F40EE66ED3",
":10112000010EE66E04D8E552E552F7D71200D9CF8A",
":10113000E6FFE1CFD9FF080EE126040EDB6A050EBB",
":10114000DB6A060EDB6A070EDB6AFD0EDBCF00F002",
":10115000FE0EDBCF01F0026A036AD950040FE96E7C",
":10116000DACFEAFF0050EE5C0150EE580250EE5824",
":101170000350EE5828E2DE6ADE6ADE6ADD6ADD527E",
":10118000DD52D9CFE9FFDACFEAFFF40EEE5C010EB3",
":10119000EE58000EEE58000EEE580AE2D9CFE9FFE5",
":1011A000DACFEAFFEE2A000EEE22EE22EE22E9D797",
":1011B000D950040FE96EDACFEAFFEE2A000EEE22D4",
":1011C000EE22EE22C2D7080EE15C02E2E16AE552AD",
":0A11D000E16EE552E7CFD9FF1200EF",
":0611DA00EA0EF66E100E95",
":1011E000F76E000EF86E00010900F550656F0900FA",
":1011F000F550666F03E1656701D03DD00900F550F9",
":10120000606F0900F550616F0900F550626F0900C9",
":101210000900F550E96E0900F550EA6E0900090071",
":101220000900F550636F0900F550646F090009006B",
":10123000F6CF67F0F7CF68F0F8CF69F060C0F6FF3F",
":1012400061C0F7FF62C0F8FF0001635302E164531D",
":1012500007E00900F550EE6E6307F8E26407F9D77E",
":1012600067C0F6FF68C0F7FF69C0F8FF00016507B7",
":08127000000E665BBFD71200FF",
":0812780013EE00F023EE00F07C",
":10128000F86A059CEDEC08F051EC09F080EC08F0F0",
":04129000FBD7120076",
":0C12940000EE00F00F0EEE6AEA62FDD7DB",
":0212A00012003A",
":0212A200120038",
":00000001FF"};

void str2ram(static CHAR *dest, static CHAR rom *src)
{
	while ((*dest++ = *src++) != '\0');
}

CHAR* get_fake_hex_line()
{
	static CHAR line[30];
	str2ram(line, table[hexIndex++]);

	return line;
}
#endif
