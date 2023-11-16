/*
 * SYSTICK_PROGRAM.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */



/*		includes section		*/
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/SYSTICK_INTERFACE.h"
#include "../include/SYSTICK_CONFIG.h"
#include "../include/SYSTICK_PRIVATE.h"
/************************************/




void (*MSYSTICK_HANDLER)(void);

/*
 * MSYSTICK_voidInit functions selected clock source for system tick from 2 choices
 * 1.AHB_DIVIDED_BY_8
 * 2.AHB
 */
void MSYSTICK_voidInit(void)
{
	#if SYSTICK_SELECTED ==AHB_DIVIDED_BY_8
	SYSTICK->CTRL &=~(1<<2) ;

	#elif SYSTICK_SELECTED ==AHB
	SYSTICK->CTRL |=(1<<2) ;
	#endif


	MSYSTICK_voidCtrlIntState(DISABLED);
}



/*
 * MSYSTICK_voidStart function start the timer by adding a load value to LOAD
 * register and VAL register starts counting down then enable the systick
 */
void MSYSTICK_voidStart(u32 Copy_u32LoadValue)
{
	SYSTICK->LOAD=Copy_u32LoadValue;
	SYSTICK->VAL=0;
	SYSTICK->CTRL |=(1<<ENABLE);
}



/*
 * MSYSTICK_voidDelayMs function provides delay in micro-seconds
 */
void MSYSTICK_voidDelayMs(u32 Copy_u32DelayValue)
{
	u32 NumberOfTicksNeeded=(Copy_u32DelayValue)*(SYSTICK_CLOCK_IN_MHZ);
	u8 flag=GET_BIT(SYSTICK->CTRL,COUNT_FLAG);
	MSYSTICK_voidStart(NumberOfTicksNeeded);

	while(GET_BIT(SYSTICK->CTRL,COUNT_FLAG)==0){
	}
}



/*
 * MSYSTICK_voidDelayms function provides delay in milli-seconds
 */
void MSYSTICK_voidDelayms(u32 Copy_u32DelayValue)
{

	u32 NumberOfTicksNeeded=(Copy_u32DelayValue)*(SYSTICK_CLOCK_IN_MHZ*1000);
	u8 flag=GET_BIT(SYSTICK->CTRL,COUNT_FLAG);
	MSYSTICK_voidStart(NumberOfTicksNeeded);

	while(GET_BIT(SYSTICK->CTRL,COUNT_FLAG)==0){

	}


}



/*
 * MSYSTICK_voidReadFlag function reads the interrupt flag of systick
 * and clear this flag
 */
u8 MSYSTICK_voidReadFlag(void)
{
	return (GET_BIT(SYSTICK->CTRL,COUNT_FLAG));
}


/*
 * MSYSTICK_voidCtrlIntState function control interrupt generation
 * 1.DISABLED
 * 2.ENABLED
 */
void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_state)
{
	if(Copy_state == DISABLED)
	{
		SYSTICK->CTRL &=~(1<<TICKINT);
	}
	else if(Copy_state == ENABLED)
	{
		SYSTICK->CTRL |=(1<<TICKINT);
	}
}



/*
 * MSYSTICK_u32GetElapsedTime function gets elapsed time from start of counting
 * till that moment in micro_seconds
 */
u32 MSYSTICK_u32GetElapsedTime(void)
{
	u32 variable= (SYSTICK->LOAD-SYSTICK->VAL) & 0xFFFFFF;
	u32 elapesd_time_in_Ms=(1.0/SYSTICK_CLOCK_IN_MHZ)*(variable);
	return elapesd_time_in_Ms;
}


/*
 * MSYSTICK_u32GetRemainingTime function gets remaining time in micro-seconds
 */
u32 MSYSTICK_u32GetRemainingTime(void)
{
	f32 TickTime=(1/SYSTICK_CLOCK_IN_MHZ);
	u32 variable= SYSTICK->VAL & 0x1FFFFFF;
	u32 remaining_time_in_Ms=TickTime*(1000000UL)*(variable);
	return remaining_time_in_Ms;
}


void MSYSTICK_CallBack(void(*ptr)(void))
{
	MSYSTICK_HANDLER=ptr;
}

void SysTick_Handler(void)
{
	MSYSTICK_HANDLER();
	GET_BIT(SYSTICK->CTRL,COUNT_FLAG);
}

