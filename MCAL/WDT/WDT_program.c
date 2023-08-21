/*
 * WDT_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: First
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MACROS.h"


#include "WDT_interface.h"
#include "WDT_private.h"


void WDT_voidEnable		(u8 Copy_u8Prescaler )
{
	/* Prescaler */

	WDTCR_REG = Copy_u8Prescaler ;
		/*Enable */
	SET_BIT(WDTCR_REG , 3 );
}

void WDT_voidDisable	(void)
{
	WDTCR_REG = (1<<3) | (1 << 4 );
	WDTCR_REG = 0x00 ;
}
