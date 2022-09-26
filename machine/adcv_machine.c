/*******************************************************************************
 * File Name   : adcv_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "adcv_machine.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

uint16_t ADCV_GetConvertedValue()
{
    uint16_t outValue;
    INTERRUPT_DisableADCV04();
    outValue = appData.torqueValue04;
    INTERRUPT_EnableADCV04();
    
    return outValue;
}
