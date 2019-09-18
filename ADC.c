#include "ADC.h"

//	Functions Implementations
void ADC_init(void)
{
	//	Select frequency prescaler for ADC
	#if (ADC_prescaler == 0)
	ADCSRA = (1<<ADPS0);
	#elif (ADC_prescaler == 1)
	ADCSRA = (1<<ADPS1);
	#elif (ADC_prescaler == 2)
	ADCSRA = ((1<<ADPS0)|(1<<ADPS1));
	#elif (ADC_prescaler == 3)
	ADCSRA = (1<<ADPS2);
	#elif (ADC_prescaler == 4)
	ADCSRA = ((1<<ADPS0)|(1<<ADPS2));
	#elif (ADC_prescaler == 5)
	ADCSRA = ((1<<ADPS1)|(1<<ADPS2));
	#elif (ADC_prescaler == 6)
	ADCSRA = ((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
	#endif
	
	//	Select reference voltage for ADC
	#if (ADC_Voltage_Reference == 0)
	ADMUX = 0;
	#elif (ADC_Voltage_Reference == 1)
	ADMUX = (1<<REFS0);	
	#elif (ADC_Voltage_Reference == 2)
	ADMUX = (1<<REFS0)|(1<<REFS1);	
	#endif
	
	
	//	checks for channel mode selected
	#if (channel_mode_select == 0)
	//	Select Channel for ADC in single mode
	#if (ADC_channel == 0)
	
	#elif (ADC_channel == 1)
	ADMUX |= (1<<MUX0);
	#elif (ADC_channel == 2)
	ADMUX |= (1<<MUX1);
	#elif (ADC_channel == 3)
	ADMUX |= ((1<<MUX0)|(1<<MUX1));
	#elif (ADC_channel == 4)
	ADMUX |= (1<<MUX2);
	#elif (ADC_channel == 5)
	ADMUX |= ((1<<MUX0)|(1<<MUX2));
	#elif (ADC_channel == 6)
	ADMUX |= ((1<<MUX1)|(1<<MUX2));
	#elif (ADC_channel == 7)
	ADMUX |= ((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
	#endif

	#elif (channel_mode_select == 1)
	//	Select Channel for ADC in differential input mode
	#if (Differential_input_channels == 0)
	ADMUX |= (1<<MUX3)|(1<<MUX0);
	#elif (Differential_input_channels == 1)
	ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX3);
	#elif (Differential_input_channels == 2)
	ADMUX |= (1<<MUX0)|(1<<MUX2)|(1<<MUX3);
	#elif (Differential_input_channels == 3)
	ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3);
	#elif (Differential_input_channels == 4)
	ADMUX |= (1<<MUX4);
	#elif (Differential_input_channels == 5)
	ADMUX |= (1<<MUX1)|(1<<MUX4);
	#elif (Differential_input_channels == 6)
	ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX4);
	#elif (Differential_input_channels == 7)
	ADMUX |= (1<<MUX2)|(1<<MUX4);
	#elif (Differential_input_channels == 8)
	ADMUX |= (1<<MUX0)|(1<<MUX2)|(1<<MUX4);
	#elif (Differential_input_channels == 9)
	ADMUX |= (1<<MUX1)|(1<<MUX2)|(1<<MUX4);
	#elif (Differential_input_channels == 10)
	ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX4);
	#elif (Differential_input_channels == 11)
	ADMUX |= (1<<MUX3)|(1<<MUX4);
	#elif (Differential_input_channels == 12)
	ADMUX |= (1<<MUX0)|(1<<MUX3)|(1<<MUX4);
	#elif (Differential_input_channels == 13)
	ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX3)|(1<<MUX4);
	#elif (Differential_input_channels == 14)
	ADMUX |= (1<<MUX2)|(1<<MUX3)|(1<<MUX4);
	#elif (Differential_input_channels == 15)
	ADMUX |= (1<<MUX0)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4);
	#endif
	
	#endif
	
	//	Set ADLAR bit to make it left Adjust the ADC Result
	ADMUX |= (1<<ADLAR);  
	
	//	Auto trigger mode configurations
	#if (ADC_AutoTrigger_Enable == 1)
	ADCSRA |= (1<<ADATE)
	#if (ADC_trigger_source == 0)
	SFIOR &= ~((1<<ADTS0)|(1<<ADTS1)|(1<<ADTS2));
	#elif (ADC_trigger_source == 1)
	SFIOR &= ~((1<<ADTS1)|(1<<ADTS2));
	SFIOR |= (1<<ADTS0);
	#elif (ADC_trigger_source == 2)
	SFIOR &= ~((1<<ADTS0)|(1<<ADTS2));
	SFIOR |= (1<<ADTS1);
	#elif (ADC_trigger_source == 3)
	SFIOR &= ~(1<<ADTS2);
	SFIOR |= (1<<ADTS0)|(1<<ADTS1);
	#elif (ADC_trigger_source == 4)
	SFIOR &= ~((1<<ADTS0)|(1<<ADTS1));
	SFIOR |= (1<<ADTS2);
	#elif (ADC_trigger_source == 5)
	SFIOR &= ~(1<<ADTS1);
	SFIOR |= (1<<ADTS0)|(1<<ADTS2);
	#elif (ADC_trigger_source == 6)
	SFIOR &= ~(1<<ADTS0);
	SFIOR |= (1<<ADTS1)|(1<<ADTS2);
	#elif (ADC_trigger_source == 7)
	SFIOR |= ((1<<ADTS0)|(1<<ADTS1)|(1<<ADTS2));
	#endif
	#endif
	
	ADCSRA |= (1<<ADEN);							//	it enables the ADC feature.	
	start_conversion();
}


uint16_t ADC_Conversion_Result(void)
{	
	while(!(ADCSRA & (1<<ADIF)));			//	wait for ADC to complete conversion
	ADCSRA|=(1<<ADIF);						//	clear the flag
	return ADC;								//	return value in ADC register
}


void ADC_interrupt_enable(void)
{
	ADCSRA |= (1<<ADIE);
	sei();
}


