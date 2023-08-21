/*
 * STEPPER_config.h
 *
 *  Created on: Aug 13, 2023
 *      Author: one
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_
#define HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_



/*Options :-
 * For Coil Port
 * PORTA
 * PORTB
 * PORTC
 * PORTD
 * */
#define STEPPERMOTOR_PORT       DIO_PORTC

/* OPTIONS :-
 * For Coil Wires
 	 1- DIO_PIN0
 	 2- DIO_PIN1
 	 3- DIO_PIN2
 	 4- DIO_PIN3
 	 5- DIO_PIN4
 	 6- DIO_PIN5
 	 7- DIO_PIN6
 	 8- DIO_PIN7

 */
#define STEPPERMOTOR_PINK_PIN   			0
#define STEPPERMOTOR_BLUE_PIN   			1
#define STEPPERMOTOR_YELLOW_PIN 			2
#define STEPPERMOTOR_ORANGE_PIN 			3





/**
 *
 *
 * *((volatile u8*)0x35)=0x09;// 0 CW-2 phase excitation
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x08; // 45 DEG
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x0c; // 90
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x04; // 135 degree
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x06; // 180
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x02; // 225 degree
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x03; // 270
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x01; // 315 degree
						_delay_ms(2000);
 *((volatile u8*)0x35)=0x09;// 0 CW-2 phase excitation
						_delay_ms(2000);
*/
#endif /* HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_*/
