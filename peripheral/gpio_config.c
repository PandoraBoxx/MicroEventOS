/*******************************************************************************
 * File Name   : gpio_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "gpio_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void GPIO_SetConfiguration()
{
    /* Disable analog mode and enable digital mode */
    ANSELA = 0x0010; ANSELB = 0x0000; /* ANSELA4 = 1 ADC04 */

    /* Set all unused pins as input and initialize outputs*/
    TRISA  = 0xffff; TRISB  = 0xffff; /* All inputs               */
    LATA   = 0x0000; LATB   = 0x0000; /* All zeros                */
    ODCA   = 0x0000; ODCB   = 0x0000; /* No open drain            */
    CNPUA  = 0x0000; CNPUB  = 0x0000; /* No pull up               */
    CNPDA  = 0xffff; CNPDB  = 0xffff; /* All pull down            */
    CNCONAbits.ON = 0;                /* No change notification A */
    CNCONBbits.ON = 0;                /* No change notification B */
    CNEN0A = 0x0000; CNEN0B = 0x0000; /* No change notification interrupt */
    CNEN1A = 0x0000; CNEN1B = 0x0000; /* No change notification interrupt */

    /* Set used pins to no pull down */
    CNPDAbits.CNPDA1  = 0;           /* RA01 SLAVE */
    CNPDAbits.CNPDA2  = 0;           /* RA02 SLAVE */
    CNPDAbits.CNPDA3  = 0;           /* RA03 TIMER */
    CNPDAbits.CNPDA4  = 0;           /* RA04 ADC04 */
    CNPDBbits.CNPDB0  = 0;           /* RB00 SLAVE */
    CNPDBbits.CNPDB1  = 0;           /* RB01 SLAVE */
    CNPDBbits.CNPDB2  = 0;           /* RB02 URTRX */
    CNPDBbits.CNPDB3  = 0;           /* RB03 URTTX */
    CNPDBbits.CNPDB4  = 0;           /* RB04 QEIA0 */
    CNPDBbits.CNPDB5  = 0;           /* RB05 P3DAT */
    CNPDBbits.CNPDB6  = 0;           /* RB06 P3CLK */
    CNPDBbits.CNPDB7  = 0;           /* RB07 QEIB0 */
    CNPDBbits.CNPDB8  = 0;           /* RB09 SLAVE */
    CNPDBbits.CNPDB9  = 0;           /* RB08 SLAVE */
    CNPDBbits.CNPDB10 = 0;           /* RB10 SLAVE */
    CNPDBbits.CNPDB11 = 0;           /* RB11 SLAVE */
    CNPDBbits.CNPDB12 = 0;           /* RB12 PWM2H */
    CNPDBbits.CNPDB13 = 0;           /* RB13 PWM2L */
    CNPDBbits.CNPDB14 = 0;           /* RB14 PWM1H */
    CNPDBbits.CNPDB15 = 0;           /* RB15 PWM1L */

    /* Set selected pins to pull up */
    CNPUBbits.CNPUB4  = 1;           /* RB04 QEIA0 */
    CNPUBbits.CNPUB7  = 1;           /* RB07 QEIB0 */

    TMMST_PORT_TristateOutput();     /* RA03 TMMST */
    URTTX_PORT_TristateOutput();     /* RB03 URTTX */
    PWM2H_PORT_TristateOutput();     /* RB12 PWM2H */
    PWM2L_PORT_TristateOutput();     /* RB13 PWM2L */
    PWM1H_PORT_TristateOutput();     /* RB14 PWM1H */
    PWM1L_PORT_TristateOutput();     /* RB15 PWM1L */

    SLA01_PORT_TristateOutput();     /* RA01 SLA01 */
    SLB08_PORT_TristateOutput();     /* RB08 SLB08 */
    SLB09_PORT_TristateOutput();     /* RB09 SLB09 */
    SLB10_PORT_TristateOutput();     /* RB10 SLB10 */
    SLB11_PORT_TristateOutput();     /* RB11 SLB11 */

    /* Initialize Outputs */
    TIMER_MST_PORT_Output = 0;       /* RA03 TMMST */
}
