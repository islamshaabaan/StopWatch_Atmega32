/*
 * UART_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: one
 */

#include "../../LIB/BIT_MACROS.h"
#include "../../LIB/STD_TYPES.h"

#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"


void UART_voidInit(void){

	UART_UCSRB_REG = 0b00011000;


	//config uscrc
	u8 Local_u8TempUCSRC = 0b10000000;
	// Asyn
	CLR_BIT(Local_u8TempUCSRC,6);
	// disable parity
	CLR_BIT(Local_u8TempUCSRC,5);
	CLR_BIT(Local_u8TempUCSRC,4);
	// 1 STOP BIT
	CLR_BIT(Local_u8TempUCSRC,3);

	// 8 BIT MODE , UCS2->>0, UCS1,0 --> 1
	SET_BIT(Local_u8TempUCSRC,2);
	SET_BIT(Local_u8TempUCSRC,1);

	//CPOL -->> leading edge (raising) ONLY FOR SYNCH
	CLR_BIT(Local_u8TempUCSRC,0);

	UART_UCSRC_REG = Local_u8TempUCSRC;

	//baud rate
	UART_UBRRL_REG = (u8) UART_BAUD_RATE;
	UART_UBRRH_REG = (u8) (UART_BAUD_RATE >> 8 );

}

void UART_voidSendData(u8 Copy_u8Data){

	// check if buffer is empty
	while(GET_BIT(UART_UCSRA_REG,5)==0);

	// SEND DATA and the flag will cleared automatically after sending
	UART_UDR_REG = Copy_u8Data;
}

u8 UART_u8ReceiveDataSync(){
	/* Waiting till RxC flag raise */
		while(GET_BIT(UART_UCSRA_REG , 7) == 0);

		/* Return the received Byte */
		return UART_UDR_REG;
}
void UART_voidSendStringSync(u8 * Pu8Data)
{
	u8 u8LoopCtr=0;
	while(Pu8Data[u8LoopCtr]!='\0')//fakt l gomla dy *(Pu8DAta+u8loopctr) da nzakr pointer aw c ya man b2a
	{
		//transmit
		UART_voidSendData(Pu8Data[u8LoopCtr]);
		u8LoopCtr++;

	}
	//UART_u8ReceiveDataSync("/r");
	//UART_u8ReceiveDataSync('/n');
}
void UART_voidReceiveStringSync(u8 * Copy_u8ReceiveData, u8 msgSize){
	u8 counter =0;

	if(Copy_u8ReceiveData != NULL){
		while(counter <msgSize){
			//check if anydata in buffer
			//read data
			Copy_u8ReceiveData[counter]= UART_UDR_REG;
			counter ++ ;
		}
	}
}
// Assignment
/* 0- Time out 50ms
 * 1- Send and Receive Data Asynch.
 * 3- Send string function Asynch.
 */
