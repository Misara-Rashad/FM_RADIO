/*
 * H2R2DAC.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Misra
 */



/*		includes section		*/
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/H2R2DAC_CONFIG.h"
#include "../include/H2R2DAC_INTERFACE.h"
#include "../include/H2R2DAC_private.h"
#include "../include/GPIO_INTERFACE.h"
#include "../include/SYSTICK_INTERFACE.h"
/*********************************/



/*
 * H2R2DAC_voidInit function selects the pins that we will use in
 * R2R circuit
 */
void H2R2DAC_voidInit(void)
{
	MGPIO_SetMode(PORTA,PIN12,OUTPUT);
	MGPIO_SetMode(PORTA,PIN15,OUTPUT);
	MGPIO_SetMode(PORTC,PIN13,OUTPUT);
	MGPIO_SetMode(PORTC,PIN14,OUTPUT);
	MGPIO_SetMode(PORTB,PIN10,OUTPUT);
	MGPIO_SetMode(PORTB,PIN12,OUTPUT);
	MGPIO_SetMode(PORTB,PIN13,OUTPUT);
	MGPIO_SetMode(PORTB,PIN14,OUTPUT);

	MGPIO_SetOutputPinMode(PORTA,PIN12,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTA,PIN15,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTC,PIN13,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTC,PIN14,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTB,PIN10,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTB,PIN12,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTB,PIN13,MEDIUM_SPEED,OUTPUT_PUSH_PULL);
	MGPIO_SetOutputPinMode(PORTB,PIN14,MEDIUM_SPEED,OUTPUT_PUSH_PULL);

}



/*
 * HR2RDAC_voidSetData function gets the samples from .h file to set the output
 * values for pins
 */
void HR2RDAC_voidSetData(const u8 *arr,u32 arrSize)
{
	u32 Copy_u32localCounter=0;

	for(Copy_u32localCounter=0;Copy_u32localCounter<arrSize;Copy_u32localCounter++)
	{
		MGPIO_SetPinValue(PORTA,PIN12,GET_BIT(arr[Copy_u32localCounter],0));
		MGPIO_SetPinValue(PORTA,PIN15,GET_BIT(arr[Copy_u32localCounter],1));
		MGPIO_SetPinValue(PORTC,PIN13,GET_BIT(arr[Copy_u32localCounter],2));
		MGPIO_SetPinValue(PORTC,PIN14,GET_BIT(arr[Copy_u32localCounter],3));
		MGPIO_SetPinValue(PORTB,PIN10,GET_BIT(arr[Copy_u32localCounter],4));
		MGPIO_SetPinValue(PORTB,PIN12,GET_BIT(arr[Copy_u32localCounter],5));
		MGPIO_SetPinValue(PORTB,PIN13,GET_BIT(arr[Copy_u32localCounter],6));
		MGPIO_SetPinValue(PORTB,PIN14,GET_BIT(arr[Copy_u32localCounter],7));

		MSYSTICK_voidDelayMs(125);			//to apply 8000 samples per second
	}
}
