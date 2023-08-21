/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Islam Shaaban
 */

#include <util/delay.h>
#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MACROS.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMERS/TIMERS_interface.h"

#include "HAL/LED/LED_interface.h"
#include "HAL/SSD/SSD_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/KPAD/KPAD_interface.h"

#define SW_NumberOf_OVFs		31
void CallBackFunction(){
	static u8 overflows_counter=0;
	overflows_counter++;
	if(overflows_counter == SW_NumberOf_OVFs){
		//ToggleLED();
		overflows_counter=0;
	}
}


int main(){
	CLCD_voidInit();
	KPAD_voidInit();

	CLCD_voidSetPosition(1,1);

	TIMER_Config_t myTimerConfig= {
			.T_ID = TIMER0_ID,
			.T_Mode = Normal_mode_OVF,
			.T_CompareOutput= DISCONNECT_OCX,
			.T_Prescaler= T0_FCPU_8,
			.Tech=Polling,
			.PreloadValue=0,
			.CompareValue=0
	};

	/*Set the value 00:00*/
	CLCD_voidSetPosition(1,1);
	CLCD_voidSendString((u8*)"SET TIME 00:00");

	// it just need to start count on Extrnal falling edge = button
	TIMERS_voidInit(&myTimerConfig);
	//TIMERS_voidTIM0Start(&myTimerConfig);

	//u8 LOCAL_u8TimerValue;
	u8 Local_u8Pressed = 0xff;
	u8 Time[4] = {'0','0','0','0'};
	u8 Local_u8TempCount =0; // to count 4 digits
	u16 Local_u16Seconds=0;
	while(1){
		Time[3]=0;
		Time[2]=0;
		Time[1]=0;
		Time[0]=0;
		CLCD_voidSetPosition(1,1);
		CLCD_voidSendString((u8*)"SET TIME 00:00");
		while(Local_u8TempCount < 4 ){
			Local_u8Pressed = KPAD_u8GetPressed();
			if(Local_u8Pressed != 0xFF){
				Time[Local_u8TempCount] = Local_u8Pressed - 48;
				if((Local_u8TempCount < 2)){
					CLCD_voidSetPosition(1,Local_u8TempCount+1+9);
				}
				else{
					CLCD_voidSetPosition(1,Local_u8TempCount+2+9);
				}
				CLCD_voidSendu32Number(Time[Local_u8TempCount]);
				++Local_u8TempCount;
			}
		}
		// To conver the digits to virtual second (Ticks).
		// 05:09 = 309 ticks.
		Local_u16Seconds = ( 60* (Time[0] * 10 + Time[1])) + Time[2] * 10 + Time[3];

		Local_u8Pressed = KPAD_u8GetPressed();
		// while the button is not pressed,
		// wait until get the pressed button.
		while(Local_u8Pressed == 0xff){
			Local_u8Pressed = KPAD_u8GetPressed();
		}

		if(Local_u8Pressed == '='){
			Local_u8TempCount = 0;
			CLCD_voidCLearDisplay();
			for(s16 i=Local_u16Seconds; i>=0; i--){
				for(u16 Local_u8OverFlows=0;Local_u8OverFlows<2500;Local_u8OverFlows++){
					TIMERS_voidTIM0Start(&myTimerConfig);
				}
				// xx:x0
				if(Time[3]==0 &&Time[2]!=0){
					Time[2]-=1;
					Time[3]=10;
				}
				//xx:00
				if(Time[2]==0 &&Time[3]==0){
					//xx:00
					if(Time[1]!=0){
						Time[1]-=1;
						Time[2]=5;
						Time[3]=10;
					}
					else{
						// x0:00
						Time[0]-=1;
						Time[1]=9;
						Time[2]=5;
						Time[3]=10;
					}
				}
				//x0:00
				if(Time[1]==0 &&Time[0]!=0 && Time[2]==0 &&Time[3]==0){
					Time[0]-=1;
					Time[1]=9;
				}
				Time[3]--;
				CLCD_voidCLearDisplay();
				CLCD_voidSetPosition(1,1);
				CLCD_voidSendData(Time[0]+'0');
				CLCD_voidSendData(Time[1]+'0');
				CLCD_voidSendData(':');
				CLCD_voidSendData(Time[2]+'0');
				CLCD_voidSendData(Time[3]+'0');
			}
		}
		else if(Local_u8Pressed == 'C'){
			CLCD_voidCLearDisplay();
			Time[3]=0;
			Time[2]=0;
			Time[1]=0;
			Time[0]=0;

		}
		else{
			// Do nothing
		}
	}
}
