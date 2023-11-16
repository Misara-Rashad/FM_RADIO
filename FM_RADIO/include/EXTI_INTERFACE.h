/*
 * EXTI_INTERFACE.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTI_LINE;


typedef enum{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTE,
	EXTI_PORTH=7,
}EXTI_PORT;



typedef enum{
	FALLING_EDGE,RISING_EDGE,RISING_FALLING_EDGES
}EXTI_Trigger;

typedef enum{
	EXTI_DISABLED,EXTI_ENABLED
}EXTI_STATE;

/*		MEXTI interface		*/
void MEXTI_voidInterruptSetport(EXTI_LINE Copy_u8Line,EXTI_PORT Copy_u8Port);
void MEXTI_voidInterruptEnableDisable(EXTI_LINE Copy_u8Line,EXTI_STATE Copy_u8State );
void MEXTI_voidInterruptTrigger(EXTI_LINE Copy_u8Line,EXTI_Trigger Copy_u8Trig);
void MEXTI_voidCallBack(void(*ptr)(void),EXTI_LINE Copy_u8Line );
/***************************************************/





#endif /* EXTI_INTERFACE_H_ */
