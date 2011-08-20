// Define all application level items here.

#ifndef APP_H
#define	APP_H

#define PRODUCTION
//#define TEST

#define BOOTLOADED_APP

// FUNCTION PROTOTYPES
void ProcessHighPriorityInterrupt(void);
void ProcessLowPriorityInterrupt(void);
void InitializeApplication(void);

#define ENABLE 1
#define DISABLE 0

#endif	/* APP_H */

