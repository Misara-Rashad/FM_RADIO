/*
 * SYSTICK_INTERFACE.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


/*		SYSTICK CLOCK SOURCE		*/
#define AHB_DIVIDED_BY_8		0
#define AHB						1
/***********************************/



#define ENABLE					0
#define TICKINT					1
#define COUNT_FLAG				16



typedef enum
{
	DISABLED,ENABLED
}SYSTICKState;





/*		SYSTICK interface		*/
void MSYSTICK_voidInit(void);
void MSYSTICK_voidStart(u32 Copy_u32LoadValue);
void MSYSTICK_voidDelayMs(u32 Copy_u32DelayValue);
void MSYSTICK_voidDelayms(u32 Copy_u32DelayValue);
u8 MSYSTICK_voidReadFlag(void);
void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_state);
u32 MSYSTICK_u32GetElapsedTime(void);
u32 MSYSTICK_u32GetRemainingTime(void);
void MSYSTICK_CallBack(void(*ptr)(void));
/************************************/


#endif /* SYSTICK_INTERFACE_H_ */
