/*******************************************************************************
 * File Name   : uart_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef UART_MACHINE_H
#define	UART_MACHINE_H

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : uint8_t UART_ReadReceivedData(uint8_t* readChar)
 *
 * Description  : Uart data reception.
 *
 * PreCondition : TBD
 *
 * Input        : one char buffer
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t UART_ReadReceivedData(uint8_t* readChar);

/*******************************************************************************
 * Function     : uint8_t UART_IsReceiveBufferEmpty()
 *
 * Description  : Uart buffer empty.
 *
 * PreCondition : TBD
 *
 * Input        : one char buffer
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t UART_IsReceiveBufferEmpty();

/*******************************************************************************
 * Function     : uint8_t UART_TransmitBufferAppend(uint8_t* writeChar, uint16_t dataLength)
 *
 * Description  : Uart append data for transmission.
 *
 * PreCondition : TBD
 *
 * Input        : data buffer and data length
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t UART_TransmitBufferAppend(uint8_t* writeChar, uint16_t dataLength);

/*******************************************************************************
 * Function     : void UART_TransmitBufferHasData()
 *
 * Description  : Uart transmission of last bytes.
 *
 * PreCondition : TBD
 *
 * Input        : none
 *
 * Output       : none
 ******************************************************************************/
void UART_TransmitBufferHasData();

/*******************************************************************************
 * Function     : uint8_t UART_IsTransmitBufferEmpty()
 *
 * Description  : Uart buffer empty check.
 *
 * PreCondition : TBD
 *
 * Input        : none
 *
 * Output       : emptiness
 ******************************************************************************/
uint8_t UART_IsTransmitBufferEmpty();

#endif	/* UART_MACHINE_H */
