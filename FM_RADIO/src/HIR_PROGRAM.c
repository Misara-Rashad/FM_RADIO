/*
 * HIR_PROGRAM.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Misra
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "SYSTICK_INTERFACE.h"
#include "HIR_INTERFACE.h"
#include "HIR_CONFIG.h"
#include "HIR_PRIVATE.h"

#include "GPIO_INTERFACE.h"

u8 flag=0,counter=0,data=0;
u8 EXTI_flag=0;
u32 arr[33]={0};


void HIR_Frame_Hanler(void)
{
//	MGPIO_SetPinValue(PORTA,PIN0,HIGH);///////////////////
//	MSYSTICK_voidDelayms(2000);
//	MGPIO_SetPinValue(PORTA,PIN0,LOW);///////////////////

	EXTI_flag=1;
	if(flag==0)
	{
		flag=1;
		MSYSTICK_voidCtrlIntState(ENABLED);
		MSYSTICK_voidStart(40000);
	}
	else
	{
		arr[counter]=MSYSTICK_u32GetElapsedTime();
		MSYSTICK_voidStart(40000);
		counter++;
	}



 }

void HIR_Data_Handler(void)
{
	if(EXTI_flag==1)
	{
		flag=0;
		counter=0;

		for(u8 i=0;i<8;i++)
		{
			if(arr[24-i]>=1000 && arr[24-i]<=1500)
			{
				CLR_BIT(data,i);
			}
			else if(arr[24-i]>=2000 && arr[24-i]<=2500)
			{
				SET_BIT(data,i);
			}
		}

	}

	MSYSTICK_voidCtrlIntState(DISABLED);

}
