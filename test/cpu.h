// FILE:		cpu.h
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION: Processor specific datatypes should be defined here for
//              portablility reasons.

// LICENSE:		see main.c for license info
// CHANGELOG:
// MM-DD-YYYY
// 06-03-2011: initial version created.

#ifndef CPU_H
#define	CPU_H

typedef unsigned long long  UINT64;
typedef unsigned long       UINT32;
typedef unsigned short long UINT24;
typedef unsigned short      UINT16;
typedef unsigned char       UINT08;

// These types must be 8-bit
typedef unsigned char       BYTE;
typedef signed char 		CHAR;
typedef unsigned char       UCHAR;

// These types must be 16-bit
typedef short               SHORT;
typedef unsigned short	    USHORT;
typedef unsigned short	    WORD;
typedef unsigned short	    WCHAR;

/* These types must be 32-bit integer */
typedef long			    LONG;
typedef unsigned long	    ULONG;
typedef unsigned long	    DWORD;

typedef enum { FALSE = 0, TRUE } BOOL;

#endif	/* CPU_H */

