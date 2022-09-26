/*******************************************************************************
 * File Name   : uart_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "uart_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void UART_HardwareConfig()
{
    U1MODEbits.ABAUD  = 0; /* Baud rate measurement is disabled                 */
    U1MODEbits.BRGH   = 1; /* High Speed: Baud rate is baudclk/4                */
    U1MODEbits.BRKOVR = 0; /* TX line is driven by the shifter                  */
    U1MODEbits.MOD    = 0b0000; /* Asynchronous 8-bit UART                      */
    U1MODEbits.RXBIMD = 0; /* RXBKIF flag when the Break makes a transition     */
    U1MODEbits.USIDL  = 1; /* Discontinues module operation on idle mode        */
    U1MODEbits.UTXBRK = 0; /* Sync Break transmission is disabled               */
    U1MODEbits.WAKE   = 0; /* RX pin is not monitored nor edge detected         */

    U1MODEHbits.BCLKMOD  = 1; /* Uses fractional Baud Rate Generation           */
    U1MODEHbits.BCLKSEL  = 0b10; /* FOSC                                        */
    U1MODEHbits.C0EN     = 0; /* legacy LIN checksum in LIN mode;               */
    U1MODEHbits.FLO      = 0; /* Flow control off                               */
    U1MODEHbits.HALFDPLX = 0; /* Full-Duplex mode: UxTX is driven at all times  */
    U1MODEHbits.RUNOVF   = 1; /* RX shifter continues to run on OERR condition  */
    U1MODEHbits.SLPEN    = 0; /* UART BRG clock is turned off during Sleep      */
    U1MODEHbits.STSEL    = 0b00; /* 1 Stop bit sent, 1 checked at receive       */
    U1MODEHbits.URXINV   = 0; /* Input is not inverted; Idle state is high      */
    U1MODEHbits.UTXINV   = 0; /* Output is not inverted; Idle state is high     */
//    U1MODEHbits.ACTIVE;

    U1STAbits.ABDOVE = 0; /* Auto-baud rate acquisition interrupt disable       */
    U1STAbits.CERIE  = 0; /* Checksum error interrupt disable                   */
    U1STAbits.FERIE  = 0; /* Framing error interrupt disable                    */
    U1STAbits.OERIE  = 0; /* Receive buffer overflow interrupt disable          */
    U1STAbits.PERIE  = 0; /* Parity error interrupt disable                     */
    U1STAbits.RXBKIE = 0; /* Receive break interrupt disable                    */
    U1STAbits.TXCIE  = 0; /* Transmit collision interrupt disable               */
    U1STAbits.TXMTIE = 0; /* Transmit shifter empty interrupt disable           */
//    U1STAbits.ABDOVF;
//    U1STAbits.CERIF;
//    U1STAbits.FERR;
//    U1STAbits.OERR;
//    U1STAbits.PERR;
//    U1STAbits.RXBKIF;
//    U1STAbits.TRMT;
//    U1STAbits.TXCIF;

    U1STAHbits.STPMD   = 1; /* Triggers RXIF at the end of the last Stop bit    */
    U1STAHbits.URXISEL = 0b000; /* Interrupt when there are 8 words buffered    */
    U1STAHbits.UTXISEL = 0b000; /* Interrupt when there are 8 empty slots       */
//    U1STAHbits.RIDLE;
//    U1STAHbits.TXWRE;
//    U1STAHbits.URXBE;
//    U1STAHbits.URXBF;
//    U1STAHbits.UTXBE;
//    U1STAHbits.UTXBF;
//    U1STAHbits.XON;

    U1BRG = 0x364;             /* baud rate 115200 [115207 error 0.006%] */
}

void UART_HardwareEnable()
{
    U1MODEbits.UARTEN = 1;
    U1MODEbits.URXEN  = 1;
    U1MODEbits.UTXEN  = 1;
}

void UART_RxTxQueueRestart()
{
    appData.uartRxHeadIndex = 0; appData.uartRxTailIndex = 0;
    appData.uartRxBuffFull  = 0; appData.uartRxBuffEmpty = 1;
    appData.uartTxHeadIndex = 0; appData.uartTxTailIndex = 0;
    appData.uartTxBuffFull  = 0; appData.uartTxBuffEmpty = 1;
}

void UART_RxInterruptEnable()
{
    IPC2bits.U1RXIP = 4;      /* Set UART Rx interrupt priority to 4 */
    /* IFS0bits.U1RXIF = 0; Do not Reset UART interrupt flag because can lose data */
    IEC0bits.U1RXIE = 1;      /* Enable UART Rx interrupt */
}

void UART_TxInterruptDisable()
{
    IPC3bits.U1TXIP = 4;      /* Set UART Tx interrupt priority to 4 */
    /* When using Tx IRQ do not Reset UART Tx interrupt flag except for the IRQ itself*/
    IEC0bits.U1TXIE = 0;      /* Disable UART Tx interrupt */
}
