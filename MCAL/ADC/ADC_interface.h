/*
 * ADC_Int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

typedef enum{
	AREF, AVCC, INTERNAL=3
}ADC_RefSelect_t;

typedef enum{
	ADC_FCPU_2 = 1 , ADC_FCPU_4, ADC_FCPU_8,
	ADC_FCPU_16 ,    ADC_FCPU_32, ADC_FCPU_64,
	ADC_FCPU_128
}ADC_Prescaler_t;

typedef enum{
	ADC0 , ADC1, ADC2, ADC3,
	ADC4,  ADC5 ,ADC6, ADC7
}ADC_Channel_t;
typedef enum{
	LEFT_ADJUST,RIGHT_ADJUST
}ADC_ADJ_Option_t;
typedef enum{

	/*For single Channel (ADC_SINGLE_ENDED_5) it means channel 5*/
	ADC_SINGLE_ENDED_0,
	ADC_SINGLE_ENDED_1,
	ADC_SINGLE_ENDED_2,
	ADC_SINGLE_ENDED_3,
	ADC_SINGLE_ENDED_4,
	ADC_SINGLE_ENDED_5,
	ADC_SINGLE_ENDED_6,
	ADC_SINGLE_ENDED_7,

	/*For differential (ADC_DIFF_0_1_10) it means channel 0 on positive and 1 on negative and 10x gain*/
	ADC_DIFF_0_0_10x,
	ADC_DIFF_1_0_10x,
	ADC_DIFF_0_0_200x,
	ADC_DIFF_1_0_200x,
	ADC_DIFF_2_2_10x,
	ADC_DIFF_3_2_10x,
	ADC_DIFF_2_2_200x,
	ADC_DIFF_3_2_200x,


	ADC_DIFF_0_1_1x,
	ADC_DIFF_1_1_1x,
	ADC_DIFF_2_1_1x,
	ADC_DIFF_3_1_1x,
	ADC_DIFF_4_1_1x,
	ADC_DIFF_5_1_1x,
	ADC_DIFF_6_1_1x,
	ADC_DIFF_7_1_1x,

	ADC_DIFF_0_2_1x,
	ADC_DIFF_1_2_1x,
	ADC_DIFF_2_2_1x,
	ADC_DIFF_3_2_1x,
	ADC_DIFF_4_2_1x,
	ADC_DIFF_5_2_1x,

}ADC_InputChWithGain_t;
typedef enum{
	ADC_FREE_RUNNING_MODE,
	ADC_ANALOG_COMPARATOR,
	ADC_EXT_INT0,
	ADC_TIMER0_COMPARE_MATCH,
	ADC_TIMER0_OVERFLOW,
	ADC_TIMER1_COMPARE_MATCH_B,
	ADC_TIMER1_OVERFLOW,
	ADC_TIMER1_CAPTURE_EVENT,

}ADC_trigger_source_t;

typedef struct{

	ADC_RefSelect_t   Vref;
	ADC_Prescaler_t   Prescaler;
	ADC_ADJ_Option_t				Adjust_Option;
}ADC_Conf_t;

void ADC_voidInit(ADC_Conf_t*);
u16 ADC_u16SynReadChannelPolling(ADC_InputChWithGain_t ADC_InputChWithGain);

void ADC_voidReadChannelInterrupt(ADC_Channel_t channel_num);

void ADC_voidSetCallBackFunction(void (*ptrToFun) (void));



void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidChooseTrigSrc(ADC_trigger_source_t Copy_enumTriggerSource);
u16 ADC_u16AsysReadCh(void);
void ADC_voidAsysChooseChannel(ADC_InputChWithGain_t ADC_InputChWithGain);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
