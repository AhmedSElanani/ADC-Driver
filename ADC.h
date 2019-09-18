#ifndef __ADC_H__
#define __ADC_H__

#include "ADC_Config.h"
#include <avr/io.h>
#include <avr/interrupt.h>



/**************************************************************************************************
*   Macros
**************************************************************************************************/
#define start_conversion()						ADCSRA |= (1<<ADSC)
#define ADC_Noise_Canceler_Enable()



/**************************************************************************************************
*   Functions prototypes
**************************************************************************************************/
void ADC_init(void);
uint16_t ADC_Conversion_Result(void);
void ADC_interrupt_enable(void);

#endif
