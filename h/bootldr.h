#ifndef BOOTLDR_H
#define BOOTLDR_H

// BOOTLOADER INFORMATION


// PLATFORM SPECIFIC DETAILS
#define PROGRAM_BLOCK_SIZE_IN_BYTES     64
#define MAX_HEX_PAYLOAD_SIZE_IN_BYTES   32
#define ERASE_BLOCK_SIZE_IN_BYTES       1024
#define USER_PROGRAM_START_ADDRESS      0x8000UL
#define USER_PROGRAM_END_ADDRESS        0x1FFF7UL
#define NUM_BLOCKS_TO_ERASE             95

enum HexRecordType
{
    HR_DATA = 0,
    HR_EOF,
    HR_EXT_SEGMENT_ADDRESS,
    HR_START_SEGMENT_ADDRESS,
    HR_EXT_LINEAR_ADDRESS,
    HR_START_LINEAR_ADDRESS
};
typedef enum HexRecordType HexRecordType;


typedef struct bootldr bootldr;
struct bootldr
{
    // bootldr members
    char data_buffer[PROGRAM_BLOCK_SIZE_IN_BYTES];
    UINT08 numberOfBytesInBuffer;
    UINT24 currentAddress;
    UINT16 addressUpperWord;
};

typedef struct HexRecord HexRecord;
struct HexRecord
{
    UINT08 ByteCount;
    UINT24 Address;
    enum HexRecordType RecordType;
    char data[MAX_HEX_PAYLOAD_SIZE_IN_BYTES];
    BYTE Checksum;
};

// Bootloader function prototypes
void Bootldr_Initialize(void);
void Bootldr_Erase(void);
void Bootldr_Verify(void);
void Bootldr_Program(void);

#ifdef TEST
BOOL Bootldr_TestHarness(void);
#endif


// Supporting functions
void flash_commit(void);


// Platform specific functions that need to be implemented
void flash_erase(void);
void flash_read(ram char *buffer, UINT24 address, UINT08 numberOfBytesToRead);
void flash_write(ram char *buffer, UINT24 address, UINT08 numberOfBytesToWrite);
void read_record(HexRecord *record);
void open_source(void);
void close_source(void);
#endif