// FILE:		cpu.h
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION:         Processor specific datatypes should be defined here for
//                      portablility reasons.

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

typedef unsigned char       BYTE;
typedef unsigned char       BOOL;

typedef char				CHAR;

#define TRUE    1;
#define FALSE   0;
#define ENABLE  1;
#define DISABLE 0;

#endif	/* CPU_H */

