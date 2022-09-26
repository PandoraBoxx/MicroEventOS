/*******************************************************************************
 * File Name   : system_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Master Configuration Bits
 ******************************************************************************/

/* FSEC: CODE PROTECTION REGISTER */
#pragma config AIVTDIS  = OFF       /* Alternate Interrupt Vector Table Disable */
#pragma config CSS      = DISABLED  /* Configuration Segment Code Flash Protection Level */
#pragma config CWRP     = OFF       /* Configuration Segment Write-Protect */
#pragma config GSS      = DISABLED  /* General Segment Code Flash Protection Level */
#pragma config GWRP     = OFF       /* General Segment Write-Protect */
#pragma config BSEN     = OFF       /* Boot Segment Control */
#pragma config BSS      = DISABLED  /* Boot Segment Code Flash Protection Level */
#pragma config BWRP     = OFF       /* Boot Segment Write-Protect */

/* FBSLIM: BOOT SEGMENT CONFIGURATION REGISTER */
//#pragma config BSLIM    = 0x000200  /* Boot Segment Code Flash Page Address Limit */

/* FOSCSEL: OSCILLATOR SELECTION CONFIGURATION REGISTER */
#pragma config IESO     = OFF       /* Internal External Switchover */
#pragma config FNOSC    = FRC       /* Initial Oscillator Source Selection */

/* FOSC: OSCILLATOR CONFIGURATION REGISTER */
#pragma config XTBST    = DISABLE   /* Oscillator Kick-Start Programmability */
#pragma config XTCFG    = G0        /* Crystal Oscillator Drive Select */
#pragma config FCKSM    = CSECMD    /* Clock Switching Mode */
#pragma config OSCIOFNC = ON        /* OSCO Pin Function */
#pragma config POSCMD   = NONE      /* Primary Oscillator Mode Select */

/* FWDT: WATCHDOG TIMER CONFIGURATION REGISTER */
#pragma config FWDTEN   = ON_SW     /* Watchdog Timer Enable */
#pragma config SWDTPS   = PS1048576 /* Sleep Mode Watchdog Timer Period Select */
#pragma config WDTWIN   = WIN75     /* Watchdog Timer Window Select */
#pragma config WINDIS   = ON        /* Watchdog Timer Window Disable */
#pragma config RCLKSEL  = LPRC      /* Watchdog Timer Clock Select */
#pragma config RWDTPS   = PS1048576 /* Run Mode Watchdog Timer Period Select */

/* FICD: IN-CIRCUIT DEBUGGER CONFIGURATION REGISTER */
#pragma config JTAGEN   = OFF       /* JTAG Enable */
#pragma config ICS      = PGD3      /* ICD Communication Channel Select */

/* FDMTIVTL: DEADMAN TIMER WINDOW LOW CONFIGURATION REGISTER */
#pragma config DMTIVTL  = 0         /* DMT Window Interval Lower 16b */

/* FDMTIVTH: DEADMAN TIMER WINDOW HIGH CONFIGURATION REGISTER */
#pragma config DMTIVTH  = 0         /* DMT Window Interval Higher 16b */

/* FDMTCNTL: DEADMAN TIMER INSTRUCTION COUNT LOW CONFIGURATION REGISTER */
#pragma config DMTCNTL  = 0         /* DMT Instruction Count Time-out Value Lower 16b */

/* FDMTCNTH: DEADMAN TIMER INSTRUCTION COUNT HIGH CONFIGURATION REGISTER */
#pragma config DMTCNTH  = 0         /* DMT Instruction Count Time-out Value Upper 16b */

/* FDMT: DEADMAN TIMER CONTROL CONFIGURATION REGISTER */
#pragma config DMTDIS   = OFF       /* DMT Disable */

/* FDEVOPT: SERIAL COMMUNICATIONS CONTROL CONFIGURATION REGISTER */
#pragma config SPI2PIN  = PPS       /* Master SPI #2 Fast I/O Pad Disable */
#pragma config SMBEN    = STANDARD  /* Select Input Voltage Threshold for I2C Pads to be SMBus 3.0 Compliant */
#pragma config ALTI2C2  = OFF       /* Alternate I2C2 Pin Mapping */
#pragma config ALTI2C1  = OFF       /* Alternate I2C1 Pin Mapping */

/* FALTREG: ALTERNATE REGISTERS CONFIGURATION REGISTER */
#pragma config CTXT4    = OFF       /* Specifies the Alternate Working Register Set #4 with Interrupt Priority Levels (IPL) */
#pragma config CTXT3    = OFF       /* Specifies the Alternate Working Register Set #3 with Interrupt Priority Levels (IPL) */
#pragma config CTXT2    = OFF       /* Specifies the Alternate Working Register Set #2 with Interrupt Priority Levels (IPL) */
#pragma config CTXT1    = OFF       /* Specifies the Alternate Working Register Set #1 with Interrupt Priority Levels (IPL) */

/*******************************************************************************
 * Section: Mailbox and Port Ownership Configuration Bits
 ******************************************************************************/

/* FMBXM: MAIL BOX CONFIGURATION REGISTER */
#pragma config MBXM0    = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM1    = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM2    = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM3    = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM4    = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM5    = S2M       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM6    = S2M       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM7    = S2M       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM8    = S2M       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM9    = S2M       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM10   = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM11   = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM12   = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM13   = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM14   = M2S       /* Mailbox Data Register Channel Direction Fuses */
#pragma config MBXM15   = M2S       /* Mailbox Data Register Channel Direction Fuses */

/* FMBXHS1: MAIL BOX PROTOCOL CONFIGURATION REGISTER */
#pragma config MBXHSD   = MBX15     /* Mailbox Handshake Protocol Block D Register Assignment */
#pragma config MBXHSC   = MBX15     /* Mailbox Handshake Protocol Block C Register Assignment */
#pragma config MBXHSB   = MBX9      /* Mailbox Handshake Protocol Block B Register Assignment */
#pragma config MBXHSA   = MBX4      /* Mailbox Handshake Protocol Block A Register Assignment */

/* FMBXHS2: MAIL BOX PROTOCOL CONFIGURATION REGISTER */
#pragma config MBXHSH   = MBX15     /* Mailbox Handshake Protocol Block D Register Assignment */
#pragma config MBXHSG   = MBX15     /* Mailbox Handshake Protocol Block C Register Assignment */
#pragma config MBXHSF   = MBX15     /* Mailbox Handshake Protocol Block B Register Assignment */
#pragma config MBXHSE   = MBX15     /* Mailbox Handshake Protocol Block A Register Assignment */

/* FMBXHSEN: MAIL BOX PROTOCOL ENABLE CONFIGURATION REGISTER */
#pragma config HSAEN    = ON       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSBEN    = ON       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSCEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSDEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSEEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSFEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSGEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */
#pragma config HSHEN    = OFF       /* Mailbox Data Flow Control Protocol Block Enable */

/* FCFGPRA0: PORT A OWNERSHIP CONFIGURATION REGISTER */
#pragma config CPRA0    = MSTR      /* Configure PORTA Ownership */
#pragma config CPRA1    = SLV1      /* Configure PORTA Ownership */
#pragma config CPRA2    = SLV1      /* Configure PORTA Ownership */
#pragma config CPRA3    = MSTR      /* Configure PORTA Ownership */
#pragma config CPRA4    = MSTR      /* Configure PORTA Ownership */

/* FCFGPRB0: PORT B OWNERSHIP CONFIGURATION REGISTER */
#pragma config CPRB0    = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB1    = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB2    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB3    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB4    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB5    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB6    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB7    = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB8    = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB9    = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB10   = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB11   = SLV1      /* Configure PORTB Ownership */
#pragma config CPRB12   = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB13   = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB14   = MSTR      /* Configure PORTB Ownership */
#pragma config CPRB15   = MSTR      /* Configure PORTB Ownership */

/*******************************************************************************
 * Section: Slave Configuration Bits
 ******************************************************************************/

/* FS1OSCSEL: OSCILLATOR SELECTION CONFIGURATION REGISTER (SLAVE) */
#pragma config S1IESO     = OFF	      /* Start with user-selected oscillator           */
#pragma config S1FNOSC    = FRC	      /* Internal Fast RC (FRC)                        */

/* FS1OSC: OSCILLATOR CONFIGURATION REGISTER (SLAVE) */
#pragma config S1FCKSM    = CSECMD    /* Clock switching enabled,Fail-safe disabled    */
#pragma config S1OSCIOFNC = ON	      /* OSC2 is general purpose I/O pin               */
#pragma config S1PLLKEN   = S1PLLKEN_ON /* S1PLLKEN->S1PLLKEN_ON                       */

/* FS1WDT WATCHDOG TIMER CONFIGURATION REGISTER (SLAVE) */
#pragma config S1FWDTEN   = ON_SW     /* WDT controlled via WDTCON.ON bit              */
#pragma config S1SWDTPS   = PS1048576 /* Sleep Mode Watchdog Timer Period Select       */
#pragma config S1WDTWIN   = WIN75     /* WDT Window is 75% of WDT period               */
#pragma config S1WINDIS   = ON        /* Watchdog Timer does't operate Window mode     */
#pragma config S1RCLKSEL  = LPRC      /* Always use LPRC                               */
#pragma config S1RWDTPS   = PS1048576 /* Run Mode Watchdog Timer Period Select         */

/* FS1ICD: IN-CIRCUIT DEBUGGER CONFIGURATION REGISTER (SLAVE) */
#pragma config S1ICS      = PGD3      /* Communicate on PGC3 and PGD3                  */
#pragma config S1ISOLAT   = OFF       /* The slave needs SLVEN bit to be set           */
#pragma config S1NOBTSWP  = OFF       /* BOOTSWP instruction is disabled               */

/* FS1DEVOPT: SERIAL COMMUNICATIONS CONTROL CONFIGURATION REGISTER (SLAVE) */
#pragma config S1ALTI2C1  = OFF       /* I2C1 mapped to SDA1/SCL1 pins                 */
#pragma config S1SPI1PIN  = PPS       /* Slave SPI1 uses I/O remap (PPS) pins          */
#pragma config S1SSRE     = ON        /* Slave resets reset Slave Enable of MSI module */
#pragma config S1MSRE     = ON        /* Master RESET events cause the slave to reset  */

/* FS1ALTREG: ALTERNATE REGISTERS CONFIGURATION REGISTER (SLAVE) */
#pragma config S1CTXT1    = OFF       /* Not Assigned                                  */
#pragma config S1CTXT2    = OFF       /* Not Assigned                                  */
#pragma config S1CTXT3    = OFF       /* Not Assigned                                  */
#pragma config S1CTXT4    = OFF       /* Not Assigned                                  */
