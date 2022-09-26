/*******************************************************************************
 * File Name   : sensor_rec_process.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef SERVO_PROCESS_H
#define	SERVO_PROCESS_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include <xc.h>
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void SERVO_EventConnection()
 *
 * Description  : Setting initial event connection.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_EventConnection();

/*******************************************************************************
 * Function     : void SERVO_StartSignal()
 *
 * Description  : Initialization of variables and PWM kickoff.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_StartSignal();

/*******************************************************************************
 * Function     : void SERVO_StartConverting();
 *
 * Description  : Reset the processor if the pendulum stops.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_StartConverting();

/*******************************************************************************
 * Function     : void SERVO_TorqueReceived();
 *
 * Description  : Start lifting the weight.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_TorqueReceived();

/*******************************************************************************
 * Function     : void SERVO_GetFromSlave();
 *
 * Description  : Get Slave MSIM data.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_GetFromSlave();

/*******************************************************************************
 * Function     : void SERVO_PutToSlave();
 *
 * Description  : Put Slave MSIM data.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_PutToSlave();

/*******************************************************************************
 * Function     : void SERVO_ReceiveCommand();
 *
 * Description  : Start lifting the weight.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_ReceiveCommand();

/*******************************************************************************
 * Function     : void SERVO_ControlSignal();
 *
 * Description  : Start lifting the weight.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_ControlSignal();

/*******************************************************************************
 * Function     : void SERVO_TransmitBufferNotEmpty();
 *
 * Description  : Start lifting the weight.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void SERVO_TransmitBufferNotEmpty();

void SERVO_SendEncoder();
void SERVO_SendValue(int32_t value, uint8_t tag);
void SERVO_PrintedVariable(uint32_t printVar, uint8_t sign, uint8_t tag, uint8_t end);

#endif	/* SERVO_PROCESS_H */
