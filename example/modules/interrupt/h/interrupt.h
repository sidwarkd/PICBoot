// CUSTOMIZABLE SECTION

#define MAX_HIGH_INTERRUPT_HANDLERS 3
#define MAX_LOW_INTERRUPT_HANDLERS 3

// FIXED SECTION

typedef enum { LOW_PRIORITY = 0, HIGH_PRIORITY } INT_PRIORITY;

void EnableInterrupt(UINT08 interruptID, INT_PRIORITY priority, UINT08 options);
BOOL RegisterInterruptCallback(UINT08 interruptID, void *callbackFunction);
BOOL UnregisterInterruptCallback(UINT08 interruptID, void *callbackFunction);
void ProcessHighPriorityInterrupt();
void ProcessLowPriorityInterrupt();
void INTERRUPTS_Initialize();


// ID FOR EACH POSSIBLE INTERRUPTS
#define INTERRUPT_TIMER0    0
#define INTERRUPT_TIMER1    1
#define INTERRUPT_INT0      2      

typedef struct AppInterrupt AppInterrupt;
struct AppInterrupt
{
    UINT08 ID;
    void *CallbackFunctions[3];
    INT_PRIORITY Priority;
};

UINT08 NextLowInterruptIndex;
UINT08 NextHighInterruptIndex;

AppInterrupt RegisteredLowInterrupts[MAX_LOW_INTERRUPT_HANDLERS];
AppInterrupt RegisteredHighInterrupts[MAX_HIGH_INTERRUPT_HANDLERS];

