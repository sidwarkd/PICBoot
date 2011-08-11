// FILE:		app.h
// AUTHOR: 		Kevin Sidwar
// DESCRIPTION: Main header file for the PICBoot application.  Define
//              all application level items here.
//
// LICENSE:		see main.c for license info
// CHANGELOG:
// MM-DD-YYYY
// 06-03-2011: initial version created.

#ifndef APP_H
#define	APP_H

// FUNCTION PROTOTYPES
void HighPriorityISRCode(void);
void LowPriorityISRCode(void);
void InitializeApplication(void);

// GLOBAL DEFINES
#define ENABLE  1;
#define DISABLE 0;
#define OUTPUT_PIN  0;
#define INPUT_PIN   1;

#endif	/* APP_H */

