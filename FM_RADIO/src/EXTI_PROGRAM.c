/*
 * EXTI_PROGRAM.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */

/*		includes section*/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "../include/EXTI_INTERFACE.h"
#include "../include/EXTI_CONFIG.h"
#include "../include/EXTI_PRIVATE.h"
/**********************************/




void (*EXTI_PTR[16])(void);			//16 pointer to function for each external interrupt

/*
 * MEXTI_voidInterruptSetport function sets the port that will cause an
 * external interrupt by line number and port number
 */
void MEXTI_voidInterruptSetport(EXTI_LINE Copy_u8Line,EXTI_PORT Copy_u8Port)
{
	SYSCFG->EXTICR[Copy_u8Line/4] |=(Copy_u8Port<<((Copy_u8Line%4)*4));
}




/*
 * MEXTI_voidInterruptEnableDisable function enables the interrupt of specific line
 */
void MEXTI_voidInterruptEnableDisable(EXTI_LINE Copy_u8Line,EXTI_STATE Copy_u8State )
{
	if(Copy_u8State==EXTI_DISABLED)
	{
		EXTI->IMR &=~(1<<Copy_u8Line);
	}
	else if(Copy_u8State==EXTI_ENABLED)
	{
		EXTI->IMR |=(1<<Copy_u8Line);
	}


}


/*
 * MEXTI_voidInterruptTrigger function sets the interrupt signal trigger
 * here we have 3 options
 * 1.FALLING_EDGE
 * 2.RISING_EDGE
 * 3.RISING_FALLING_EDGES(any change)
 */
void MEXTI_voidInterruptTrigger(EXTI_LINE Copy_u8Line,EXTI_Trigger Copy_u8Trig)
{
	if(Copy_u8Trig==FALLING_EDGE)
	{
		EXTI->FTSR |=(1<<Copy_u8Line);
	}
	else if(Copy_u8Trig==RISING_EDGE)
	{
		EXTI->RTSR |=(1<<Copy_u8Line);
	}
	else if(RISING_FALLING_EDGES==Copy_u8Trig)
	{
		EXTI->FTSR |=(1<<Copy_u8Line);
		EXTI->RTSR |=(1<<Copy_u8Line);
	}
}



/*
 * MEXTI_voidCallBack function gets the function to be executed in interrupt
 * handler
 */
void MEXTI_voidCallBack(void(*ptr)(void),EXTI_LINE Copy_u8Line )
{
	EXTI_PTR[Copy_u8Line]=ptr;
}




/*
 * external interrupt handlers
 */
void EXTI0_IRQHandler(void)
{
	EXTI_PTR[0]();
	EXTI->PR |=(1<<0);
}
void EXTI1_IRQHandler(void)
{
	EXTI_PTR[1]();
	EXTI->PR |=(1<<1);
}
void EXTI2_IRQHandler(void)
{
	EXTI_PTR[2]();
	EXTI->PR |=(1<<2);
}
void EXTI3_IRQHandler(void)
{
	EXTI_PTR[3]();
	EXTI->PR |=(1<<3);
}
void EXTI4_IRQHandler(void)
{
	EXTI_PTR[4]();
	EXTI->PR |=(1<<4);
}



EXTI15_10_IRQHandler(void)
{
	EXTI_PTR[15]();
	EXTI->PR |=(1<<15);
}
