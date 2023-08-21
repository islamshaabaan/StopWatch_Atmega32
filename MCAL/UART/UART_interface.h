/*
 * UART_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: one
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_voidInit(void);

void UART_voidSendDataSync(u8 );

u8   UART_u8ReceiveDataSync(void);

void UART_voidSendString(u8* );


#endif /* MCAL_UART_UART_INTERFACE_H_ */
