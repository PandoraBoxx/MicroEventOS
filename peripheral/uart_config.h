/*******************************************************************************
 * File Name   : uart_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef UART_CONFIG_H
#define	UART_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void UART_HardwareConfig() 
 *
 * Description  : Initializes the processor's UARTs.
 *
 * PreCondition : None
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void UART_HardwareConfig();

/*******************************************************************************
 * Function     : void UART_HardwareEnable()
 *
 * Description  : This routine enables UART's hardware for run.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void UART_HardwareEnable();

/*******************************************************************************
 * Function     : void UART_RxTxQueueRestart()
 *
 * Description  : This routine restarts UART's Tx Rx buffers.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void UART_RxTxQueueRestart();

/*******************************************************************************
 * Function     : void UART_RxInterruptEnable()
 *
 * Description  : This routine enables UART's Rx interrupts.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void UART_RxInterruptEnable();

/*******************************************************************************
 * Function     : void UART_TxInterruptDisable()
 *
 * Description  : This routine disables UART's Tx interrupts.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void UART_TxInterruptDisable();

#endif	/* UART_CONFIG_H */

