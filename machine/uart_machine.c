/*******************************************************************************
 * File Name   : uart_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "uart_machine.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

uint8_t UART_ReadReceivedData(uint8_t* readChar)
{
    uint8_t noError;
    noError = 0;
    INTERRUPT_DisableReceive();
    if (!appData.uartRxBuffEmpty) {
        *readChar = appBuffers.uartReceive[appData.uartRxHeadIndex];
        noError = 1;
        appData.uartRxHeadIndex++;
        appData.uartRxHeadIndex &= (SERIAL_BUFFER_MAX_LENGTH-1);
        appData.uartRxBuffFull = 0;
        if (appData.uartRxHeadIndex == appData.uartRxTailIndex) appData.uartRxBuffEmpty = 1;
    }
    INTERRUPT_EnableReceive();

    return noError;
}

uint8_t UART_IsReceiveBufferEmpty()
{
    uint8_t buffEmpty;

    INTERRUPT_DisableReceive();
    buffEmpty = appData.uartRxBuffEmpty;
    INTERRUPT_EnableReceive();

    return buffEmpty;
}

uint8_t UART_TransmitBufferAppend(uint8_t* writeChar, uint16_t dataLength)
{
    uint8_t noError;
    uint16_t inpIdx;
    inpIdx = 0; noError = 0;
    while (!appData.uartTxBuffFull && inpIdx < dataLength) {
        appBuffers.uartTransmit[appData.uartTxTailIndex] = writeChar[inpIdx++];
        appData.uartTxTailIndex++;
        appData.uartTxTailIndex &= (SERIAL_TRANSMIT_MAX_LENGTH-1);
        appData.uartTxBuffEmpty = 0;
        if (appData.uartTxTailIndex == appData.uartTxHeadIndex) appData.uartTxBuffFull = 1;
    }
    if (inpIdx == dataLength) noError = 1;

    inpIdx = 0;
    if (U1STAHbits.UTXBE) {
        INTERRUPT_DisableTransmit();
        while (!appData.uartTxBuffEmpty && inpIdx < 8) {
            U1TXREG = appBuffers.uartTransmit[appData.uartTxHeadIndex];
            inpIdx++;
            appData.uartTxHeadIndex++;
            appData.uartTxHeadIndex &= (SERIAL_TRANSMIT_MAX_LENGTH-1);
            appData.uartTxBuffFull = 0;
            if (appData.uartTxHeadIndex == appData.uartTxTailIndex) appData.uartTxBuffEmpty = 1;
        }
        INTERRUPT_EnableTransmit();
    }

    return noError;
}

void UART_TransmitBufferHasData()
{
    uint16_t inpIdx;

    inpIdx = 0;
    if (U1STAHbits.UTXBE) {
        INTERRUPT_DisableTransmit();
        while (!appData.uartTxBuffEmpty && inpIdx < 8) {
            U1TXREG = appBuffers.uartTransmit[appData.uartTxHeadIndex];
            inpIdx++;
            appData.uartTxHeadIndex++;
            appData.uartTxHeadIndex &= (SERIAL_TRANSMIT_MAX_LENGTH-1);
            appData.uartTxBuffFull = 0;
            if (appData.uartTxHeadIndex == appData.uartTxTailIndex) appData.uartTxBuffEmpty = 1;
        }
        INTERRUPT_EnableTransmit();
    }
}

uint8_t UART_IsTransmitBufferEmpty()
{
    uint8_t buffEmpty;

    INTERRUPT_DisableTransmit();
    buffEmpty = appData.uartTxBuffEmpty;
    INTERRUPT_EnableTransmit();

    return buffEmpty;
}
