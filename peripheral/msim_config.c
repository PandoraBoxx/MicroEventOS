/*******************************************************************************
 * File Name   : msim_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "msim_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void MSIM_HardwareConfig()
{
    MSI1CONbits.MTSIRQ  = 0; /* Master not issued Slave interrupt request       */
    MSI1CONbits.RFITSEL = 0b00; /* Data valid interrupt on 1st FIFO written by Slave */
    MSI1CONbits.SLVEN   = 0; /* Slave processor is disabled and held in Reset   */
    MSI1CONbits.SRSTIE  = 0; /* Reset interrupt doesn't occur when Slave Resets */
    MSI1CONbits.STMIACK = 0; /* Master has not yet Acknowledged Slave           */

    /* MSI1STATbits.MTSIACK  Not used (Acknowledge Status bit (Slave ACK)       */
    /* MSI1STATbits.SLVP2ACT Not used (Slave PRAM Panel 2 Active Status)        */
    /* MSI1STATbits.SLVPWR   Not used (Slave Low-Power Operating Mode Status)   */
    /* MSI1STATbits.SLVRST   Not used (Slave Reset Status)                      */
    /* MSI1STATbits.SLVWDRST Not used (Slave Watchdog Timer (WDT) Reset Status) */
    /* MSI1STATbits.STMIRQ   Not used (Slave to Master Interrupt Req Status)    */
    /* MSI1STATbits.VERFERR  Not used (PRAM Verify Error Status)                */
    
    /* MSI1KEYbits.MSI1KEY   Not used (MSI1 Master Interlock Key)               */

    /* MSI1MBXSbits.DTRDYA   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYB   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYC   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYD   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYE   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYF   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYG   Not used (Data Ready Status on MSI1MBXnD)          */
    /* MSI1MBXSbits.DTRDYH   Not used (Data Ready Status on MSI1MBXnD)          */
    
    /* MSI1MBXnD             Not used (MSI1 Master Mailbox n Data Register)     */

    MSI1FIFOCSbits.RFEMPTY = 0; /* Read FIFO has data not yet read by Master    */
    MSI1FIFOCSbits.RFFULL  = 0; /* Read FIFO is not full                        */
    MSI1FIFOCSbits.RFOF    = 0; /* No Read FIFO overflow is detected            */
    MSI1FIFOCSbits.RFUF    = 0; /* No Read FIFO underflow is detected           */
    MSI1FIFOCSbits.WFEMPTY = 0; /* Write FIFO has data not yet read by Slave    */
    MSI1FIFOCSbits.WFFULL  = 0; /* Write FIFO is not full                       */
    MSI1FIFOCSbits.WFOF    = 0; /* No Write FIFO overflow is detected           */
    MSI1FIFOCSbits.WFUF    = 0; /* No Write FIFO underflow is detected          */
    
    /* MRSWFDATA        Not used (Master Read (Slave Write) FIFO Data Register) */
    /* MWSRFDATA        Not used (Master Write (Slave Read) FIFO Data Register) */
}

void MSIM_HardwareEnable()
{
    MSI1FIFOCSbits.RFEN = 1; /* Enables (Master) Read FIFO                      */
    MSI1FIFOCSbits.WFEN = 1; /* Enables (Master) Write FIFO                     */
}

void MSIM_InterruptEnable()
{
    IPC32bits.MSIS1IP = 4;      /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIS1IF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIS1IE  = 1;      /* Enable MSIM interrupt */

    IPC32bits.MSIAIP = 4;       /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIS1IF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIAIE  = 1;       /* Enable MSIM interrupt */

    IPC32bits.MSIBIP = 4;       /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIS1IF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIBIE  = 1;       /* Enable MSIM interrupt */
}
