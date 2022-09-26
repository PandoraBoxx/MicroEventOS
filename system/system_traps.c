/*******************************************************************************
 * File Name   : system_traps.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include "system.h"

/*  Available traps
 * 
 * _OscillatorFail, _AddressError, _StackError, _MathError, _DefaultInterrupt */

/*******************************************************************************
 * Section: File Scope Functions
 ******************************************************************************/

#define ERROR_HANDLER __attribute__((interrupt, no_auto_psv, keep, section("error_handler")))

static uint16_t TRAPS_error_code = -1;

void __attribute__((weak)) SYSTEM_TrapError(uint16_t code)
{
    TRAPS_error_code = code;
#ifdef __DEBUG    
    __builtin_software_breakpoint();
#endif
    while(1);
}

/*******************************************************************************
 * Section: Primary Exception Vector handlers
 ******************************************************************************/

/*******************************************************************************
 * Function     : void ERROR_HANDLER _OscillatorFail(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Oscillator trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the oscillator trap.
 *
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void ERROR_HANDLER _OscillatorFail (void)
{
    INTCON1bits.OSCFAIL = 0;
    SYSTEM_TrapError(TRAPS_OSC_FAIL);
}

/*******************************************************************************
 * Function     : void ERROR_HANDLER _AddressError(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Address Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the address error trap.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void ERROR_HANDLER _AddressError (void)
{
    INTCON1bits.ADDRERR = 0;
    SYSTEM_TrapError(TRAPS_ADDRESS_ERR);
}

/*******************************************************************************
 * Function     : void ERROR_HANDLER _HardTrapError(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Address Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the address error trap.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void ERROR_HANDLER _HardTrapError (void)
{
    INTCON4bits.SGHT = 0;
    SYSTEM_TrapError(TRAPS_HARD_ERR);
}

/*******************************************************************************
 * Function     : void ERROR_HANDLER _MathError(void))
 * 
 *
 * Description  : Provides the required exception vector handlers for
 *                Math Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the math error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void ERROR_HANDLER _MathError (void)
{
    INTCON1bits.MATHERR = 0;
    SYSTEM_TrapError(TRAPS_MATH_ERR);
}

/*******************************************************************************
 * Function     : void ERROR_HANDLER _SoftTrapError(void))
 * 
 *
 * Description  : Provides the required exception vector handlers for
 *                Math Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the math error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void ERROR_HANDLER _SoftTrapError ( void )
{
    if(INTCON3bits.NAE) {
        INTCON3bits.NAE = 0;
        SYSTEM_TrapError(TRAPS_NVM_ERR);
    }

    if(INTCON3bits.DAE) {
        INTCON3bits.DAE = 0;
        SYSTEM_TrapError(TRAPS_DAE_ERR);
    }

    if(INTCON3bits.DOOVR)
    {
        INTCON3bits.DOOVR = 0;
        SYSTEM_TrapError(TRAPS_DOOVR_ERR);
    }

    if(INTCON3bits.APLL)
    {
        INTCON3bits.APLL = 0;
        SYSTEM_TrapError(TRAPS_APLL_ERR);
    }

    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _StackError(void))
 *
 * Description  : Provides the required exception vector handlers for
 *                Stack Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the stack error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _StackError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__ ( ( __interrupt__ , auto_psv ) ) _DefaultInterrupt( void );
 *
 * Description  : Default Interrupt Handler
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This executes when an interrupt occurs for an interrupt
 *                source with an improperly defined or undefined interrupt
 *                handling routine.
 *******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _DefaultInterrupt( void )
{
    /* Check the trap flag */
    while(1);
}

/*******************************************************************************
 * Section: Secondary Exception Vector handlers (Disabled)
 ******************************************************************************/
