/*
 * GPIO_INTERFACE.H
 *
 *  Created on: Sep 10, 2023
 *      Author: Misra
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/*		PINS_CONFIGURATION		*/
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15
/*************************************/



/*		PORTS_CONFIGURATION		*/
#define PORTA		0
#define PORTB		1
#define PORTC		2
#define PORTD		3
#define PORTE		4
#define PORTH		5
/*************************************/



/*		PINS_MODES		*/
#define INPUT		0
#define OUTPUT		1
#define ALT_FUNC	2
#define ANALOG		3
/*************************************/







/*		OUTPUT_MODE_SELECTION		*/
#define OUTPUT_PUSH_PULL	0
#define OUTPUT_OPEN_DRAIN	1
/*************************************/



/*		OUTPUT_SPEED_SELECTION		*/
#define LOW_SPEED			0
#define MEDIUM_SPEED		1
#define HIGH_SPEED			2
#define	VERY_HIGH_SPEED		3
/*************************************/


/*		PULL_UP_DOWN_SELECTION		*/
#define NO_PULL_UP_DOWN		0
#define	PULL_UP				1
#define	PULL_DOWN			2
/*************************************/


/*		OUTPUT_VALUES		*/
#define LOW					0
#define HIGH				1
/*************************************/


/*		SET_RESET_SELECTION		*/
#define RESET				0
#define SET					1
/*************************************/

/*		Alternate function selection		*/
#define AF0					0
#define AF1					1
#define AF2					2
#define AF3					3
#define AF4					4
#define AF5					5
#define AF6					6
#define AF7					7
#define AF8					8
#define AF9					9
#define AF10				10
#define AF11				11
#define AF12				12
#define AF13				13
#define AF14				14
#define AF15				15
/*************************************/


#define GPIO_MODE_MASK		3
#define GPIO_AF_MASK		16

#define COUNT_FLAG			16

/*		GPIO_INTERFACE		*/
void MGPIO_SetMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);	//INPUT OR OUTPUT
void MGPIO_SetOutputPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed,u8 Copy_u8Type); 	//PUSH_PULL OR OPEN_DRAIN
void MGPIO_SetInputPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8InputMode );		//PULL_DOWN OR PULL_UP
void MGPIO_GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8*  Copy_pu8Value);		//GET PIN VALUE
void MGPIO_SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
void MGPIO_SetResetValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8SetOrReset);
void MGPIO_PinAlternateFunction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AlternateFunction);
/*************************************/


#endif /* GPIO_INTERFACE_H_ */
