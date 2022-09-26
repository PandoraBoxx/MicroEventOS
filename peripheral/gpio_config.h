/*******************************************************************************
 * File Name   : gpio_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef GPIO_CONFIG_H
#define	GPIO_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include <xc.h>
#include "../system/global_app_data.h"

/*******************************************************************************
 * Section: I/O Management
 ******************************************************************************/

#define TMMST_PORT_TristateOutput() TRISAbits.TRISA3  = 0 /* RA03 TMMST */
#define URTTX_PORT_TristateOutput() TRISBbits.TRISB3  = 0 /* RB03 URTTX */
#define PWM2H_PORT_TristateOutput() TRISBbits.TRISB12 = 0 /* RB12 PWM2H */
#define PWM2L_PORT_TristateOutput() TRISBbits.TRISB13 = 0 /* RB13 PWM2L */
#define PWM1H_PORT_TristateOutput() TRISBbits.TRISB14 = 0 /* RB14 PWM1H */
#define PWM1L_PORT_TristateOutput() TRISBbits.TRISB15 = 0 /* RB15 PWM1L */

#define SLA01_PORT_TristateOutput() TRISAbits.TRISA1  = 0 /* RA01 SLA01 */
#define SLB08_PORT_TristateOutput() TRISBbits.TRISB8  = 0 /* RB08 SLB08 */
#define SLB09_PORT_TristateOutput() TRISBbits.TRISB9  = 0 /* RB09 SLB09 */
#define SLB10_PORT_TristateOutput() TRISBbits.TRISB10 = 0 /* RB10 SLB10 */
#define SLB11_PORT_TristateOutput() TRISBbits.TRISB11 = 0 /* RB11 SLB11 */

#define TIMER_MST_PORT_Output       LATAbits.LATA3        /* RA03 TMMST */

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void GPIO_SetConfiguration() 
 *
 * Description  : Initializes the input/output pins.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void GPIO_SetConfiguration();

#endif	/* GPIO_CONFIG_H */

