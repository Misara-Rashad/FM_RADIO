/*
 * NVIC_PROGRAM.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Misra
 */

/*		includes section		*/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "../include/NVIC_INTERFACE.h"
#include "../include/NVIC_CONFIG.h"
#include "../include/NVIC_PRIVARE.h"
/**********************************/

/*		GLOBAL VARIABLES		*/
static u8 Global_u8PIR=0;
/**********************************/



/*
 * MNVIC_voidEnableInterrupt function enables interrupt by number in vector
 * table
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos)
{
	NVIC->ISER[Copy_u8IntPos/32]  |= (1<<(Copy_u8IntPos%REG_DIV));
}


/*
 * MNVIC_voidDisableInterrupt function disable interrupt by number in vector
 * table
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos)
{
	NVIC->ICER[Copy_u8IntPos/32]  |= (1<<(Copy_u8IntPos%REG_DIV));
}


/*
 * MNVIC_voidEnableInterruptPending function sets pending flag
 */
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntPos)
{
	NVIC->ISPR[Copy_u8IntPos/32]  |= (1<<(Copy_u8IntPos%REG_DIV));
}


/*
 * MNVIC_voidDisableInterruptPending function clear pending flag
 */
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntPos)
{
	NVIC->ICPR[Copy_u8IntPos/32]  |= (1<<(Copy_u8IntPos%REG_DIV));
}


/*
 * MNVIC_IsInterruptActive function gets the status of interrupt
 * by number in vector table
 */
void MNVIC_IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read)
{
	*Copy_Read=GET_BIT(NVIC->IABR[Copy_u8IntPos/32],(Copy_u8IntPos%REG_DIV));

}


/*
 * MNVIC_voidSetInterruptGroupMode function selects the group mode for
 * the NVIC system
 */
void MNVIC_voidSetInterruptGroupMode(MNVIC_Group_t Copy_GroupMode)
{
	Global_u8PIR=Copy_GroupMode;
	u32 Copy_To_AIRCR=(0X05FA<<16) |(Copy_GroupMode<<8);
	AIRCR=Copy_To_AIRCR;			//YOU MUST WRITE TO THIS REG AT ONCE
}



/*
 * MNVICSetInterruptPriority function sets a group priority and sub group
 * priority for interrupt
 */
void MNVICSetInterruptPriority(u8 Copy_u8IntPos,u8 GroupNum,u8 Copy_u8SubGroupNum)
{
	switch(Global_u8PIR)
	{
	case GROUP16_SUBNONE:
		NVIC->IPR[Copy_u8IntPos]=GroupNum<<4;
		break;

	case GROUP8_SUB2:
		NVIC->IPR[Copy_u8IntPos]=GroupNum<<5 | Copy_u8SubGroupNum<<4 ;
			break;

	case GROUP4_SUB4:
		NVIC->IPR[Copy_u8IntPos]=GroupNum<<6 | Copy_u8SubGroupNum<<4 ;
			break;

	case GROUP2_SUB8:
		NVIC->IPR[Copy_u8IntPos]=GroupNum<<7 | Copy_u8SubGroupNum<<4 ;
			break;

	case GROUPNONE_SUB16:
		NVIC->IPR[Copy_u8IntPos]=Copy_u8SubGroupNum<<4;
			break;
	}
}
