#ifndef __ADC_CONFIG_H__
#define __ADC_CONFIG_H__

//	Select frequency prescaler for ADC
/*
	0 For division factor equals 2
	1 For division factor equals 4
	2 For division factor equals 8
	3 For division factor equals 16
	4 For division factor equals 32
	5 For division factor equals 64
	6 For division factor equals 128
*/
#define ADC_prescaler							3		//	In general, the ADC operates within a frequency range of 50kHz to 200kHz.

//	Select reference voltage for ADC
/*
	0 For AREF, Internal Vref turned off
	1 For AVcc with external capacitor at AREF pin
	2 For Internal 2.56 Voltage Reference with external capacitor at AREF Pin
*/
#define ADC_Voltage_Reference					1

#define channel_mode_select						0		//	0 for single channel mode , 1 for differential input channel mode 

//	Select Channel for ADC 																						(optional)
/*
	0 For ADC0
	1 For ADC1
	2 For ADC2	
	3 For ADC3
	4 For ADC4
	5 For ADC5
	6 For ADC6
	7 For ADC7		
*/
#define ADC_channel								0		//	In case of single channel mode		

//	Select differential channels with proper gain for ADC														(optional)
/*
	0 For  (positive: ADC1 ,negative: ADC0 ,gain: 10)
	1 For  (positive: ADC1 ,negative: ADC0 ,gain: 200)
	2 For  (positive: ADC3 ,negative: ADC2 ,gain: 10)	
	3 For  (positive: ADC3 ,negative: ADC2 ,gain: 200)
	4 For  (positive: ADC0 ,negative: ADC1 ,gain: 1)
	5 For  (positive: ADC2 ,negative: ADC1 ,gain: 1)
	6 For  (positive: ADC3 ,negative: ADC1 ,gain: 1)
	7 For  (positive: ADC4 ,negative: ADC1 ,gain: 1)
	8 For  (positive: ADC5 ,negative: ADC1 ,gain: 1)
	9 For  (positive: ADC6 ,negative: ADC1 ,gain: 1)
	10 For (positive: ADC7 ,negative: ADC1 ,gain: 1)
	11 For (positive: ADC0 ,negative: ADC2 ,gain: 1)
	12 For (positive: ADC1 ,negative: ADC2 ,gain: 1)
	13 For (positive: ADC3 ,negative: ADC2 ,gain: 1)
	14 For (positive: ADC4 ,negative: ADC2 ,gain: 1)
	15 For (positive: ADC5 ,negative: ADC2 ,gain: 1)
*/
#define Differential_input_channels				20		//	In case of differential input channel mode

#define ADC_AutoTrigger_Enable					2		//	1 for enable ,otherwise for disable						(optional)	

//Select ADC trigger source for ADC 
/*
	0 For free running mode
	1 For Analog comparator
	2 For External interrupt request 0	
	3 For Timer/Counter 0 compare match
	4 For Timer/Counter 0 overflow
	5 For Timer/Counter 1 compare match B
	6 For Timer/Counter 1 overflow
	7 For Timer/Counter 1 capture event		
*/
#define ADC_trigger_source						9		//	ADC AutoTrigger must be enabled							(optional)

#endif