/*
 * GPIO_PROGRAM.C
 *
 *  Created on: Sep 10, 2023
 *      Author: Misra
 */



/*		includes section*/
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "GPIO_INTERFACE.h"
#include "GPIO_CONFIG.h"
#include "GPIO_PRIVATE.h"
/*****************************/

/*
 * MGPIO_SetMode function select between input or output modes for each pin
 */
void MGPIO_SetMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)	//INPUT OR OUTPUT
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOA->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2)) ;

			break;

		case PORTB:
			GPIOB->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOB->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2)) ;
			break;

		case PORTC:
			GPIOC->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOC->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2)) ;
			break;

		case PORTD:
			GPIOD->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOD->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2)) ;
			break;

		case PORTE:
			GPIOE->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOE->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2));
			break;

		case PORTH:
			GPIOH->MODER &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2)) ;
			GPIOH->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2)) ;
			break;

		default:
			break;
		}
	}
}





/*
 * MGPIO_SetOutputPinMode function sets type of pin from 2 selections:
 * 1.PUSH PULL
 * 2.OPEN DRAIN
 * select between four speeds for each  pin:
 * 1.LOW_SPEED
 * 2.MEDIUM_SPEED
 * 3.HIGH_SPEED
 * 4.VERY_HIGH_SPEED
 */
void MGPIO_SetOutputPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Speed,u8 Copy_u8Type) 	//PUSH_PULL OR OPEN_DRAIN
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOA->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOA->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));

			break;

		case PORTB:
			GPIOB->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOB->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOB->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
			break;

		case PORTC:
			GPIOC->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOC->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOC->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
			break;

		case PORTD:
			GPIOD->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOD->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOD->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOD->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
			break;

		case PORTE:
			GPIOE->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOE->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOE->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOE->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
			break;

		case PORTH:
			GPIOH->OTYPER &=~(1<<(Copy_u8Pin));
			GPIOH->OTYPER |=(Copy_u8Type<<(Copy_u8Pin));

			GPIOH->OSPEEDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOH->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
			break;

		default:
			break;
		}
	}

}




/*
 * MGPIO_SetInputPin function selects input pin mode from 2 selection:
 * 1.PULL_DOWN
 * 2.PULL_UP
 */
void MGPIO_SetInputPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8InputMode )		//PULL_DOWN OR PULL_UP
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		case PORTB:
			GPIOB->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		case PORTC:
			GPIOC->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		case PORTD:
			GPIOD->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOD->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		case PORTE:
			GPIOE->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOE->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		case PORTH:
			GPIOH->PUPDR &=~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOH->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
			break;

		default:
			break;
		}
	}
}




/*
 * MGPIO_GetPinValue function reads pin value from IDR register
 */
void MGPIO_GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8*  Copy_pu8Value)		//GET PIN VALUE
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{

		switch(Copy_u8Port)
		{
		case PORTA:
			*Copy_pu8Value=GET_BIT(GPIOA->IDR,Copy_u8Pin);
			break;

		case PORTB:
			*Copy_pu8Value=GET_BIT(GPIOB->IDR,Copy_u8Pin);
			break;

		case PORTC:
			*Copy_pu8Value=GET_BIT(GPIOC->IDR,Copy_u8Pin);
			break;

		case PORTD:
			*Copy_pu8Value=GET_BIT(GPIOD->IDR,Copy_u8Pin);
			break;

		case PORTE:
			*Copy_pu8Value=GET_BIT(GPIOE->IDR,Copy_u8Pin);
			break;

		case PORTH:
			*Copy_pu8Value=GET_BIT(GPIOH->IDR,Copy_u8Pin);
			break;

		default:
			break;
		}
	}
}





/*
 * MGPIO_SetPinValue function sets pin value
 * 1.LOW
 * 2.HIGH
 */
void MGPIO_SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			if(Copy_u8Value==LOW)
			{
				GPIOA->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOA->ODR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTB:
			if(Copy_u8Value==LOW)
			{
				GPIOB->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOB->ODR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTC:
			if(Copy_u8Value==LOW)
			{
				GPIOC->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOC->ODR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTD:
			if(Copy_u8Value==LOW)
			{
				GPIOD->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOD->ODR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTE:
			if(Copy_u8Value==LOW)
			{
				GPIOE->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOE->ODR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTH:
			if(Copy_u8Value==LOW)
			{
				GPIOH->ODR &=~(1<<Copy_u8Pin);
			}
			else if(Copy_u8Value==HIGH)
			{
				GPIOH->ODR |=(1<<Copy_u8Pin);
			}
			break;

		default:
			break;
		}
	}
}





/*
 * MGPIO_SetResetValue function performs atomic instruction to set or reset any pin
 */
void MGPIO_SetResetValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8SetOrReset)
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOA->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOA->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTB:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOB->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOB->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTC:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOC->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOC->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTD:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOD->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOD->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTE:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOE->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOE->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		case PORTH:
			if(Copy_u8SetOrReset==RESET)
			{
				GPIOH->BSRR |=(1<<(Copy_u8Pin+16));
			}
			else if(Copy_u8SetOrReset==SET)
			{
				GPIOH->BSRR |=(1<<Copy_u8Pin);
			}
			break;

		default:
			break;
		}
	}
}



void MGPIO_PinAlternateFunction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AlternateFunction)
{
	if(DEBUG_PINS)			//WRITE DEBUG PINS
	{
		//DO NO THING
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOA->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOA->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOA->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOA->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		case PORTB:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOB->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOB->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOB->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOB->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		case PORTC:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOC->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOC->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOC->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOC->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		case PORTD:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOD->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOD->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOD->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOD->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		case PORTE:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOE->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOE->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOE->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOE->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		case PORTH:
			if(Copy_u8Pin<=PIN7)
			{
				GPIOH->AFRL &=~(GPIO_AF_MASK<<(Copy_u8Pin*4));
				GPIOH->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOH->AFRH &=~(GPIO_AF_MASK<<(Copy_u8Pin%8*4));
				GPIOH->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin%8*4));
			}
			break;

		default:
			break;
		}
	}
}
