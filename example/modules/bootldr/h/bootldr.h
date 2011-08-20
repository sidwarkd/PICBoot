#ifndef BOOTLDR_H
#define BOOTLDR_H

#ifdef BOOTLOADED_APP
#define PROGRAM_START_ADDRESS      0x8000UL
#define PROGRAM_END_ADDRESS        0x1FFF8UL
#define HIGH_INTERRUPT_ADDRESS     0x8008UL
#define LOW_INTERRUPT_ADDRESS      0x8018UL
#endif

// PLATFORM SPECIFIC DETAILS
#define PROGRAM_BLOCK_SIZE_IN_BYTES     64
#define MAX_HEX_PAYLOAD_SIZE_IN_BYTES   32
#define ERASE_BLOCK_SIZE_IN_BYTES       1024
#define USER_PROGRAM_START_ADDRESS      0x8000UL
#define USER_PROGRAM_END_ADDRESS        0x1FFF8UL
#define NUM_BLOCKS_TO_ERASE             95
#define BLOCK_ALIGN_CONSTANT            0xFFFFC0UL
#define USER_HIGH_INTERRUPT_ADDRESS     0x8008UL
#define USER_LOW_INTERRUPT_ADDRESS      0x8018UL

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


// ============================================================================
// BOOTLOADER STRUCTURE
//
// data_buffer - holds the data to be written to program memory
// start_address - the beginning address of the current block being programmed
// end_address - the ending address of the current block being programmed
// ============================================================================
typedef struct bootldr Bootloader;
struct bootldr
{
    char data_buffer[PROGRAM_BLOCK_SIZE_IN_BYTES];
    UINT24 start_address;
    UINT24 end_address;
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
BOOL Bootldr_Verify(void);
void Bootldr_Program(void);

#ifdef TEST
BOOL Bootldr_TestHarness(void);
#endif


// Supporting functions
void flash_commit(void);
void initialize_buffer_data(Bootloader *bootldr);
void mystrncpy(CHAR *dest, CHAR *src, UINT08 count);


// Platform specific functions that need to be implemented
void flash_erase(void);
void flash_read(ram char *buffer, UINT24 address, UINT08 numberOfBytesToRead);
void flash_write(ram char *buffer, UINT24 address, UINT08 numberOfBytesToWrite);
void read_record(HexRecord *record);
void open_source(void);
void close_source(void);

#endif
