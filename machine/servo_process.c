/*******************************************************************************
 * File Name   : servo_process.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "servo_process.h"
#include "event_process.h"
#include "timer_machine.h"
#include "adcv_machine.h"
#include "uart_machine.h"
#include "msim_machine.h"
#include "../peripheral/gpio_config.h"
#include "../system/system.h"

/* #define PENDULUM_STOP_DELAY  5000ms  */

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

/* Shared Variables (keep value between multiple functions) */
uint8_t transmitBuffer[SERIAL_TRANSMIT_MAX_LENGTH];
uint8_t  m_index;
int16_t  m_velocityCount;
int32_t  m_positionCount;
int8_t  m_positionIncrement;
uint8_t  m_transmitEnable;

/*******************************************************************************
 * Section: Function Entry Points
 ******************************************************************************/

void SERVO_EventConnection()
{
    PROCESS_ConnectInterruptEvent(INT_TIMER1_TOGG00, &SERVO_StartConverting);
    PROCESS_ConnectInterruptEvent(INT_ADCONV_READY, &SERVO_TorqueReceived);
    PROCESS_ConnectInterruptEvent(INT_UART_RX_READY, &SERVO_ReceiveCommand);
    PROCESS_ConnectInterruptEvent(INT_UART_TX_READY, &UART_TransmitBufferHasData);
    PROCESS_ConnectInterruptEvent(INT_READY_TOREAD, &SERVO_GetFromSlave);
    PROCESS_ConnectInterruptEvent(INT_READY_TOWRITE, &SERVO_PutToSlave);
}

void SERVO_StartSignal()
{
    m_positionIncrement = 0;
    m_transmitEnable = 1;

    TIMER1_StartToggle00(5);
    ADCON3Lbits.SHRSAMP = 1; /* ADC start sampling */
}

void SERVO_StartConverting()
{
    uint8_t timerOutput;

    ADCON3Lbits.SHRSAMP = 0; /* ADC stop sampling    */
    ADCON3Lbits.CNVRTCH = 1; /* ADC start converting */

    timerOutput = TIMER_MST_PORT_Output;
    if (timerOutput == 0) {
        TIMER_MST_PORT_Output = 1;
    } else {
        TIMER_MST_PORT_Output = 0;
    }

//    SERVO_SendEncoder();
}

void SERVO_TorqueReceived()
{
    uint8_t  idx;
    uint32_t filterOut;

    appBuffers.intADCQueue[appData.intADCTailIndex] = ADCV_GetConvertedValue();
    appData.intADCTailIndex++;
    appData.intADCTailIndex &= (FILTER_MAX_LENGTH-1);
    filterOut = 0;
    for (idx=0; idx < FILTER_MAX_LENGTH; idx++) {
        filterOut += appBuffers.intADCQueue[idx];
    }
    filterOut /= FILTER_MAX_LENGTH;

//    SERVO_SendValue((filterOut - 0x07FF - 23), 'C');
}

void SERVO_GetFromSlave()
{
    uint32_t temp;

    MSIM_ReadFromSlave();

    if (appBuffers.dataRead.ProtocolB[0] == 0x1234) {
        temp = appBuffers.dataRead.ProtocolB[1];
        temp = temp << 16;
        temp = temp | appBuffers.dataRead.ProtocolB[2];
    }

    SERVO_SendValue(temp, 'Z');

    appBuffers.dataRead.ProtocolB[4] = MSI1MBX9D; /* ProtocolB read finished (interrupt to slave) */
}

void SERVO_PutToSlave()
{
    m_transmitEnable = 1;
}

void SERVO_ReceiveCommand()
{
    uint8_t receivedSerial;
    uint16_t receivedData;

    receivedSerial = 0;
    if (!UART_IsReceiveBufferEmpty()) {
        if (m_transmitEnable) {
            UART_ReadReceivedData(&receivedSerial);

            m_transmitEnable = 0;
            appBuffers.dataWrite.ProtocolA[0] = 0x5678;
            appBuffers.dataWrite.ProtocolA[1] = receivedSerial;
            appBuffers.dataWrite.ProtocolA[2] = 0;
            appBuffers.dataWrite.ProtocolA[3] = 0;
            appBuffers.dataWrite.ProtocolA[4] = 0;

            MSIM_WriteToSlave();

            if (receivedSerial == 'U' || receivedSerial == 'u') {
                TIMER1_SetTimeIncrement(--m_positionIncrement);
            } else if (receivedSerial == 'D' || receivedSerial == 'd') {
                TIMER1_SetTimeIncrement(++m_positionIncrement);
            } else if (receivedSerial == 'P' || receivedSerial == 'p') {
                receivedData = PG1DC - 100;
                if (receivedData > (4095 - 100)) receivedData = 4095 - 100;
                if (receivedData < 100) receivedData = 100;
                PG2DC = 4095 - receivedData; /* The order is important */
                PG1DC = receivedData;        /* The order is important */
            } else if (receivedSerial == 'M' || receivedSerial == 'm') {
                receivedData = PG1DC + 100;
                if (receivedData > (4095 - 100)) receivedData = 4095 - 100;
                if (receivedData < 100) receivedData = 100;
                PG2DC = 4095 - receivedData; /* The order is important */
                PG1DC = receivedData;        /* The order is important */
            } else if (receivedSerial == 'C' || receivedSerial == 'c') {
                TIMER1_InitControler();
                m_positionIncrement = 0;
                POS1HLD  = 0;
                POS1CNTL = 0;
                PROCESS_ConnectInterruptEvent(INT_TIMER1_CONTROL, &SERVO_ControlSignal);
            } else if (receivedSerial == 'F' || receivedSerial == 'f') {
                PROCESS_ConnectInterruptEvent(INT_TIMER1_CONTROL, &PROCESS_NoCallBack);
                PG2DC = 4095-2047; /* PWM2 50% Duty Cycle */
                PG1DC = 2047;      /* PWM1 50% Duty Cycle */
            }
        }
    }

    if (!UART_IsReceiveBufferEmpty()) {
        PROCESS_ConnectInterruptEvent(INT_TIMER1_TOUT00, &SERVO_ReceiveCommand);
        TIMER1_StartTimer00(1);
    }
}

void SERVO_ControlSignal()
{
    int32_t controlOutput;
    uint16_t PWMOutput;
    controlOutput = appData.positionError * 16 + appData.errorDelta * 16 + 2047;
    if (controlOutput > (4095 - 100)) PWMOutput = 4095 - 100;
    else if (controlOutput < 100) PWMOutput = 100;
    else PWMOutput = controlOutput;
    PG2DC = 4095 - PWMOutput; /* The order is important */
    PG1DC = PWMOutput;        /* The order is important */
}

void SERVO_SendEncoder()
{
    uint32_t highWord, lastval;
    lastval = m_positionCount;

    m_positionCount = POS1CNTL;
    highWord = POS1HLD;
    highWord <<= 16;
    m_positionCount |= highWord;

//    if (lastval != m_positionCount)
//        SERVO_SendValue(m_positionCount, 'p');

    lastval = m_velocityCount;
    m_velocityCount = VEL1CNT;

//    if (lastval != m_velocityCount)
//        SERVO_SendValue((int32_t)m_velocityCount, 'v');
}

void SERVO_SendValue(int32_t value, uint8_t tag)
{
    uint8_t tempHolder, lastByte;

    m_index = 0;
    if (value < 0) SERVO_PrintedVariable(-value, '-', tag, 0);
    else SERVO_PrintedVariable(value, '+', tag, 0);

    lastByte = strlen((const char*) transmitBuffer);

    for (m_index = 0; m_index < lastByte/2; m_index++) {
        tempHolder = transmitBuffer[m_index];
        transmitBuffer[m_index] = transmitBuffer[lastByte - m_index -1];
        transmitBuffer[lastByte - m_index -1] = tempHolder;
    }
    transmitBuffer[lastByte++] = 0x0D;
    transmitBuffer[lastByte++] = 0x0A;

    UART_TransmitBufferAppend(transmitBuffer, lastByte);
}

void SERVO_PrintedVariable(uint32_t printVar, uint8_t sign, uint8_t tag, uint8_t end)
{
    uint32_t tempHolder, division, remmant;

    tempHolder = printVar;
    division = tempHolder / 10;
    remmant  = tempHolder % 10;

    while (division >= 10 ) {
        transmitBuffer[m_index++] = remmant + 0x30;
        tempHolder  = division;
        division = tempHolder / 10;
        remmant  = tempHolder % 10;
    }
    transmitBuffer[m_index++] = remmant + 0x30;
    transmitBuffer[m_index++] = division + 0x30;
    transmitBuffer[m_index++] = sign;
    transmitBuffer[m_index++] = ' ';
    transmitBuffer[m_index++] = ':';
    transmitBuffer[m_index++] = tag;
    transmitBuffer[m_index++] = end;
}

/*************************************************************************
 *************************************************************************
    uint16_t mcCorconSave = CORCON;
    CORCON = 0x00C1;

    volatile register int a_Reg asm("A");
    volatile register int b_Reg asm("B");
    int *xmemory;
    int *ymemory;
    int xVal, yVal;
    long result;

    asm volatile ("" : "+w"(a_Reg):); // Prevent optimization from re-ordering/ignoring this sequence of operations
    asm volatile ("" : "+w"(b_Reg):); // Prevent optimization from re-ordering/ignoring this sequence of operations

    xmemory = x_memory_buffer;
    ymemory = y_memory_buffer;

    a_Reg = __builtin_clr_prefetch(&xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, b_Reg);
    a_Reg = __builtin_mac(a_Reg, xVal, yVal, &xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, b_Reg);
    a_Reg = __builtin_mac(a_Reg, xVal, yVal, &xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, b_Reg);
    a_Reg = __builtin_sftac(a_Reg, -16);
    result = __builtin_sac(a_Reg,4);


    clr     A,[W8]+=2,W6,[W10]+=2,W7
	mac     W6*W7,A,[W8]+=2,W6,[W10]+=2,W7
	mac     W6*W7,A,[W8]+=2,W6,[W10]+=2,W7
	mac     W6*W7,A,[W8]+=2,W6,[W10]+=2,W7
	sftac   A,#-16
	sac     A,#4,[W13]

    Id =  Ialpha*cos(Angle) + Ibeta*sin(Angle)
    a_Reg = __builtin_mpy(alphabeta->alpha, sincos->cos,0,0,0,0,0,0);
    a_Reg = __builtin_mac(a_Reg, alphabeta->beta, sincos->sin,0,0,0,0,0,0,0,0);
    dq->d = __builtin_sacr(a_Reg,0);

       Iq = - Ialpha*sin(Angle) + Ibeta*cos(Angle)
    a_Reg = __builtin_mpy(alphabeta->beta, sincos->cos,0,0,0,0,0,0);
    a_Reg = __builtin_msc(a_Reg, alphabeta->alpha, sincos->sin,0,0,0,0,0,0,0,0);
    dq->q = __builtin_sacr(a_Reg,0);

    CORCON = mcCorconSave;
*/
