/*******************************************************************************
 * File Name   : adcv_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "adcv_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void ADCV_HardwareConfig()
{
    /* ADC control 3H */
    ////////////////////
    ADCON3Hbits.CLKDIV = 0b000001; /* ADC Module Clock Divider (2 Source Periods) */
    ADCON3Hbits.CLKSEL = 0b00;     /* ADC Module Clock Selection (FOSC/2)         */

    /* ADC control 2L */
    ////////////////////
    ADCON2Lbits.SHRADCS  = 0b0000000; /* ADC input clock divider (2 Source Clock) */
    ADCON2Lbits.EIEN     = 0; /* Interrupt at end of conversion (ANxRDY flag set) */
    ADCON2Lbits.REFCIE   = 0; /* Interrupt disabled for band gap                  */
    ADCON2Lbits.REFERCIE = 0; /* Interrupt disabled for band gap error event      */
    /* ADCON2Lbits.SHREISEL  Not used (ADC Early Interrupt Time Selection)        */

    /* ADC control 3L */
    ////////////////////
    ADCON3Lbits.REFSEL   = 0b000;  /* ADC reference voltage selection (AVDD-AVSS) */
    ADCON3Lbits.CNVCHSEL = 0b00100; /* Channel selection for software channel
                                       conversion trigger to AN04                 */
    /* ADCON3Lbits.SUSPCIE   Not used (No interrupt generated for suspend)        */
    /* ADCON3Lbits.SUSPEND   Not used (All ADC cores suspend command)             */
    /* ADCON3Lbits.SUSPRDY   Not used (All ADC cores suspended flag)              */
    /* ADCON3Lbits.SWLCTRG   Not used (Software level-sensitive common trigger)   */
    /* ADCON3Lbits.SWCTRG    Not used (Software Common Trigger)                   */

    /* ADC control 1H */
    ////////////////////
    ADCON1Hbits.FORM   = 0;    /* Integer format                                  */
    ADCON1Hbits.SHRRES = 0b11; /* Shared ADC Core Resolution 12 bits              */

    /* ADC input mode control */
    ////////////////////////////
    ADMOD0Lbits.SIGN4 = 0; /* Set channel AN04 output data as unsigned            */
    /* ADMOD0H  Not used (Output Data Sign for Corresponding Analog Input)        */
    /* ADMOD1L  Not used (Output Data Sign for Corresponding Analog Input)        */

    /* ADC control 2H */
    ////////////////////
    ADCON2Hbits.SHRSAMC = 0b0000001000; /* ADC Core Sample Time 10 TADCORE        */
    /* ADCON2Hbits.REFERR   Not used (Band Gap or Reference Voltage Error Flag)   */
    /* ADCON2Hbits.REFRDY   Not used (Band Gap or Reference Voltage Ready Flag)   */

    /* ADC early interrupt enable */
    ////////////////////////////////
    ADEIELbits.EIEN4  = 0; /* Early interrupt is disabled for AN04                */
    /* ADEIEH     Not used (ADC early interrupt enable)                           */
    /* ADEISTATL  Not used (ADC early interrupt status)                           */
    /* ADEISTATH  Not used (ADC early interrupt status)                           */

    /* ADC level sensitive trigger */
    /////////////////////////////////
    ADLVLTRGLbits.LVLEN4 = 0;      /* Input trigger is edge-sensitive for AN04    */
    /* ADLVLTRGHbits   Not used (ADC level-sensitive trigger control)             */

    /* ADC channel trigger selection register */
    ///////////////////////////////////////////
    ADTRIG1Lbits.TRGSRC4 = 0b00001; /* Common software trigger for AN04           */

    /* ADC data ready status */
    ///////////////////////////
    /* ADSTATLbits.AN4RDY   Not used (Conversion result ready in ADCBUFx)         */
    /* ADSTATH              Not used (ADC data ready status register high)        */

    /* ADC comparator control registers */
    //////////////////////////////////////
    /* ADCMPxCON  Not used (ADC digital comparator x control)                     */
    /* ADCMPxENL  Not used (ADC digital comparator x channel enable)              */
    /* ADCMPxENH  Not used (ADC digital comparator x channel enable)              */

    /* ADC digital filter registers */
    //////////////////////////////////////
    /* ADFLxCON   Not used (ADC digital filter x control)                         */

////////////////////////////////////

    /* ADC channel buffer */
    ////////////////////////
    /* ADCBUF4               USED (AN4 Data buffer)                               */

    /* ADC control 3L */
    ////////////////////
    /* ADCON3Lbits.CNVRTCH   USED (Software individual channel trigger)           */
    /* ADCON3Lbits.SHRSAMP   USED (Connects input selected by CNVCHSEL[5:0]       */
}

void ADCV_HardwareEnable()
{
    /* ADC control 5H */
    ////////////////////
    ADCON5Hbits.WARMTIME = 0b1111; /* 32768 Source Clock Periods of warmup        */
    ADCON5Hbits.SHRCIE   = 0;      /* No interrupt when ADC is powered
                                      and ready for operation                     */
    /* ADC control 1L */
    ////////////////////
    ADCON1Lbits.ADSIDL   = 1;      /* Discontinues module operation on Idle mode  */
    ADCON1Lbits.ADON     = 1;      /* Turn on ADC module                          */

    /* ADC control 5L */
    ////////////////////
    ADCON5Lbits.SHRPWR   = 1;      /* Turn on analog power for shared core        */
    while(ADCON5Lbits.SHRRDY == 0); /* Wait when the shared core is ready         */
    ADCON3Hbits.SHREN    = 1;      /* Turn on digital power to enable triggers    */
}

void ADCV_InterruptEnable()
{
    /* ADC interrupt enable */
    //////////////////////////
    ADIELbits.IE4 = 1; /* Common and individual interrupts are enabled for AN04   */
    /* ADIEH  Not used (ADC interrupt enable register)                            */

    IPC23bits.ADCAN4IP = 4;  /* Set ADC AN04 interrupt priority to 4 */
    /* IFS5bits.ADCAN4IF  = 0; Do not Reset ADCM interrupt flag because can lose a conversion */
    IEC5bits.ADCAN4IE  = 1;  /* Enable ADC AN04 interrupt            */
}

void ADCV_VariableInitialization()
{
    appData.torqueValue04   = 0;
    appData.intADCTailIndex = 0;
}
