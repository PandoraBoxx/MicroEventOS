/*******************************************************************************
 * File Name   : msim_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef MSIM_MACHINE_H
#define	MSIM_MACHINE_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void MSIM_WriteToSlave()
 *
 * Description  : Transfer Data to slave.
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void MSIM_WriteToSlave();

/*******************************************************************************
 * Function     : void MSIM_ReadFromSlave()
 *
 * Description  : Receive Data from Slave.
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void MSIM_ReadFromSlave();

#endif	/* MSIM_MACHINE_H */
