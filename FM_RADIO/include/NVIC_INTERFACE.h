/*
 * NVIC_INTERFACE.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Misra
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum{
GROUP16_SUBNONE=3,GROUP8_SUB2,GROUP4_SUB4,GROUP2_SUB8,GROUPNONE_SUB16
}MNVIC_Group_t;

/*			NVIC INTERFACE		*/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos);
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntPos);
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntPos);
void MNVIC_IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read);
void MNVIC_voidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode);
void MNVICSetInterruptPriority(u8 Copy_u8IntPos,u8 GroupNum,u8 Copy_u8SubGroupNum);
/******************************************/

#endif /* NVIC_INTERFACE_H_ */
