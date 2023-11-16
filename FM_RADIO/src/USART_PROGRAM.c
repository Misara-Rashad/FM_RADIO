/*
 * USART_PROGRAM.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Misra
 */



#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/USART_INTERFACE.h"
#include "../include/USART_CONFIG.h"
#include "../include/USART_PRIVATE.h"

void (*USART1_CALLBACK)(void);

void MUSART_voidInit(void)
{
	u32 config=0;
	config |=(USART1_SAMPLING_SELECTED<< 15)
			|(USART1_WORD_LENGTH<<12)
			|(USART1_PARITY_STATUS<<10)
			|(USART1_PARITY_SELECTION<<9)
			|(USART1_TRANSMIT_STATUS<<3)
			|(USART1_RECEIVER_STATUS<<2);
	USART1->CR1=config;

	config=0;
	config |=(USART1_STOP_BITS_SELECTION<<12)
			|(USART_CLK_PIN_STATUS<<11)
			|(USART1_CPOL_STATUS<<10)
			|(USART1_CPHA_STATUS<<9);
	USART1->CR2=config;

	config=0;
	config |=(USART1_HALF_DUPLEX_SELECTED<<3);
	USART1->CR3=config;

	config=0;
	config |=(USART1_PRESCALAR_SLECTED<<0);
	USART1->GTPR=config;

#if USART1_SAMPLING_SELECTED==OVER16
	USART1->BRR=BAUD_RATE_9600_OVER16;

#else if USART1_SAMPLING_SELECTED==OVER8
	USART1->BRR=BAUD_RATE_9600_OVER8;

#endif
}

void MUSART_Transmit(u8* Copy_u8Data,u8 Copy_u8Length)
{
	for(u8 i=0;i<Copy_u8Length;i++)
	{
		USART1->DR=Copy_u8Data[i];
		while(GET_BIT(USART1->SR,7));
	}
}

u8 MUSART_Receive(void)
{
	while(GET_BIT(USART1->SR,5));
	return USART1->DR;
}

void MUSART_voidEnable(void)
{
	USART1->CR1 |=(1<<13);
}

void MUSART_voidDisable(void)
{
	USART1->CR1 &=~(1<<13);
}

void MUSART_voidCallBack(void(*ptr)(void))
{
	USART1_CALLBACK=ptr;
}



void USART1_IRQHandler(void)
{
	USART1_CALLBACK();
}
