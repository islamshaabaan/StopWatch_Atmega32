/*
 * WDT_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: First
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_


#define WDT_2_1_S		7
#define WDT_1_S			6

void WDT_voidEnable		(u8 Copy_u8Prescaler );

void WDT_voidDisable	(void);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
