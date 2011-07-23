/*-------------------------------------------------------------------------
 * MPLAB-Cxx  PIC18F27J53 processor header
 *
 * (c) Copyright 1999-2010 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __18F27J53_H
#define __18F27J53_H

extern volatile far  unsigned char       ADCTRIG;
extern volatile far  union {
  struct {
    unsigned TRIGSEL:2;
  };
  struct {
    unsigned SRC0:1;
    unsigned SRC1:1;
  };
  struct {
    unsigned TRIGSEL0:1;
    unsigned TRIGSEL1:1;
  };
  struct {
    unsigned SRC:2;
  };
} ADCTRIGbits;
extern volatile far  unsigned char       PD0;
extern volatile far  union {
  struct {
    unsigned ADCMD:1;
    unsigned SPI1MD:1;
    unsigned SPI2MD:1;
    unsigned UART1MD:1;
    unsigned UART2MD:1;
    unsigned ECCP1MD:1;
    unsigned ECCP2MD:1;
    unsigned ECCP3MD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDMSSP1:1;
    unsigned PMDMSSP2:1;
    unsigned PMDUART1:1;
    unsigned PMDUART2:1;
    unsigned PMDECCP1:1;
    unsigned PMDECCP2:1;
    unsigned PMDECCP3:1;
  };
  struct {
    unsigned PMDADC:1;
    unsigned PMDMSSP:2;
    unsigned PMDUART:2;
    unsigned PMDECCP:3;
  };
  struct {
    unsigned :1;
    unsigned SPIMD:2;
    unsigned UARTMD:2;
    unsigned ECCPMD:3;
  };
} PD0bits;
extern volatile far  unsigned char       PMDIS0;
extern volatile far  union {
  struct {
    unsigned ADCMD:1;
    unsigned SPI1MD:1;
    unsigned SPI2MD:1;
    unsigned UART1MD:1;
    unsigned UART2MD:1;
    unsigned ECCP1MD:1;
    unsigned ECCP2MD:1;
    unsigned ECCP3MD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDMSSP1:1;
    unsigned PMDMSSP2:1;
    unsigned PMDUART1:1;
    unsigned PMDUART2:1;
    unsigned PMDECCP1:1;
    unsigned PMDECCP2:1;
    unsigned PMDECCP3:1;
  };
  struct {
    unsigned PMDADC:1;
    unsigned PMDMSSP:2;
    unsigned PMDUART:2;
    unsigned PMDECCP:3;
  };
  struct {
    unsigned :1;
    unsigned SPIMD:2;
    unsigned UARTMD:2;
    unsigned ECCPMD:3;
  };
} PMDIS0bits;
extern volatile far  unsigned char       PD1;
extern volatile far  union {
  struct {
    unsigned :1;
    unsigned TMR1MD:1;
    unsigned TMR2MD:1;
    unsigned TMR3MD:1;
    unsigned TMR4MD:1;
    unsigned RTCCMD:1;
    unsigned CTMUMD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDTMR1:1;
    unsigned PMDTMR2:1;
    unsigned PMDTMR3:1;
    unsigned PMDTMR4:1;
  };
  struct {
    unsigned :1;
    unsigned PMDTMR:4;
    unsigned PMDRTCC:1;
    unsigned PMDCTMU:1;
  };
  struct {
    unsigned :1;
    unsigned TMRMD:4;
  };
} PD1bits;
extern volatile far  unsigned char       PMDIS1;
extern volatile far  union {
  struct {
    unsigned :1;
    unsigned TMR1MD:1;
    unsigned TMR2MD:1;
    unsigned TMR3MD:1;
    unsigned TMR4MD:1;
    unsigned RTCCMD:1;
    unsigned CTMUMD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDTMR1:1;
    unsigned PMDTMR2:1;
    unsigned PMDTMR3:1;
    unsigned PMDTMR4:1;
  };
  struct {
    unsigned :1;
    unsigned PMDTMR:4;
    unsigned PMDRTCC:1;
    unsigned PMDCTMU:1;
  };
  struct {
    unsigned :1;
    unsigned TMRMD:4;
  };
} PMDIS1bits;
extern volatile far  unsigned char       PD2;
extern volatile far  union {
  struct {
    unsigned CMP1MD:1;
    unsigned CMP2MD:1;
    unsigned CMP3MD:1;
    unsigned TMR5MD:1;
    unsigned TMR6MD:1;
    unsigned :1;
    unsigned TMR8MD:1;
  };
  struct {
    unsigned PMDCMP1:1;
    unsigned PMDCMP2:1;
    unsigned PMDCMP3:1;
  };
  struct {
    unsigned PMDCMP:3;
    unsigned PMDTMR5:1;
    unsigned PMDTMR6:1;
    unsigned :1;
    unsigned PMDTMR8:1;
  };
  struct {
    unsigned CMPMD:3;
  };
} PD2bits;
extern volatile far  unsigned char       PMDIS2;
extern volatile far  union {
  struct {
    unsigned CMP1MD:1;
    unsigned CMP2MD:1;
    unsigned CMP3MD:1;
    unsigned TMR5MD:1;
    unsigned TMR6MD:1;
    unsigned :1;
    unsigned TMR8MD:1;
  };
  struct {
    unsigned PMDCMP1:1;
    unsigned PMDCMP2:1;
    unsigned PMDCMP3:1;
  };
  struct {
    unsigned PMDCMP:3;
    unsigned PMDTMR5:1;
    unsigned PMDTMR6:1;
    unsigned :1;
    unsigned PMDTMR8:1;
  };
  struct {
    unsigned CMPMD:3;
  };
} PMDIS2bits;
extern volatile far  unsigned char       PD3;
extern volatile far  union {
  struct {
    unsigned :1;
    unsigned CCP4MD:1;
    unsigned CCP5MD:1;
    unsigned CCP6MD:1;
    unsigned CCP7MD:1;
    unsigned CCP8MD:1;
    unsigned CCP9MD:1;
    unsigned CCP10MD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDCCP4:1;
    unsigned PMDCCP5:1;
    unsigned PMDCCP6:1;
    unsigned PMDCCP7:1;
    unsigned PMDCCP8:1;
    unsigned PMDCCP9:1;
    unsigned PMDCCP10:1;
  };
  struct {
    unsigned :1;
    unsigned PMDCCP:7;
  };
  struct {
    unsigned :1;
    unsigned CCPMD:7;
  };
} PD3bits;
extern volatile far  unsigned char       PMDIS3;
extern volatile far  union {
  struct {
    unsigned :1;
    unsigned CCP4MD:1;
    unsigned CCP5MD:1;
    unsigned CCP6MD:1;
    unsigned CCP7MD:1;
    unsigned CCP8MD:1;
    unsigned CCP9MD:1;
    unsigned CCP10MD:1;
  };
  struct {
    unsigned :1;
    unsigned PMDCCP4:1;
    unsigned PMDCCP5:1;
    unsigned PMDCCP6:1;
    unsigned PMDCCP7:1;
    unsigned PMDCCP8:1;
    unsigned PMDCCP9:1;
    unsigned PMDCCP10:1;
  };
  struct {
    unsigned :1;
    unsigned PMDCCP:7;
  };
  struct {
    unsigned :1;
    unsigned CCPMD:7;
  };
} PMDIS3bits;
extern volatile far  unsigned char       PPSCON;
extern volatile far  struct {
  unsigned IOLOCK:1;
} PPSCONbits;
extern volatile far  unsigned char       RPOR0;
extern volatile far  unsigned char       RPOR1;
extern volatile far  unsigned char       RPOR2;
extern volatile far  unsigned char       RPOR3;
extern volatile far  unsigned char       RPOR4;
extern volatile far  unsigned char       RPOR5;
extern volatile far  unsigned char       RPOR6;
extern volatile far  unsigned char       RPOR7;
extern volatile far  unsigned char       RPOR8;
extern volatile far  unsigned char       RPOR9;
extern volatile far  unsigned char       RPOR10;
extern volatile far  unsigned char       RPOR11;
extern volatile far  unsigned char       RPOR12;
extern volatile far  unsigned char       RPOR13;
extern volatile far  unsigned char       RPOR17;
extern volatile far  unsigned char       RPOR18;
extern volatile far  unsigned char       RPINR1;
extern volatile far  unsigned char       RPINR2;
extern volatile far  unsigned char       RPINR3;
extern volatile far  unsigned char       RPINR4;
extern volatile far  unsigned char       RPINR6;
extern volatile far  unsigned char       RPINR15;
extern volatile far  unsigned char       RPINR7;
extern volatile far  unsigned char       RPINR8;
extern volatile far  unsigned char       RPINR9;
extern volatile far  unsigned char       RPINR12;
extern volatile far  unsigned char       RPINR13;
extern volatile far  unsigned char       RPINR14;
extern volatile far  unsigned char       RPINR16;
extern volatile far  unsigned char       RPINR17;
extern volatile far  unsigned char       RPINR21;
extern volatile far  unsigned char       RPINR22;
extern volatile far  unsigned char       RPINR23;
extern volatile far  unsigned char       RPINR24;
extern volatile far  unsigned char       CCP10CON;
extern volatile far  union {
  struct {
    unsigned CCP10M:4;
    unsigned DC10B:2;
  };
  struct {
    unsigned CCP10M0:1;
    unsigned CCP10M1:1;
    unsigned CCP10M2:1;
    unsigned CCP10M3:1;
    unsigned DC10B0:1;
    unsigned DC10B1:1;
  };
} CCP10CONbits;
extern volatile far  unsigned char       CCPR10L;
extern volatile far  unsigned char       CCPR10H;
extern volatile far  unsigned char       CCP9CON;
extern volatile far  union {
  struct {
    unsigned CCP9M:4;
    unsigned DC9B:2;
  };
  struct {
    unsigned CCP9M0:1;
    unsigned CCP9M1:1;
    unsigned CCP9M2:1;
    unsigned CCP9M3:1;
    unsigned DC9B0:1;
    unsigned DC9B1:1;
  };
} CCP9CONbits;
extern volatile far  unsigned char       CCPR9L;
extern volatile far  unsigned char       CCPR9H;
extern volatile far  unsigned char       CCP8CON;
extern volatile far  union {
  struct {
    unsigned CCP8M:4;
    unsigned DC8B:2;
  };
  struct {
    unsigned CCP8M0:1;
    unsigned CCP8M1:1;
    unsigned CCP8M2:1;
    unsigned CCP8M3:1;
    unsigned DC8B0:1;
    unsigned DC8B1:1;
  };
} CCP8CONbits;
extern volatile far  unsigned char       CCPR8L;
extern volatile far  unsigned char       CCPR8H;
extern volatile far  unsigned char       CCP7CON;
extern volatile far  union {
  struct {
    unsigned CCP7M:4;
    unsigned DC7B:2;
  };
  struct {
    unsigned CCP7M0:1;
    unsigned CCP7M1:1;
    unsigned CCP7M2:1;
    unsigned CCP7M3:1;
    unsigned DC7B0:1;
    unsigned DC7B1:1;
  };
} CCP7CONbits;
extern volatile far  unsigned char       CCPR7L;
extern volatile far  unsigned char       CCPR7H;
extern volatile far  unsigned char       CCP6CON;
extern volatile far  union {
  struct {
    unsigned CCP6M:4;
    unsigned DC6B:2;
  };
  struct {
    unsigned CCP6M0:1;
    unsigned CCP6M1:1;
    unsigned CCP6M2:1;
    unsigned CCP6M3:1;
    unsigned DC6B0:1;
    unsigned DC6B1:1;
  };
} CCP6CONbits;
extern volatile far  unsigned char       CCPR6L;
extern volatile far  unsigned char       CCPR6H;
extern volatile far  unsigned char       CCP5CON;
extern volatile far  union {
  struct {
    unsigned CCP5M:4;
    unsigned DC5B:2;
  };
  struct {
    unsigned CCP5M0:1;
    unsigned CCP5M1:1;
    unsigned CCP5M2:1;
    unsigned CCP5M3:1;
    unsigned DC5B0:1;
    unsigned DC5B1:1;
  };
} CCP5CONbits;
extern volatile far  unsigned char       CCPR5L;
extern volatile far  unsigned char       CCPR5H;
extern volatile far  unsigned char       CCP4CON;
extern volatile far  union {
  struct {
    unsigned CCP4M:4;
    unsigned DC4B:2;
  };
  struct {
    unsigned CCP4M0:1;
    unsigned CCP4M1:1;
    unsigned CCP4M2:1;
    unsigned CCP4M3:1;
    unsigned DC4B0:1;
    unsigned DC4B1:1;
  };
} CCP4CONbits;
extern volatile far  unsigned char       CCPR4L;
extern volatile far  unsigned char       CCPR4H;
extern volatile far  unsigned char       CCP3CON;
extern volatile far  union {
  struct {
    unsigned CCP3M:4;
    unsigned DC3B:2;
    unsigned P3M:2;
  };
  struct {
    unsigned CCP3M0:1;
    unsigned CCP3M1:1;
    unsigned CCP3M2:1;
    unsigned CCP3M3:1;
    unsigned DC3B0:1;
    unsigned DC3B1:1;
    unsigned P3M0:1;
    unsigned P3M1:1;
  };
} CCP3CONbits;
extern volatile far  unsigned char       CCPR3L;
extern volatile far  unsigned char       CCPR3H;
extern volatile far  unsigned char       ECCP3DEL;
extern volatile far  union {
  struct {
    unsigned P3DC:7;
    unsigned P3RSEN:1;
  };
  struct {
    unsigned P3DC0:1;
    unsigned P3DC1:1;
    unsigned P3DC2:1;
    unsigned P3DC3:1;
    unsigned P3DC4:1;
    unsigned P3DC5:1;
    unsigned P3DC6:1;
  };
} ECCP3DELbits;
extern volatile far  unsigned char       ECCP3AS;
extern volatile far  union {
  struct {
    unsigned PSS3BD:2;
    unsigned PSS3AC:2;
    unsigned ECCP3AS:3;
    unsigned ECCP3ASE:1;
  };
  struct {
    unsigned PSS3BD0:1;
    unsigned PSS3BD1:1;
    unsigned PSS3AC0:1;
    unsigned PSS3AC1:1;
    unsigned ECCP3AS0:1;
    unsigned ECCP3AS1:1;
    unsigned ECCP3AS2:1;
  };
} ECCP3ASbits;
extern volatile far  unsigned char       PSTR3CON;
extern volatile far  union {
  struct {
    unsigned STRA:1;
    unsigned STRB:1;
    unsigned STRC:1;
    unsigned STRD:1;
    unsigned STRSYNC:1;
    unsigned :1;
    unsigned CMPL:2;
  };
  struct {
    unsigned :6;
    unsigned CMPL0:1;
    unsigned CMPL1:1;
  };
} PSTR3CONbits;
extern volatile far  unsigned char       T8CON;
extern volatile far  union {
  struct {
    unsigned T8CKPS:2;
    unsigned TMR8ON:1;
    unsigned T8OUTPS:4;
  };
  struct {
    unsigned T8CKPS0:1;
    unsigned T8CKPS1:1;
    unsigned :1;
    unsigned T8OUTPS0:1;
    unsigned T8OUTPS1:1;
    unsigned T8OUTPS2:1;
    unsigned T8OUTPS3:1;
  };
} T8CONbits;
extern volatile far  unsigned char       PR8;
extern volatile far  unsigned char       TMR8;
extern volatile far  unsigned char       T6CON;
extern volatile far  union {
  struct {
    unsigned T6CKPS:2;
    unsigned TMR6ON:1;
    unsigned T6OUTPS:4;
  };
  struct {
    unsigned T6CKPS0:1;
    unsigned T6CKPS1:1;
    unsigned :1;
    unsigned T6OUTPS0:1;
    unsigned T6OUTPS1:1;
    unsigned T6OUTPS2:1;
    unsigned T6OUTPS3:1;
  };
} T6CONbits;
extern volatile far  unsigned char       PR6;
extern volatile far  unsigned char       TMR6;
extern volatile far  unsigned char       T5GCON;
extern volatile far  union {
  struct {
    unsigned T5GSS:2;
    unsigned T5GVAL:1;
    unsigned T5GGO_NOT_T5DONE:1;
    unsigned T5GSPM:1;
    unsigned T5GTM:1;
    unsigned T5GPOL:1;
    unsigned TMR5GE:1;
  };
  struct {
    unsigned T5GSS0:1;
    unsigned T5GSS1:1;
    unsigned :1;
    unsigned T5GGO:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_T5DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T5DONE:1;
  };
} T5GCONbits;
extern volatile far  unsigned char       T5CON;
extern volatile far  union {
  struct {
    unsigned TMR5ON:1;
    unsigned RD16:1;
    unsigned NOT_T5SYNC:1;
    unsigned T5OSCEN:1;
    unsigned T5CKPS:2;
    unsigned TMR5CS:2;
  };
  struct {
    unsigned :4;
    unsigned T5CKPS0:1;
    unsigned T5CKPS1:1;
    unsigned TMR5CS0:1;
    unsigned TMR5CS1:1;
  };
} T5CONbits;
extern volatile far  unsigned char       TMR5L;
extern volatile far  unsigned char       TMR5H;
extern volatile far  unsigned char       CM3CON;
extern volatile far  union {
  struct {
    unsigned CCH:2;
    unsigned CREF:1;
    unsigned EVPOL:2;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
    unsigned :1;
    unsigned EVPOL0:1;
    unsigned EVPOL1:1;
  };
} CM3CONbits;
extern volatile far  unsigned char       UEP0;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP0bits;
extern volatile far  unsigned char       UEP1;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP1bits;
extern volatile far  unsigned char       UEP2;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP2bits;
extern volatile far  unsigned char       UEP3;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP3bits;
extern volatile far  unsigned char       UEP4;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP4bits;
extern volatile far  unsigned char       UEP5;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP5bits;
extern volatile far  unsigned char       UEP6;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP6bits;
extern volatile far  unsigned char       UEP7;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP7bits;
extern volatile far  unsigned char       UEP8;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP8bits;
extern volatile far  unsigned char       UEP9;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP9bits;
extern volatile far  unsigned char       UEP10;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP10bits;
extern volatile far  unsigned char       UEP11;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP11bits;
extern volatile far  unsigned char       UEP12;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP12bits;
extern volatile far  unsigned char       UEP13;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP13bits;
extern volatile far  unsigned char       UEP14;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP14bits;
extern volatile far  unsigned char       UEP15;
extern volatile far  struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP15bits;
extern volatile far  unsigned char       UIE;
extern volatile far  struct {
  unsigned URSTIE:1;
  unsigned UERRIE:1;
  unsigned ACTVIE:1;
  unsigned TRNIE:1;
  unsigned IDLEIE:1;
  unsigned STALLIE:1;
  unsigned SOFIE:1;
} UIEbits;
extern volatile far  unsigned char       UEIE;
extern volatile far  struct {
  unsigned PIDEE:1;
  unsigned CRC5EE:1;
  unsigned CRC16EE:1;
  unsigned DFN8EE:1;
  unsigned BTOEE:1;
  unsigned :2;
  unsigned BTSEE:1;
} UEIEbits;
extern volatile far  unsigned char       UADDR;
extern volatile far  union {
  struct {
    unsigned ADDR:7;
  };
  struct {
    unsigned ADDR0:1;
    unsigned ADDR1:1;
    unsigned ADDR2:1;
    unsigned ADDR3:1;
    unsigned ADDR4:1;
    unsigned ADDR5:1;
    unsigned ADDR6:1;
  };
} UADDRbits;
extern volatile far  unsigned char       UCFG;
extern volatile far  struct {
  unsigned PPB0:1;
  unsigned PPB1:1;
  unsigned FSEN:1;
  unsigned UTRDIS:1;
  unsigned UPUEN:1;
  unsigned :1;
  unsigned UOEMON:1;
  unsigned UTEYE:1;
} UCFGbits;
extern volatile far  unsigned char       RTCVALL;
extern volatile far  unsigned char       RTCVALH;
extern volatile far  unsigned char       PADCFG1;
extern volatile far  struct {
  unsigned :1;
  unsigned RTSECSEL0:1;
  unsigned RTSECSEL1:1;
} PADCFG1bits;
extern volatile far  unsigned char       REFOCON;
extern volatile far  union {
  struct {
    unsigned RODIV:4;
    unsigned ROSEL:1;
    unsigned ROSSLP:1;
    unsigned :1;
    unsigned ROON:1;
  };
  struct {
    unsigned RODIV0:1;
    unsigned RODIV1:1;
    unsigned RODIV2:1;
    unsigned RODIV3:1;
  };
} REFOCONbits;
extern volatile far  unsigned char       RTCCAL;
extern volatile far  union {
  struct {
    unsigned CAL:8;
  };
  struct {
    unsigned CAL0:1;
    unsigned CAL1:1;
    unsigned CAL2:1;
    unsigned CAL3:1;
    unsigned CAL4:1;
    unsigned CAL5:1;
    unsigned CAL6:1;
    unsigned CAL7:1;
  };
} RTCCALbits;
extern volatile far  unsigned char       RTCCFG;
extern volatile far  struct {
  unsigned RTCPTR0:1;
  unsigned RTCPTR1:1;
  unsigned RTCOE:1;
  unsigned HALFSEC:1;
  unsigned RTCSYNC:1;
  unsigned RTCWREN:1;
  unsigned :1;
  unsigned RTCEN:1;
} RTCCFGbits;
extern volatile far  unsigned char       ODCON3;
extern volatile far  struct {
  unsigned SPI1OD:1;
  unsigned SPI2OD:1;
} ODCON3bits;
extern volatile far  unsigned char       ODCON2;
extern volatile far  struct {
  unsigned U1OD:1;
  unsigned U2OD:1;
  unsigned CCP9OD:1;
  unsigned CCP10OD:1;
} ODCON2bits;
extern volatile far  unsigned char       ODCON1;
extern volatile far  struct {
  unsigned ECCP1OD:1;
  unsigned ECCP2OD:1;
  unsigned ECCP3OD:1;
  unsigned CCP4OD:1;
  unsigned CCP5OD:1;
  unsigned CCP6OD:1;
  unsigned CCP7OD:1;
  unsigned CCP8OD:1;
} ODCON1bits;
extern volatile far  unsigned char       ALRMVALL;
extern volatile far  unsigned char       ALRMVALH;
extern volatile far  unsigned char       ALRMRPT;
extern volatile far  union {
  struct {
    unsigned ARPT:8;
  };
  struct {
    unsigned ARPT0:1;
    unsigned ARPT1:1;
    unsigned ARPT2:1;
    unsigned ARPT3:1;
    unsigned ARPT4:1;
    unsigned ARPT5:1;
    unsigned ARPT6:1;
    unsigned ARPT7:1;
  };
} ALRMRPTbits;
extern volatile far  unsigned char       ALRMCFG;
extern volatile far  union {
  struct {
    unsigned ALRMPTR:2;
    unsigned AMASK:4;
    unsigned CHIME:1;
    unsigned ALRMEN:1;
  };
  struct {
    unsigned ALRMPTR0:1;
    unsigned ALRMPTR1:1;
    unsigned AMASK0:1;
    unsigned AMASK1:1;
    unsigned AMASK2:1;
    unsigned AMASK3:1;
  };
} ALRMCFGbits;
extern volatile far  unsigned char       ANCON0;
extern volatile far  struct {
  unsigned PCFG0:1;
  unsigned PCFG1:1;
  unsigned PCFG2:1;
  unsigned PCFG3:1;
  unsigned PCFG4:1;
} ANCON0bits;
extern volatile far  unsigned char       ANCON1;
extern volatile far  struct {
  unsigned PCFG8:1;
  unsigned PCFG9:1;
  unsigned PCFG10:1;
  unsigned PCFG11:1;
  unsigned PCFG12:1;
  unsigned :2;
  unsigned VBGEN:1;
} ANCON1bits;
extern volatile far  unsigned char       DSWAKEL;
extern volatile far  struct {
  unsigned DSPOR:1;
  unsigned :1;
  unsigned DSMCLR:1;
  unsigned DSRTC:1;
  unsigned DSWDT:1;
  unsigned DSULP:1;
  unsigned :1;
  unsigned DSFLT:1;
} DSWAKELbits;
extern volatile far  unsigned char       DSWAKEH;
extern volatile far  struct {
  unsigned DSINT0:1;
} DSWAKEHbits;
extern volatile far  unsigned char       DSCONL;
extern volatile far  struct {
  unsigned RELEASE:1;
  unsigned DSBOR:1;
  unsigned ULPWDIS:1;
} DSCONLbits;
extern volatile far  unsigned char       DSCONH;
extern volatile far  struct {
  unsigned RTCWDIS:1;
  unsigned DSULPEN:1;
  unsigned :5;
  unsigned DSEN:1;
} DSCONHbits;
extern volatile far  unsigned char       DSGPR0;
extern volatile far  unsigned char       DSGPR1;
extern volatile far  unsigned char       CCPTMRS2;
extern volatile far  union {
  struct {
    unsigned C8TSEL:2;
    unsigned C9TSEL0:1;
    unsigned :1;
    unsigned C10TSEL0:1;
  };
  struct {
    unsigned C8TSEL0:1;
    unsigned C8TSEL1:1;
  };
} CCPTMRS2bits;
extern volatile far  unsigned char       CCPTMRS1;
extern volatile far  union {
  struct {
    unsigned C4TSEL:2;
    unsigned C5TSEL0:1;
    unsigned :1;
    unsigned C6TSEL0:1;
    unsigned :1;
    unsigned C7TSEL:2;
  };
  struct {
    unsigned C4TSEL0:1;
    unsigned C4TSEL1:1;
    unsigned :4;
    unsigned C7TSEL0:1;
    unsigned C7TSEL1:1;
  };
} CCPTMRS1bits;
extern volatile far  unsigned char       CCPTMRS0;
extern volatile far  union {
  struct {
    unsigned C1TSEL:3;
    unsigned C2TSEL:3;
    unsigned C3TSEL:2;
  };
  struct {
    unsigned C1TSEL0:1;
    unsigned C1TSEL1:1;
    unsigned C1TSEL2:1;
    unsigned C2TSEL0:1;
    unsigned C2TSEL1:1;
    unsigned C2TSEL2:1;
    unsigned C3TSEL0:1;
    unsigned C3TSEL1:1;
  };
} CCPTMRS0bits;
extern volatile far  unsigned char       CVRCON;
extern volatile far  union {
  struct {
    unsigned CVR:4;
    unsigned CVRSS:1;
    unsigned CVRR:1;
    unsigned CVROE:1;
    unsigned CVREN:1;
  };
  struct {
    unsigned CVR0:1;
    unsigned CVR1:1;
    unsigned CVR2:1;
    unsigned CVR3:1;
  };
} CVRCONbits;
extern volatile near unsigned            UFRM;
extern volatile near unsigned char       UFRML;
extern volatile near union {
  struct {
    unsigned FRM:8;
  };
  struct {
    unsigned FRM0:1;
    unsigned FRM1:1;
    unsigned FRM2:1;
    unsigned FRM3:1;
    unsigned FRM4:1;
    unsigned FRM5:1;
    unsigned FRM6:1;
    unsigned FRM7:1;
  };
} UFRMLbits;
extern volatile near unsigned char       UFRMH;
extern volatile near union {
  struct {
    unsigned FRM:3;
  };
  struct {
    unsigned FRM8:1;
    unsigned FRM9:1;
    unsigned FRM10:1;
  };
} UFRMHbits;
extern volatile near unsigned char       UIR;
extern volatile near struct {
  unsigned URSTIF:1;
  unsigned UERRIF:1;
  unsigned ACTVIF:1;
  unsigned TRNIF:1;
  unsigned IDLEIF:1;
  unsigned STALLIF:1;
  unsigned SOFIF:1;
} UIRbits;
extern volatile near unsigned char       UEIR;
extern volatile near struct {
  unsigned PIDEF:1;
  unsigned CRC5EF:1;
  unsigned CRC16EF:1;
  unsigned DFN8EF:1;
  unsigned BTOEF:1;
  unsigned :2;
  unsigned BTSEF:1;
} UEIRbits;
extern volatile near unsigned char       USTAT;
extern volatile near union {
  struct {
    unsigned :1;
    unsigned PPBI:1;
    unsigned DIR:1;
    unsigned ENDP:4;
  };
  struct {
    unsigned :3;
    unsigned ENDP0:1;
    unsigned ENDP1:1;
    unsigned ENDP2:1;
    unsigned ENDP3:1;
  };
} USTATbits;
extern volatile near unsigned char       UCON;
extern volatile near struct {
  unsigned :1;
  unsigned SUSPND:1;
  unsigned RESUME:1;
  unsigned USBEN:1;
  unsigned PKTDIS:1;
  unsigned SE0:1;
  unsigned PPBRST:1;
} UCONbits;
extern volatile near unsigned char       DMABCH;
extern volatile near struct {
  unsigned DMACNTHB:2;
} DMABCHbits;
extern volatile near unsigned char       DMABCL;
extern volatile near unsigned char       RXADDRH;
extern volatile near struct {
  unsigned DMARCVPTRHB:4;
} RXADDRHbits;
extern volatile near unsigned char       RXADDRL;
extern volatile near unsigned char       TXADDRH;
extern volatile near struct {
  unsigned DMATXPTRHB:4;
} TXADDRHbits;
extern volatile near unsigned char       TXADDRL;
extern volatile near unsigned char       CMSTAT;
extern volatile near struct {
  unsigned COUT1:1;
  unsigned COUT2:1;
  unsigned COUT3:1;
} CMSTATbits;
extern volatile near unsigned char       CMSTATUS;
extern volatile near struct {
  unsigned COUT1:1;
  unsigned COUT2:1;
  unsigned COUT3:1;
} CMSTATUSbits;
extern volatile near unsigned char       SSP2CON2;
extern volatile near union {
  struct {
    unsigned SEN:1;
    unsigned RSEN:1;
    unsigned PEN:1;
    unsigned RCEN:1;
    unsigned ACKEN:1;
    unsigned ACKDT:1;
    unsigned ACKSTAT:1;
    unsigned GCEN:1;
  };
  struct {
    unsigned :1;
    unsigned ADMSK1:1;
    unsigned ADMSK2:1;
    unsigned ADMSK3:1;
    unsigned ADMSK4:1;
    unsigned ADMSK5:1;
  };
} SSP2CON2bits;
extern volatile near unsigned char       SSP2CON1;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSP2CON1bits;
extern volatile near unsigned char       SSP2STAT;
extern volatile near struct {
  unsigned BF:1;
  unsigned UA:1;
  unsigned R_NOT_W:1;
  unsigned S:1;
  unsigned P:1;
  unsigned D_NOT_A:1;
  unsigned CKE:1;
  unsigned SMP:1;
} SSP2STATbits;
extern volatile near unsigned char       SSP2ADD;
extern volatile near union {
  struct {
    unsigned SSPADD:8;
  };
  struct {
    unsigned MSK0:1;
    unsigned MSK1:1;
    unsigned MSK2:1;
    unsigned MSK3:1;
    unsigned MSK4:1;
    unsigned MSK5:1;
    unsigned MSK6:1;
    unsigned MSK7:1;
  };
} SSP2ADDbits;
extern volatile near unsigned char       SSP2BUF;
extern volatile near unsigned char       T4CON;
extern volatile near union {
  struct {
    unsigned T4CKPS:2;
    unsigned TMR4ON:1;
    unsigned T4OUTPS:4;
  };
  struct {
    unsigned T4CKPS0:1;
    unsigned T4CKPS1:1;
    unsigned :1;
    unsigned T4OUTPS0:1;
    unsigned T4OUTPS1:1;
    unsigned T4OUTPS2:1;
    unsigned T4OUTPS3:1;
  };
} T4CONbits;
extern volatile near unsigned char       PR4;
extern volatile near unsigned char       TMR4;
extern volatile near unsigned char       T3CON;
extern volatile near union {
  struct {
    unsigned TMR3ON:1;
    unsigned RD16:1;
    unsigned NOT_T3SYNC:1;
    unsigned T3OSCEN:1;
    unsigned T3CKPS:2;
    unsigned TMR3CS:2;
  };
  struct {
    unsigned :4;
    unsigned T3CKPS0:1;
    unsigned T3CKPS1:1;
    unsigned TMR3CS0:1;
    unsigned TMR3CS1:1;
  };
} T3CONbits;
extern volatile near unsigned char       TMR3L;
extern volatile near unsigned char       TMR3H;
extern volatile near unsigned char       BAUDCON2;
extern volatile near struct {
  unsigned ABDEN:1;
  unsigned WUE:1;
  unsigned :1;
  unsigned BRG16:1;
  unsigned TXCKP:1;
  unsigned RXDTP:1;
  unsigned RCIDL:1;
  unsigned ABDOVF:1;
} BAUDCON2bits;
extern volatile near unsigned char       SPBRGH2;
extern volatile near unsigned char       BAUDCON;
extern volatile near struct {
  unsigned ABDEN:1;
  unsigned WUE:1;
  unsigned :1;
  unsigned BRG16:1;
  unsigned TXCKP:1;
  unsigned RXDTP:1;
  unsigned RCIDL:1;
  unsigned ABDOVF:1;
} BAUDCONbits;
extern volatile near unsigned char       BAUDCON1;
extern volatile near struct {
  unsigned ABDEN:1;
  unsigned WUE:1;
  unsigned :1;
  unsigned BRG16:1;
  unsigned TXCKP:1;
  unsigned RXDTP:1;
  unsigned RCIDL:1;
  unsigned ABDOVF:1;
} BAUDCON1bits;
extern volatile near unsigned char       BAUDCTL;
extern volatile near struct {
  unsigned ABDEN:1;
  unsigned WUE:1;
  unsigned :1;
  unsigned BRG16:1;
  unsigned TXCKP:1;
  unsigned RXDTP:1;
  unsigned RCIDL:1;
  unsigned ABDOVF:1;
} BAUDCTLbits;
extern volatile near unsigned char       SPBRGH;
extern volatile near unsigned char       SPBRGH1;
extern volatile near unsigned char       PORTA;
extern volatile near union {
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned :1;
    unsigned RA5:1;
    unsigned RA6:1;
    unsigned RA7:1;
  };
  struct {
    unsigned AN0:1;
    unsigned AN1:1;
    unsigned AN2:1;
    unsigned AN3:1;
    unsigned :1;
    unsigned AN4:1;
    unsigned OSC2:1;
    unsigned OSC1:1;
  };
  struct {
    unsigned C1INA:1;
    unsigned C2INA:1;
    unsigned VREF_MINUS:1;
    unsigned VREF_PLUS:1;
    unsigned :1;
    unsigned NOT_SS1:1;
    unsigned CLKO:1;
    unsigned CLKI:1;
  };
  struct {
    unsigned :2;
    unsigned CVREF:1;
    unsigned C1INB:1;
    unsigned :1;
    unsigned HLVDIN:1;
  };
  struct {
    unsigned RP0:1;
    unsigned RP1:1;
    unsigned C2INB:1;
    unsigned :2;
    unsigned RCV:1;
  };
  struct {
    unsigned ULPWU:1;
    unsigned VBG:1;
    unsigned C1IND:1;
    unsigned :2;
    unsigned RP2:1;
  };
  struct {
    unsigned :2;
    unsigned C3INB:1;
    unsigned :2;
    unsigned C1INC:1;
  };
} PORTAbits;
extern volatile near unsigned char       PORTB;
extern volatile near union {
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
  struct {
    unsigned AN12:1;
    unsigned AN10:1;
    unsigned AN8:1;
    unsigned AN9:1;
    unsigned :2;
    unsigned KBI2:1;
    unsigned KBI3:1;
  };
  struct {
    unsigned INT0:1;
    unsigned :1;
    unsigned CTED1:1;
    unsigned CTED2:1;
    unsigned KBI0:1;
    unsigned KBI1:1;
    unsigned PGC:1;
    unsigned PGD:1;
  };
  struct {
    unsigned RP3:1;
    unsigned RTCC:1;
    unsigned :2;
    unsigned SCK1:1;
    unsigned SDI1:1;
    unsigned RP9:1;
    unsigned RP10:1;
  };
  struct {
    unsigned :1;
    unsigned RP4:1;
    unsigned VMO:1;
    unsigned VPO:1;
    unsigned SCL1:1;
    unsigned SDA1:1;
  };
  struct {
    unsigned :2;
    unsigned REFO:1;
    unsigned RP6:1;
    unsigned RP7:1;
    unsigned RP8:1;
  };
  struct {
    unsigned :1;
    unsigned C3INC:1;
    unsigned RP5:1;
    unsigned C3INA:1;
    unsigned CCP4:1;
    unsigned CCP5:1;
    unsigned CCP6:1;
    unsigned CCP7:1;
  };
  struct {
    unsigned C3IND:1;
    unsigned :1;
    unsigned C2INC:1;
  };
} PORTBbits;
extern volatile near unsigned char       PORTC;
extern volatile near union {
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned :1;
    unsigned RC4:1;
    unsigned RC5:1;
    unsigned RC6:1;
    unsigned RC7:1;
  };
  struct {
    unsigned T1OSO:1;
    unsigned T1OSI:1;
    unsigned AN11:1;
    unsigned :1;
    unsigned D_MINUS:1;
    unsigned D_PLUS:1;
  };
  struct {
    unsigned T1CKI:1;
    unsigned NOT_UOE:1;
    unsigned CTPLS:1;
    unsigned :1;
    unsigned VM:1;
    unsigned VP:1;
    unsigned TX1:1;
    unsigned RX1:1;
  };
  struct {
    unsigned RP11:1;
    unsigned RP12:1;
    unsigned RP13:1;
    unsigned :3;
    unsigned CK1:1;
    unsigned DT1:1;
  };
  struct {
    unsigned :6;
    unsigned RP17:1;
    unsigned SDO1:1;
  };
  struct {
    unsigned :2;
    unsigned C2IND:1;
    unsigned :4;
    unsigned RP18:1;
  };
  struct {
    unsigned :1;
    unsigned CCP8:1;
    unsigned :4;
    unsigned CCP9:1;
    unsigned CCP10:1;
  };
} PORTCbits;
extern volatile near unsigned char       HLVDCON;
extern volatile near union {
  struct {
    unsigned HLVDL:4;
    unsigned HLVDEN:1;
    unsigned IRVST:1;
    unsigned BGVST:1;
    unsigned VDIRMAG:1;
  };
  struct {
    unsigned HLVDL0:1;
    unsigned HLVDL1:1;
    unsigned HLVDL2:1;
    unsigned HLVDL3:1;
  };
} HLVDCONbits;
extern volatile near unsigned char       DMACON2;
extern volatile near union {
  struct {
    unsigned INTLVL:4;
    unsigned DLYCYC:4;
  };
  struct {
    unsigned INTLVL0:1;
    unsigned INTLVL1:1;
    unsigned INTLVL2:1;
    unsigned INTLVL3:1;
    unsigned DLYCYC0:1;
    unsigned DLYCYC1:1;
    unsigned DLYCYC2:1;
    unsigned DLYCYC3:1;
  };
} DMACON2bits;
extern volatile near unsigned char       OSCCON2;
extern volatile near struct {
  unsigned :2;
  unsigned PRISD:1;
  unsigned SOSCGO:1;
  unsigned SOSCDRV:1;
  unsigned :1;
  unsigned SOSCRUN:1;
} OSCCON2bits;
extern volatile near unsigned char       DMACON1;
extern volatile near struct {
  unsigned DMAEN:1;
  unsigned DLYINTEN:1;
  unsigned DUPLEX0:1;
  unsigned DUPLEX1:1;
  unsigned RXINC:1;
  unsigned TXINC:1;
  unsigned SSCON0:1;
  unsigned SSCON1:1;
} DMACON1bits;
extern volatile near unsigned char       LATA;
extern volatile near struct {
  unsigned LATA0:1;
  unsigned LATA1:1;
  unsigned LATA2:1;
  unsigned LATA3:1;
  unsigned :1;
  unsigned LATA5:1;
  unsigned LATA6:1;
  unsigned LATA7:1;
} LATAbits;
extern volatile near unsigned char       LATB;
extern volatile near struct {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
} LATBbits;
extern volatile near unsigned char       LATC;
extern volatile near struct {
  unsigned LATC0:1;
  unsigned LATC1:1;
  unsigned LATC2:1;
  unsigned :3;
  unsigned LATC6:1;
  unsigned LATC7:1;
} LATCbits;
extern volatile near unsigned char       PIE4;
extern volatile near struct {
  unsigned CCP3IE:1;
  unsigned CCP4IE:1;
  unsigned CCP5IE:1;
  unsigned CCP6IE:1;
  unsigned CCP7IE:1;
  unsigned CCP8IE:1;
  unsigned CCP9IE:1;
  unsigned CCP10IE:1;
} PIE4bits;
extern volatile near unsigned char       PIR4;
extern volatile near struct {
  unsigned CCP3IF:1;
  unsigned CCP4IF:1;
  unsigned CCP5IF:1;
  unsigned CCP6IF:1;
  unsigned CCP7IF:1;
  unsigned CCP8IF:1;
  unsigned CCP9IF:1;
  unsigned CCP10IF:1;
} PIR4bits;
extern volatile near unsigned char       IPR4;
extern volatile near struct {
  unsigned CCP3IP:1;
  unsigned CCP4IP:1;
  unsigned CCP5IP:1;
  unsigned CCP6IP:1;
  unsigned CCP7IP:1;
  unsigned CCP8IP:1;
  unsigned CCP9IP:1;
  unsigned CCP10IP:1;
} IPR4bits;
extern volatile near unsigned char       PIE5;
extern volatile near struct {
  unsigned TMR1GIE:1;
  unsigned TMR5GIE:1;
  unsigned TMR5IE:1;
  unsigned TMR6IE:1;
  unsigned TMR8IE:1;
  unsigned CM3IE:1;
} PIE5bits;
extern volatile near unsigned char       TRISA;
extern volatile near struct {
  unsigned TRISA0:1;
  unsigned TRISA1:1;
  unsigned TRISA2:1;
  unsigned TRISA3:1;
  unsigned :1;
  unsigned TRISA5:1;
  unsigned TRISA6:1;
  unsigned TRISA7:1;
} TRISAbits;
extern volatile near unsigned char       TRISB;
extern volatile near struct {
  unsigned TRISB0:1;
  unsigned TRISB1:1;
  unsigned TRISB2:1;
  unsigned TRISB3:1;
  unsigned TRISB4:1;
  unsigned TRISB5:1;
  unsigned TRISB6:1;
  unsigned TRISB7:1;
} TRISBbits;
extern volatile near unsigned char       TRISC;
extern volatile near struct {
  unsigned TRISC0:1;
  unsigned TRISC1:1;
  unsigned TRISC2:1;
  unsigned :3;
  unsigned TRISC6:1;
  unsigned TRISC7:1;
} TRISCbits;
extern volatile near unsigned char       T3GCON;
extern volatile near union {
  struct {
    unsigned T3GSS0:1;
    unsigned T3GSS1:1;
    unsigned T3GVAL:1;
    unsigned T3GGO_T3DONE:1;
    unsigned T3GSPM:1;
    unsigned T3GTM:1;
    unsigned T3GPOL:1;
    unsigned TMR3GE:1;
  };
  struct {
    unsigned :3;
    unsigned T3GGO:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_T3DONE:1;
  };
} T3GCONbits;
extern volatile near unsigned char       PIR5;
extern volatile near struct {
  unsigned TMR1GIF:1;
  unsigned TMR5GIF:1;
  unsigned TMR5IF:1;
  unsigned TMR6IF:1;
  unsigned TMR8IF:1;
  unsigned CM3IF:1;
} PIR5bits;
extern volatile near unsigned char       IPR5;
extern volatile near struct {
  unsigned TMR1GIP:1;
  unsigned TMR5GIP:1;
  unsigned TMR5IP:1;
  unsigned TMR6IP:1;
  unsigned TMR8IP:1;
  unsigned CM3IP:1;
} IPR5bits;
extern volatile near unsigned char       T1GCON;
extern volatile near union {
  struct {
    unsigned T1GSS0:1;
    unsigned T1GSS1:1;
    unsigned T1GVAL:1;
    unsigned T1GGO_NOT_T1DONE:1;
    unsigned T1GSPM:1;
    unsigned T1GTM:1;
    unsigned T1GPOL:1;
    unsigned TMR1GE:1;
  };
  struct {
    unsigned :3;
    unsigned T1GGO:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_T1DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T1DONE:1;
  };
} T1GCONbits;
extern volatile near unsigned char       OSCTUNE;
extern volatile near union {
  struct {
    unsigned TUN:6;
    unsigned PLLEN:1;
    unsigned INTSRC:1;
  };
  struct {
    unsigned TUN0:1;
    unsigned TUN1:1;
    unsigned TUN2:1;
    unsigned TUN3:1;
    unsigned TUN4:1;
    unsigned TUN5:1;
  };
} OSCTUNEbits;
extern volatile near unsigned char       RCSTA2;
extern volatile near struct {
  unsigned RX9D:1;
  unsigned OERR:1;
  unsigned FERR:1;
  unsigned ADDEN:1;
  unsigned CREN:1;
  unsigned SREN:1;
  unsigned RX9:1;
  unsigned SPEN:1;
} RCSTA2bits;
extern volatile near unsigned char       PIE1;
extern volatile near union {
  struct {
    unsigned TMR1IE:1;
    unsigned TMR2IE:1;
    unsigned CCP1IE:1;
    unsigned SSP1IE:1;
    unsigned TX1IE:1;
    unsigned RC1IE:1;
    unsigned ADIE:1;
  };
  struct {
    unsigned :3;
    unsigned SSPIE:1;
    unsigned TXIE:1;
    unsigned RCIE:1;
  };
} PIE1bits;
extern volatile near unsigned char       PIR1;
extern volatile near union {
  struct {
    unsigned TMR1IF:1;
    unsigned TMR2IF:1;
    unsigned CCP1IF:1;
    unsigned SSP1IF:1;
    unsigned TX1IF:1;
    unsigned RC1IF:1;
    unsigned ADIF:1;
  };
  struct {
    unsigned :3;
    unsigned SSPIF:1;
    unsigned TXIF:1;
    unsigned RCIF:1;
  };
} PIR1bits;
extern volatile near unsigned char       IPR1;
extern volatile near union {
  struct {
    unsigned TMR1IP:1;
    unsigned TMR2IP:1;
    unsigned CCP1IP:1;
    unsigned SSP1IP:1;
    unsigned TX1IP:1;
    unsigned RC1IP:1;
    unsigned ADIP:1;
  };
  struct {
    unsigned :3;
    unsigned SSPIP:1;
    unsigned TXIP:1;
    unsigned RCIP:1;
  };
} IPR1bits;
extern volatile near unsigned char       PIE2;
extern volatile near union {
  struct {
    unsigned CCP2IE:1;
    unsigned TMR3IE:1;
    unsigned LVDIE:1;
    unsigned BCL1IE:1;
    unsigned USBIE:1;
    unsigned CM1IE:1;
    unsigned CM2IE:1;
    unsigned OSCFIE:1;
  };
  struct {
    unsigned :2;
    unsigned HLVDIE:1;
    unsigned BCLIE:1;
  };
} PIE2bits;
extern volatile near unsigned char       PIR2;
extern volatile near union {
  struct {
    unsigned CCP2IF:1;
    unsigned TMR3IF:1;
    unsigned LVDIF:1;
    unsigned BCL1IF:1;
    unsigned USBIF:1;
    unsigned CM1IF:1;
    unsigned CM2IF:1;
    unsigned OSCFIF:1;
  };
  struct {
    unsigned :2;
    unsigned HLVDIF:1;
    unsigned BCLIF:1;
  };
} PIR2bits;
extern volatile near unsigned char       IPR2;
extern volatile near union {
  struct {
    unsigned CCP2IP:1;
    unsigned TMR3IP:1;
    unsigned LVDIP:1;
    unsigned BCL1IP:1;
    unsigned USBIP:1;
    unsigned CM1IP:1;
    unsigned CM2IP:1;
    unsigned OSCFIP:1;
  };
  struct {
    unsigned :2;
    unsigned HLVDIP:1;
    unsigned BCLIP:1;
  };
} IPR2bits;
extern volatile near unsigned char       PIE3;
extern volatile near struct {
  unsigned RTCCIE:1;
  unsigned TMR3GIE:1;
  unsigned CTMUIE:1;
  unsigned TMR4IE:1;
  unsigned TX2IE:1;
  unsigned RC2IE:1;
  unsigned BCL2IE:1;
  unsigned SSP2IE:1;
} PIE3bits;
extern volatile near unsigned char       PIR3;
extern volatile near struct {
  unsigned RTCCIF:1;
  unsigned TMR3GIF:1;
  unsigned CTMUIF:1;
  unsigned TMR4IF:1;
  unsigned TX2IF:1;
  unsigned RC2IF:1;
  unsigned BCL2IF:1;
  unsigned SSP2IF:1;
} PIR3bits;
extern volatile near unsigned char       IPR3;
extern volatile near struct {
  unsigned RTCCIP:1;
  unsigned TMR3GIP:1;
  unsigned CTMUIP:1;
  unsigned TMR4IP:1;
  unsigned TX2IP:1;
  unsigned RC2IP:1;
  unsigned BCL2IP:1;
  unsigned SSP2IP:1;
} IPR3bits;
extern volatile near unsigned char       EECON1;
extern volatile near struct {
  unsigned :1;
  unsigned WR:1;
  unsigned WREN:1;
  unsigned WRERR:1;
  unsigned FREE:1;
  unsigned WPROG:1;
} EECON1bits;
extern volatile near unsigned char       EECON2;
extern volatile near unsigned char       TXSTA2;
extern volatile near struct {
  unsigned TX9D:1;
  unsigned TRMT:1;
  unsigned BRGH:1;
  unsigned SENDB:1;
  unsigned SYNC:1;
  unsigned TXEN:1;
  unsigned TX9:1;
  unsigned CSRC:1;
} TXSTA2bits;
extern volatile near unsigned char       TXREG2;
extern volatile near unsigned char       RCREG2;
extern volatile near unsigned char       SPBRG2;
extern volatile near unsigned char       RCSTA;
extern volatile near union {
  struct {
    unsigned RX9D:1;
    unsigned OERR:1;
    unsigned FERR:1;
    unsigned ADDEN:1;
    unsigned CREN:1;
    unsigned SREN:1;
    unsigned RX9:1;
    unsigned SPEN:1;
  };
  struct {
    unsigned RCD8:1;
    unsigned :2;
    unsigned ADEN:1;
    unsigned :2;
    unsigned RC9:1;
  };
  struct {
    unsigned :6;
    unsigned NOT_RC8:1;
  };
  struct {
    unsigned :6;
    unsigned RC8_9:1;
  };
} RCSTAbits;
extern volatile near unsigned char       RCSTA1;
extern volatile near union {
  struct {
    unsigned RX9D:1;
    unsigned OERR:1;
    unsigned FERR:1;
    unsigned ADDEN:1;
    unsigned CREN:1;
    unsigned SREN:1;
    unsigned RX9:1;
    unsigned SPEN:1;
  };
  struct {
    unsigned RCD8:1;
    unsigned :2;
    unsigned ADEN:1;
    unsigned :2;
    unsigned RC9:1;
  };
  struct {
    unsigned :6;
    unsigned NOT_RC8:1;
  };
  struct {
    unsigned :6;
    unsigned RC8_9:1;
  };
} RCSTA1bits;
extern volatile near unsigned char       TXSTA;
extern volatile near union {
  struct {
    unsigned TX9D:1;
    unsigned TRMT:1;
    unsigned BRGH:1;
    unsigned SENDB:1;
    unsigned SYNC:1;
    unsigned TXEN:1;
    unsigned TX9:1;
    unsigned CSRC:1;
  };
  struct {
    unsigned TXD8:1;
    unsigned :5;
    unsigned TX8_9:1;
  };
  struct {
    unsigned :6;
    unsigned NOT_TX8:1;
  };
} TXSTAbits;
extern volatile near unsigned char       TXSTA1;
extern volatile near union {
  struct {
    unsigned TX9D:1;
    unsigned TRMT:1;
    unsigned BRGH:1;
    unsigned SENDB:1;
    unsigned SYNC:1;
    unsigned TXEN:1;
    unsigned TX9:1;
    unsigned CSRC:1;
  };
  struct {
    unsigned TXD8:1;
    unsigned :5;
    unsigned TX8_9:1;
  };
  struct {
    unsigned :6;
    unsigned NOT_TX8:1;
  };
} TXSTA1bits;
extern volatile near unsigned char       TXREG;
extern volatile near unsigned char       TXREG1;
extern volatile near unsigned char       RCREG;
extern volatile near unsigned char       RCREG1;
extern volatile near unsigned char       SPBRG;
extern volatile near unsigned char       SPBRG1;
extern volatile near unsigned char       CTMUICON;
extern volatile near union {
  struct {
    unsigned IRNG:2;
    unsigned ITRIM:6;
  };
  struct {
    unsigned IRNG0:1;
    unsigned IRNG1:1;
    unsigned ITRIM0:1;
    unsigned ITRIM1:1;
    unsigned ITRIM2:1;
    unsigned ITRIM3:1;
    unsigned ITRIM4:1;
    unsigned ITRIM5:1;
  };
} CTMUICONbits;
extern volatile near unsigned char       CTMUCONL;
extern volatile near struct {
  unsigned EDG1STAT:1;
  unsigned EDG2STAT:1;
  unsigned EDG1SEL0:1;
  unsigned EDG1SEL1:1;
  unsigned EDG1POL:1;
  unsigned EDG2SEL0:1;
  unsigned EDG2SEL1:1;
  unsigned EDG2POL:1;
} CTMUCONLbits;
extern volatile near unsigned char       CTMUCONH;
extern volatile near struct {
  unsigned CTTRIG:1;
  unsigned IDISSEN:1;
  unsigned EDGSEQEN:1;
  unsigned EDGEN:1;
  unsigned TGEN:1;
  unsigned CTMUSIDL:1;
  unsigned :1;
  unsigned CTMUEN:1;
} CTMUCONHbits;
extern volatile near unsigned char       CCP2CON;
extern volatile near union {
  struct {
    unsigned CCP2M:4;
    unsigned DC2B:2;
    unsigned P2M:2;
  };
  struct {
    unsigned CCP2M0:1;
    unsigned CCP2M1:1;
    unsigned CCP2M2:1;
    unsigned CCP2M3:1;
    unsigned DC2B0:1;
    unsigned DC2B1:1;
    unsigned P2M0:1;
    unsigned P2M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP2Y:1;
    unsigned CCP2X:1;
  };
} CCP2CONbits;
extern volatile near unsigned char       ECCP2CON;
extern volatile near union {
  struct {
    unsigned CCP2M:4;
    unsigned DC2B:2;
    unsigned P2M:2;
  };
  struct {
    unsigned CCP2M0:1;
    unsigned CCP2M1:1;
    unsigned CCP2M2:1;
    unsigned CCP2M3:1;
    unsigned DC2B0:1;
    unsigned DC2B1:1;
    unsigned P2M0:1;
    unsigned P2M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP2Y:1;
    unsigned CCP2X:1;
  };
} ECCP2CONbits;
extern volatile near unsigned            CCPR2;
extern volatile near unsigned char       CCPR2L;
extern volatile near unsigned char       CCPR2H;
extern volatile near unsigned char       ECCP2DEL;
extern volatile near union {
  struct {
    unsigned P2DC:7;
    unsigned P2RSEN:1;
  };
  struct {
    unsigned P2DC0:1;
    unsigned P2DC1:1;
    unsigned P2DC2:1;
    unsigned P2DC3:1;
    unsigned P2DC4:1;
    unsigned P2DC5:1;
    unsigned P2DC6:1;
  };
} ECCP2DELbits;
extern volatile near unsigned char       PWM2CON;
extern volatile near union {
  struct {
    unsigned P2DC:7;
    unsigned P2RSEN:1;
  };
  struct {
    unsigned P2DC0:1;
    unsigned P2DC1:1;
    unsigned P2DC2:1;
    unsigned P2DC3:1;
    unsigned P2DC4:1;
    unsigned P2DC5:1;
    unsigned P2DC6:1;
  };
} PWM2CONbits;
extern volatile near unsigned char       ECCP2AS;
extern volatile near union {
  struct {
    unsigned PSS2BD:2;
    unsigned PSS2AC:2;
    unsigned ECCP2AS:3;
    unsigned ECCP2ASE:1;
  };
  struct {
    unsigned PSS2BD0:1;
    unsigned PSS2BD1:1;
    unsigned PSS2AC0:1;
    unsigned PSS2AC1:1;
    unsigned ECCP2AS0:1;
    unsigned ECCP2AS1:1;
    unsigned ECCP2AS2:1;
  };
} ECCP2ASbits;
extern volatile near unsigned char       PSTR2CON;
extern volatile near union {
  struct {
    unsigned STRA:1;
    unsigned STRB:1;
    unsigned STRC:1;
    unsigned STRD:1;
    unsigned STRSYNC:1;
    unsigned :1;
    unsigned CMPL0:1;
    unsigned CMPL1:1;
  };
  struct {
    unsigned P2DC0:1;
    unsigned P2DC1:1;
    unsigned P2DC2:1;
    unsigned P2DC3:1;
    unsigned P2DC4:1;
    unsigned P2DC5:1;
    unsigned P2DC6:1;
  };
} PSTR2CONbits;
extern volatile near unsigned char       CCP1CON;
extern volatile near union {
  struct {
    unsigned CCP1M:4;
    unsigned DC1B:2;
    unsigned P1M:2;
  };
  struct {
    unsigned CCP1M0:1;
    unsigned CCP1M1:1;
    unsigned CCP1M2:1;
    unsigned CCP1M3:1;
    unsigned DC1B0:1;
    unsigned DC1B1:1;
    unsigned P1M0:1;
    unsigned P1M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP1Y:1;
    unsigned CCP1X:1;
  };
} CCP1CONbits;
extern volatile near unsigned char       ECCP1CON;
extern volatile near union {
  struct {
    unsigned CCP1M:4;
    unsigned DC1B:2;
    unsigned P1M:2;
  };
  struct {
    unsigned CCP1M0:1;
    unsigned CCP1M1:1;
    unsigned CCP1M2:1;
    unsigned CCP1M3:1;
    unsigned DC1B0:1;
    unsigned DC1B1:1;
    unsigned P1M0:1;
    unsigned P1M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP1Y:1;
    unsigned CCP1X:1;
  };
} ECCP1CONbits;
extern volatile near unsigned            CCPR1;
extern volatile near unsigned char       CCPR1L;
extern volatile near unsigned char       CCPR1H;
extern volatile near unsigned char       ECCP1DEL;
extern volatile near union {
  struct {
    unsigned P1DC:7;
    unsigned P1RSEN:1;
  };
  struct {
    unsigned P1DC0:1;
    unsigned P1DC1:1;
    unsigned P1DC2:1;
    unsigned P1DC3:1;
    unsigned P1DC4:1;
    unsigned P1DC5:1;
    unsigned P1DC6:1;
  };
} ECCP1DELbits;
extern volatile near unsigned char       PWM1CON;
extern volatile near union {
  struct {
    unsigned P1DC:7;
    unsigned P1RSEN:1;
  };
  struct {
    unsigned P1DC0:1;
    unsigned P1DC1:1;
    unsigned P1DC2:1;
    unsigned P1DC3:1;
    unsigned P1DC4:1;
    unsigned P1DC5:1;
    unsigned P1DC6:1;
  };
} PWM1CONbits;
extern volatile near unsigned char       ECCP1AS;
extern volatile near union {
  struct {
    unsigned PSS1BD:2;
    unsigned PSS1AC:2;
    unsigned ECCP1AS:3;
    unsigned ECCP1ASE:1;
  };
  struct {
    unsigned PSS1BD0:1;
    unsigned PSS1BD1:1;
    unsigned PSS1AC0:1;
    unsigned PSS1AC1:1;
    unsigned ECCP1AS0:1;
    unsigned ECCP1AS1:1;
    unsigned ECCP1AS2:1;
  };
} ECCP1ASbits;
extern volatile near unsigned char       PSTR1CON;
extern volatile near struct {
  unsigned STRA:1;
  unsigned STRB:1;
  unsigned STRC:1;
  unsigned STRD:1;
  unsigned STRSYNC:1;
  unsigned :1;
  unsigned CMPL0:1;
  unsigned CMPL1:1;
} PSTR1CONbits;
extern volatile near unsigned char       WDTCON;
extern volatile near union {
  struct {
    unsigned SWDTEN:1;
    unsigned ULPSINK:1;
    unsigned ULPEN:1;
    unsigned DS:1;
    unsigned VBGOE:1;
    unsigned ULPLVL:1;
    unsigned LVDSTAT:1;
    unsigned REGSLP:1;
  };
  struct {
    unsigned SWDTE:1;
  };
} WDTCONbits;
extern volatile near unsigned char       ADCON1;
extern volatile near union {
  struct {
    unsigned ADCS:3;
    unsigned ACQT:3;
    unsigned ADCAL:1;
    unsigned ADFM:1;
  };
  struct {
    unsigned ADCS0:1;
    unsigned ADCS1:1;
    unsigned ADCS2:1;
    unsigned ACQT0:1;
    unsigned ACQT1:1;
    unsigned ACQT2:1;
  };
} ADCON1bits;
extern volatile near unsigned char       ADCON0;
extern volatile near union {
  struct {
    unsigned ADON:1;
    unsigned GO_NOT_DONE:1;
    unsigned CHS:4;
    unsigned VCFG:2;
  };
  struct {
    unsigned :1;
    unsigned GO_DONE:1;
    unsigned CHS0:1;
    unsigned CHS1:1;
    unsigned CHS2:1;
    unsigned CHS3:1;
    unsigned VCFG0:1;
    unsigned VCFG1:1;
  };
  struct {
    unsigned :1;
    unsigned DONE:1;
  };
  struct {
    unsigned :1;
    unsigned GO:1;
  };
  struct {
    unsigned :1;
    unsigned NOT_DONE:1;
  };
} ADCON0bits;
extern volatile near unsigned            ADRES;
extern volatile near unsigned char       ADRESL;
extern volatile near unsigned char       ADRESH;
extern volatile near unsigned char       SSP1CON2;
extern volatile near union {
  struct {
    unsigned SEN:1;
    unsigned RSEN:1;
    unsigned PEN:1;
    unsigned RCEN:1;
    unsigned ACKEN:1;
    unsigned ACKDT:1;
    unsigned ACKSTAT:1;
    unsigned GCEN:1;
  };
  struct {
    unsigned :1;
    unsigned ADMSK1:1;
    unsigned ADMSK2:1;
    unsigned ADMSK3:1;
    unsigned ADMSK4:1;
    unsigned ADMSK5:1;
  };
} SSP1CON2bits;
extern volatile near unsigned char       SSPCON2;
extern volatile near union {
  struct {
    unsigned SEN:1;
    unsigned RSEN:1;
    unsigned PEN:1;
    unsigned RCEN:1;
    unsigned ACKEN:1;
    unsigned ACKDT:1;
    unsigned ACKSTAT:1;
    unsigned GCEN:1;
  };
  struct {
    unsigned :1;
    unsigned ADMSK1:1;
    unsigned ADMSK2:1;
    unsigned ADMSK3:1;
    unsigned ADMSK4:1;
    unsigned ADMSK5:1;
  };
} SSPCON2bits;
extern volatile near unsigned char       SSP1CON1;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSP1CON1bits;
extern volatile near unsigned char       SSPCON1;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSPCON1bits;
extern volatile near unsigned char       SSP1STAT;
extern volatile near union {
  struct {
    unsigned BF:1;
    unsigned UA:1;
    unsigned R_NOT_W:1;
    unsigned S:1;
    unsigned P:1;
    unsigned D_NOT_A:1;
    unsigned CKE:1;
    unsigned SMP:1;
  };
  struct {
    unsigned :2;
    unsigned R:1;
    unsigned :2;
    unsigned D:1;
  };
  struct {
    unsigned :2;
    unsigned R_W:1;
    unsigned :2;
    unsigned D_A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_W:1;
    unsigned :2;
    unsigned NOT_A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_WRITE:1;
    unsigned :2;
    unsigned NOT_ADDRESS:1;
  };
  struct {
    unsigned :2;
    unsigned READ_WRITE:1;
    unsigned :2;
    unsigned DATA_ADDRESS:1;
  };
  struct {
    unsigned :2;
    unsigned I2C_READ:1;
    unsigned I2C_START:1;
    unsigned I2C_STOP:1;
    unsigned I2C_DAT:1;
  };
} SSP1STATbits;
extern volatile near unsigned char       SSPSTAT;
extern volatile near union {
  struct {
    unsigned BF:1;
    unsigned UA:1;
    unsigned R_NOT_W:1;
    unsigned S:1;
    unsigned P:1;
    unsigned D_NOT_A:1;
    unsigned CKE:1;
    unsigned SMP:1;
  };
  struct {
    unsigned :2;
    unsigned R:1;
    unsigned :2;
    unsigned D:1;
  };
  struct {
    unsigned :2;
    unsigned R_W:1;
    unsigned :2;
    unsigned D_A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_W:1;
    unsigned :2;
    unsigned NOT_A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_WRITE:1;
    unsigned :2;
    unsigned NOT_ADDRESS:1;
  };
  struct {
    unsigned :2;
    unsigned READ_WRITE:1;
    unsigned :2;
    unsigned DATA_ADDRESS:1;
  };
  struct {
    unsigned :2;
    unsigned I2C_READ:1;
    unsigned I2C_START:1;
    unsigned I2C_STOP:1;
    unsigned I2C_DAT:1;
  };
} SSPSTATbits;
extern volatile near unsigned char       SSP1ADD;
extern volatile near union {
  struct {
    unsigned SSPADD:8;
  };
  struct {
    unsigned MSK0:1;
    unsigned MSK1:1;
    unsigned MSK2:1;
    unsigned MSK3:1;
    unsigned MSK4:1;
    unsigned MSK5:1;
    unsigned MSK6:1;
    unsigned MSK7:1;
  };
} SSP1ADDbits;
extern volatile near unsigned char       SSPADD;
extern volatile near union {
  struct {
    unsigned SSPADD:8;
  };
  struct {
    unsigned MSK0:1;
    unsigned MSK1:1;
    unsigned MSK2:1;
    unsigned MSK3:1;
    unsigned MSK4:1;
    unsigned MSK5:1;
    unsigned MSK6:1;
    unsigned MSK7:1;
  };
} SSPADDbits;
extern volatile near unsigned char       SSP1BUF;
extern volatile near unsigned char       SSPBUF;
extern volatile near unsigned char       T2CON;
extern volatile near union {
  struct {
    unsigned T2CKPS:2;
    unsigned TMR2ON:1;
    unsigned T2OUTPS:4;
  };
  struct {
    unsigned T2CKPS0:1;
    unsigned T2CKPS1:1;
    unsigned :1;
    unsigned T2OUTPS0:1;
    unsigned T2OUTPS1:1;
    unsigned T2OUTPS2:1;
    unsigned T2OUTPS3:1;
  };
} T2CONbits;
extern volatile near unsigned char       PR2;
extern volatile near unsigned char       TMR2;
extern volatile near unsigned char       T1CON;
extern volatile near union {
  struct {
    unsigned TMR1ON:1;
    unsigned RD16:1;
    unsigned NOT_T1SYNC:1;
    unsigned T1OSCEN:1;
    unsigned T1CKPS:2;
    unsigned TMR1CS:2;
  };
  struct {
    unsigned :4;
    unsigned T1CKPS0:1;
    unsigned T1CKPS1:1;
    unsigned TMR1CS0:1;
    unsigned TMR1CS1:1;
  };
} T1CONbits;
extern volatile near unsigned char       TMR1L;
extern volatile near unsigned char       TMR1H;
extern volatile near unsigned char       RCON;
extern volatile near union {
  struct {
    unsigned NOT_BOR:1;
    unsigned NOT_POR:1;
    unsigned NOT_PD:1;
    unsigned NOT_TO:1;
    unsigned NOT_RI:1;
    unsigned NOT_CM:1;
    unsigned :1;
    unsigned IPEN:1;
  };
  struct {
    unsigned BOR:1;
    unsigned POR:1;
    unsigned PD:1;
    unsigned TO:1;
    unsigned RI:1;
    unsigned CM:1;
  };
} RCONbits;
extern volatile near unsigned char       CM2CON;
extern volatile near union {
  struct {
    unsigned CCH:2;
    unsigned CREF:1;
    unsigned EVPOL:2;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
    unsigned :1;
    unsigned EVPOL0:1;
    unsigned EVPOL1:1;
  };
} CM2CONbits;
extern volatile near unsigned char       CM2CON1;
extern volatile near union {
  struct {
    unsigned CCH:2;
    unsigned CREF:1;
    unsigned EVPOL:2;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
    unsigned :1;
    unsigned EVPOL0:1;
    unsigned EVPOL1:1;
  };
} CM2CON1bits;
extern volatile near unsigned char       CM1CON;
extern volatile near union {
  struct {
    unsigned CCH:2;
    unsigned CREF:1;
    unsigned EVPOL:2;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
    unsigned :1;
    unsigned EVPOL0:1;
    unsigned EVPOL1:1;
  };
} CM1CONbits;
extern volatile near unsigned char       CM1CON1;
extern volatile near union {
  struct {
    unsigned CCH:2;
    unsigned CREF:1;
    unsigned EVPOL:2;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
    unsigned :1;
    unsigned EVPOL0:1;
    unsigned EVPOL1:1;
  };
} CM1CON1bits;
extern volatile near unsigned char       OSCCON;
extern volatile near union {
  struct {
    unsigned SCS:2;
    unsigned FLTS:1;
    unsigned OSTS:1;
    unsigned IRCF:3;
    unsigned IDLEN:1;
  };
  struct {
    unsigned SCS0:1;
    unsigned SCS1:1;
    unsigned :2;
    unsigned IRCF0:1;
    unsigned IRCF1:1;
    unsigned IRCF2:1;
  };
} OSCCONbits;
extern volatile near unsigned char       T0CON;
extern volatile near union {
  struct {
    unsigned T0PS:3;
    unsigned PSA:1;
    unsigned T0SE:1;
    unsigned T0CS:1;
    unsigned T08BIT:1;
    unsigned TMR0ON:1;
  };
  struct {
    unsigned T0PS0:1;
    unsigned T0PS1:1;
    unsigned T0PS2:1;
  };
} T0CONbits;
extern volatile near unsigned char       TMR0L;
extern volatile near unsigned char       TMR0H;
extern          near unsigned char       STATUS;
extern          near struct {
  unsigned C:1;
  unsigned DC:1;
  unsigned Z:1;
  unsigned OV:1;
  unsigned N:1;
} STATUSbits;
extern          near unsigned            FSR2;
extern          near unsigned char       FSR2L;
extern          near unsigned char       FSR2H;
extern volatile near unsigned char       PLUSW2;
extern volatile near unsigned char       PREINC2;
extern volatile near unsigned char       POSTDEC2;
extern volatile near unsigned char       POSTINC2;
extern          near unsigned char       INDF2;
extern          near unsigned char       BSR;
extern          near unsigned            FSR1;
extern          near unsigned char       FSR1L;
extern          near unsigned char       FSR1H;
extern volatile near unsigned char       PLUSW1;
extern volatile near unsigned char       PREINC1;
extern volatile near unsigned char       POSTDEC1;
extern volatile near unsigned char       POSTINC1;
extern          near unsigned char       INDF1;
extern          near unsigned char       WREG;
extern          near unsigned            FSR0;
extern          near unsigned char       FSR0L;
extern          near unsigned char       FSR0H;
extern volatile near unsigned char       PLUSW0;
extern volatile near unsigned char       PREINC0;
extern volatile near unsigned char       POSTDEC0;
extern volatile near unsigned char       POSTINC0;
extern          near unsigned char       INDF0;
extern volatile near unsigned char       INTCON3;
extern volatile near union {
  struct {
    unsigned INT1IF:1;
    unsigned INT2IF:1;
    unsigned INT3IF:1;
    unsigned INT1IE:1;
    unsigned INT2IE:1;
    unsigned INT3IE:1;
    unsigned INT1IP:1;
    unsigned INT2IP:1;
  };
  struct {
    unsigned INT1F:1;
    unsigned INT2F:1;
    unsigned INT3F:1;
    unsigned INT1E:1;
    unsigned INT2E:1;
    unsigned INT3E:1;
    unsigned INT1P:1;
    unsigned INT2P:1;
  };
} INTCON3bits;
extern volatile near unsigned char       INTCON2;
extern volatile near union {
  struct {
    unsigned RBIP:1;
    unsigned INT3IP:1;
    unsigned TMR0IP:1;
    unsigned INTEDG3:1;
    unsigned INTEDG2:1;
    unsigned INTEDG1:1;
    unsigned INTEDG0:1;
    unsigned NOT_RBPU:1;
  };
  struct {
    unsigned :1;
    unsigned INT3P:1;
    unsigned T0IP:1;
    unsigned :4;
    unsigned RBPU:1;
  };
} INTCON2bits;
extern volatile near unsigned char       INTCON;
extern volatile near union {
  struct {
    unsigned RBIF:1;
    unsigned INT0IF:1;
    unsigned TMR0IF:1;
    unsigned RBIE:1;
    unsigned INT0IE:1;
    unsigned TMR0IE:1;
    unsigned PEIE_GIEL:1;
    unsigned GIE_GIEH:1;
  };
  struct {
    unsigned :1;
    unsigned INT0F:1;
    unsigned T0IF:1;
    unsigned :1;
    unsigned INT0E:1;
    unsigned T0IE:1;
    unsigned PEIE:1;
    unsigned GIE:1;
  };
  struct {
    unsigned :6;
    unsigned GIEL:1;
    unsigned GIEH:1;
  };
} INTCONbits;
extern          near unsigned            PROD;
extern          near unsigned char       PRODL;
extern          near unsigned char       PRODH;
extern volatile near unsigned char       TABLAT;
extern volatile near unsigned short long TBLPTR;
extern volatile near unsigned char       TBLPTRL;
extern volatile near unsigned char       TBLPTRH;
extern volatile near unsigned char       TBLPTRU;
extern volatile near unsigned short long PC;
extern volatile near unsigned char       PCL;
extern volatile near unsigned char       PCLATH;
extern volatile near unsigned char       PCLATU;
extern volatile near unsigned char       STKPTR;
extern volatile near union {
  struct {
    unsigned STKPTR:5;
    unsigned :1;
    unsigned STKUNF:1;
    unsigned STKFUL:1;
  };
  struct {
    unsigned SP0:1;
    unsigned SP1:1;
    unsigned SP2:1;
    unsigned SP3:1;
    unsigned SP4:1;
    unsigned :2;
    unsigned STKOVF:1;
  };
} STKPTRbits;
extern          near unsigned short long TOS;
extern          near unsigned char       TOSL;
extern          near unsigned char       TOSH;
extern          near unsigned char       TOSU;

#pragma varlocate 14 ADCTRIG
#pragma varlocate 14 ADCTRIGbits
#pragma varlocate 14 PD0
#pragma varlocate 14 PD0bits
#pragma varlocate 14 PMDIS0
#pragma varlocate 14 PMDIS0bits
#pragma varlocate 14 PD1
#pragma varlocate 14 PD1bits
#pragma varlocate 14 PMDIS1
#pragma varlocate 14 PMDIS1bits
#pragma varlocate 14 PD2
#pragma varlocate 14 PD2bits
#pragma varlocate 14 PMDIS2
#pragma varlocate 14 PMDIS2bits
#pragma varlocate 14 PD3
#pragma varlocate 14 PD3bits
#pragma varlocate 14 PMDIS3
#pragma varlocate 14 PMDIS3bits
#pragma varlocate 14 PPSCON
#pragma varlocate 14 PPSCONbits
#pragma varlocate 14 RPOR0
#pragma varlocate 14 RPOR1
#pragma varlocate 14 RPOR2
#pragma varlocate 14 RPOR3
#pragma varlocate 14 RPOR4
#pragma varlocate 14 RPOR5
#pragma varlocate 14 RPOR6
#pragma varlocate 14 RPOR7
#pragma varlocate 14 RPOR8
#pragma varlocate 14 RPOR9
#pragma varlocate 14 RPOR10
#pragma varlocate 14 RPOR11
#pragma varlocate 14 RPOR12
#pragma varlocate 14 RPOR13
#pragma varlocate 14 RPOR17
#pragma varlocate 14 RPOR18
#pragma varlocate 14 RPINR1
#pragma varlocate 14 RPINR2
#pragma varlocate 14 RPINR3
#pragma varlocate 14 RPINR4
#pragma varlocate 14 RPINR6
#pragma varlocate 14 RPINR15
#pragma varlocate 14 RPINR7
#pragma varlocate 14 RPINR8
#pragma varlocate 14 RPINR9
#pragma varlocate 14 RPINR12
#pragma varlocate 14 RPINR13
#pragma varlocate 14 RPINR14
#pragma varlocate 14 RPINR16
#pragma varlocate 14 RPINR17
#pragma varlocate 14 RPINR21
#pragma varlocate 14 RPINR22
#pragma varlocate 14 RPINR23
#pragma varlocate 14 RPINR24
#pragma varlocate 15 CCP10CON
#pragma varlocate 15 CCP10CONbits
#pragma varlocate 15 CCPR10L
#pragma varlocate 15 CCPR10H
#pragma varlocate 15 CCP9CON
#pragma varlocate 15 CCP9CONbits
#pragma varlocate 15 CCPR9L
#pragma varlocate 15 CCPR9H
#pragma varlocate 15 CCP8CON
#pragma varlocate 15 CCP8CONbits
#pragma varlocate 15 CCPR8L
#pragma varlocate 15 CCPR8H
#pragma varlocate 15 CCP7CON
#pragma varlocate 15 CCP7CONbits
#pragma varlocate 15 CCPR7L
#pragma varlocate 15 CCPR7H
#pragma varlocate 15 CCP6CON
#pragma varlocate 15 CCP6CONbits
#pragma varlocate 15 CCPR6L
#pragma varlocate 15 CCPR6H
#pragma varlocate 15 CCP5CON
#pragma varlocate 15 CCP5CONbits
#pragma varlocate 15 CCPR5L
#pragma varlocate 15 CCPR5H
#pragma varlocate 15 CCP4CON
#pragma varlocate 15 CCP4CONbits
#pragma varlocate 15 CCPR4L
#pragma varlocate 15 CCPR4H
#pragma varlocate 15 CCP3CON
#pragma varlocate 15 CCP3CONbits
#pragma varlocate 15 CCPR3L
#pragma varlocate 15 CCPR3H
#pragma varlocate 15 ECCP3DEL
#pragma varlocate 15 ECCP3DELbits
#pragma varlocate 15 ECCP3AS
#pragma varlocate 15 ECCP3ASbits
#pragma varlocate 15 PSTR3CON
#pragma varlocate 15 PSTR3CONbits
#pragma varlocate 15 T8CON
#pragma varlocate 15 T8CONbits
#pragma varlocate 15 PR8
#pragma varlocate 15 TMR8
#pragma varlocate 15 T6CON
#pragma varlocate 15 T6CONbits
#pragma varlocate 15 PR6
#pragma varlocate 15 TMR6
#pragma varlocate 15 T5GCON
#pragma varlocate 15 T5GCONbits
#pragma varlocate 15 T5CON
#pragma varlocate 15 T5CONbits
#pragma varlocate 15 TMR5L
#pragma varlocate 15 TMR5H
#pragma varlocate 15 CM3CON
#pragma varlocate 15 CM3CONbits
#pragma varlocate 15 UEP0
#pragma varlocate 15 UEP0bits
#pragma varlocate 15 UEP1
#pragma varlocate 15 UEP1bits
#pragma varlocate 15 UEP2
#pragma varlocate 15 UEP2bits
#pragma varlocate 15 UEP3
#pragma varlocate 15 UEP3bits
#pragma varlocate 15 UEP4
#pragma varlocate 15 UEP4bits
#pragma varlocate 15 UEP5
#pragma varlocate 15 UEP5bits
#pragma varlocate 15 UEP6
#pragma varlocate 15 UEP6bits
#pragma varlocate 15 UEP7
#pragma varlocate 15 UEP7bits
#pragma varlocate 15 UEP8
#pragma varlocate 15 UEP8bits
#pragma varlocate 15 UEP9
#pragma varlocate 15 UEP9bits
#pragma varlocate 15 UEP10
#pragma varlocate 15 UEP10bits
#pragma varlocate 15 UEP11
#pragma varlocate 15 UEP11bits
#pragma varlocate 15 UEP12
#pragma varlocate 15 UEP12bits
#pragma varlocate 15 UEP13
#pragma varlocate 15 UEP13bits
#pragma varlocate 15 UEP14
#pragma varlocate 15 UEP14bits
#pragma varlocate 15 UEP15
#pragma varlocate 15 UEP15bits
#pragma varlocate 15 UIE
#pragma varlocate 15 UIEbits
#pragma varlocate 15 UEIE
#pragma varlocate 15 UEIEbits
#pragma varlocate 15 UADDR
#pragma varlocate 15 UADDRbits
#pragma varlocate 15 UCFG
#pragma varlocate 15 UCFGbits
#pragma varlocate 15 RTCVALL
#pragma varlocate 15 RTCVALH
#pragma varlocate 15 PADCFG1
#pragma varlocate 15 PADCFG1bits
#pragma varlocate 15 REFOCON
#pragma varlocate 15 REFOCONbits
#pragma varlocate 15 RTCCAL
#pragma varlocate 15 RTCCALbits
#pragma varlocate 15 RTCCFG
#pragma varlocate 15 RTCCFGbits
#pragma varlocate 15 ODCON3
#pragma varlocate 15 ODCON3bits
#pragma varlocate 15 ODCON2
#pragma varlocate 15 ODCON2bits
#pragma varlocate 15 ODCON1
#pragma varlocate 15 ODCON1bits
#pragma varlocate 15 ALRMVALL
#pragma varlocate 15 ALRMVALH
#pragma varlocate 15 ALRMRPT
#pragma varlocate 15 ALRMRPTbits
#pragma varlocate 15 ALRMCFG
#pragma varlocate 15 ALRMCFGbits
#pragma varlocate 15 ANCON0
#pragma varlocate 15 ANCON0bits
#pragma varlocate 15 ANCON1
#pragma varlocate 15 ANCON1bits
#pragma varlocate 15 DSWAKEL
#pragma varlocate 15 DSWAKELbits
#pragma varlocate 15 DSWAKEH
#pragma varlocate 15 DSWAKEHbits
#pragma varlocate 15 DSCONL
#pragma varlocate 15 DSCONLbits
#pragma varlocate 15 DSCONH
#pragma varlocate 15 DSCONHbits
#pragma varlocate 15 DSGPR0
#pragma varlocate 15 DSGPR1
#pragma varlocate 15 CCPTMRS2
#pragma varlocate 15 CCPTMRS2bits
#pragma varlocate 15 CCPTMRS1
#pragma varlocate 15 CCPTMRS1bits
#pragma varlocate 15 CCPTMRS0
#pragma varlocate 15 CCPTMRS0bits
#pragma varlocate 15 CVRCON
#pragma varlocate 15 CVRCONbits

/*-------------------------------------------------------------------------
 * Some useful defines for inline assembly stuff
 *-------------------------------------------------------------------------*/
#define ACCESS 0
#define BANKED 1

/*-------------------------------------------------------------------------
 * Some useful macros for inline assembly stuff
 *-------------------------------------------------------------------------*/
#define Nop()    {_asm nop _endasm}
#define ClrWdt() {_asm clrwdt _endasm}
#define Sleep()  {_asm sleep _endasm}
#define Reset()  {_asm reset _endasm}

#define Rlcf(f,dest,access)  {_asm movlb f rlcf f,dest,access _endasm}
#define Rlncf(f,dest,access) {_asm movlb f rlncf f,dest,access _endasm}
#define Rrcf(f,dest,access)  {_asm movlb f rrcf f,dest,access _endasm}
#define Rrncf(f,dest,access) {_asm movlb f rrncf f,dest,access _endasm}
#define Swapf(f,dest,access) {_asm movlb f swapf f,dest,access _endasm }

/*-------------------------------------------------------------------------
 * A fairly inclusive set of registers to save for interrupts.
 * These are locations which are commonly used by the compiler.
 *-------------------------------------------------------------------------*/
#define INTSAVELOCS TBLPTR, TABLAT, PROD


#endif
