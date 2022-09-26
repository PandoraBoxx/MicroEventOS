/*******************************************************************************
 * File Name   : msim_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "msim_machine.h"
#include "timer_machine.h"
#include "event_process.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

/*******************************************************************************
 * Section: Function Entry Points
 ******************************************************************************/

void MSIM_WriteToSlave()
{
    /* The protocolA FIFO is empty, (mailbox write) */
    if(!MSI1MBXSbits.DTRDYA) {
        MSI1MBX0D = appBuffers.dataWrite.ProtocolA[0];
        MSI1MBX1D = appBuffers.dataWrite.ProtocolA[1];
        MSI1MBX2D = appBuffers.dataWrite.ProtocolA[2];
        MSI1MBX3D = appBuffers.dataWrite.ProtocolA[3];
        MSI1MBX4D = appBuffers.dataWrite.ProtocolA[4];  /* ProtocolA write finished (interrupt to slave) */
    } else {
        // ERROR;
    }
}

void MSIM_ReadFromSlave()
{
    /* We have data in the protocolB FIFO (mailbox read) */
    if(MSI1MBXSbits.DTRDYB) {
        appBuffers.dataRead.ProtocolB[0] = MSI1MBX5D;
        appBuffers.dataRead.ProtocolB[1] = MSI1MBX6D;
        appBuffers.dataRead.ProtocolB[2] = MSI1MBX7D;
        appBuffers.dataRead.ProtocolB[3] = MSI1MBX8D;
        // appBuffers.dataRead.ProtocolB[4] = MSI1MBX9D;  /* ProtocolB read finished (interrupt to slave) */
    } else {
        // ERROR;
    }
}

/* ********************************************************
   ********************************************************
uint8_t MSIM_ProtocolAIsFull()
{
    return (MSI1MBXSbits.DTRDYA);
}

uint8_t MSIM_ProtocolBIsEmpty()
{
    return (!MSI1MBXSbits.DTRDYB);
}

uint16_t MSIM_Read(uint16_t *pData, uint16_t wordCount)
{
    uint16_t readCountStatus;

    readCountStatus = 0;
    while(wordCount) {
        if(MSI1FIFOCSbits.RFEMPTY != 1) {
            *pData++ = MRSWFDATA;
            wordCount--;
            readCountStatus++;
        } else {
            break;
        }
    }
    return readCountStatus;   
}

uint16_t MSIM_Write(uint16_t *pData, uint16_t wordCount)
{
    uint16_t writeCountStatus;

    writeCountStatus = 0;
    while(wordCount) {
        if(MSI1FIFOCSbits.WFFULL != 1) {
            MWSRFDATA = *pData++;
            wordCount--;
            writeCountStatus++;
        } else {
            break;
        }
    }
    return writeCountStatus;
}

SLAVE_RESET_CAUSE MSIM_GetResetCause()
{
    SLAVE_RESET_CAUSE resetCause;
    
    if(MSI1STATbits.SLVWDRST)
    {
        resetCause = SLAVE_RESET_CAUSE_WATCHDOG;
    }
    else
    {
        resetCause = SLAVE_RESET_CAUSE_UNSPECIFIED;
    }
    
    return resetCause;
}

void MSIM_ResetCauseClear(SLAVE_RESET_CAUSE resetCause)
{
    switch(resetCause)
    {
        case SLAVE_RESET_CAUSE_WATCHDOG :   MSI1STATbits.SLVWDRST = 0;
                                            break;
        default                         :
                                            break;
    }
}

SLAVE_SYSTEM_STATUS MSIM_SystemStatusGet()
{
    SLAVE_SYSTEM_STATUS systemStatus = SLAVE_SYSTEM_STATUS_RUNNING;
    
    if(MSI1STATbits.SLVWDRST)
    {
        systemStatus = SLAVE_SYSTEM_STATUS_IN_RESET;
    }
    else
    {
        switch(MSI1STATbits.SLVPWR)
        {
            case 0: systemStatus = SLAVE_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE;
                    break;
            case 1: systemStatus = SLAVE_SYSTEM_STATUS_IDLE;
                    break;
            case 2: systemStatus = SLAVE_SYSTEM_STATUS_SLEEP;
                    break;
            default:systemStatus = SLAVE_SYSTEM_STATUS_RUNNING;
                    break;             
        }
    }
    return systemStatus;
}
*/
