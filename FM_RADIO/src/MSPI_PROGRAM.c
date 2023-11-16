/*
 * MSPI_PROGRAM.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Misra
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_INTERFACE.h"

#include "../include/MSPI_INTERFACE.h"
#include "../include/MSPI_CONFIG.h"
#include "../include/MSPI_PRIVATE.h"



static void (*SPI_PTR[4])(void);


void MSPI_voidInit(void)
{
#if MSPI_STATUS==MSPI_ENABLE
	u32 configuration=0;
	configuration   |=(MSPI1_DATA_FRAME<<11)
					|(MSPI1_SS_MANAGE<<9)
					|(1<<8)						// SSI
					|(MSPI1_DATA_ORDER<<7)
					|(MSPI_ENABLE<<6)
					|(MSPI1_PRESCALAR<<3)
					|(MSPI1_MASTER_SLAVE<<2)
					|(MSPI1_CPOL_MODE<<1)
					|(MSPI1_CPHA_MODE<<0);

	SPI1->CR1=configuration;
	//SPI1->CR1=0x0347;

	configuration=0;

	configuration   |=(MSPI1_INT_STATUS<<7)
					|(MSPI1_INT_STATUS<<6)
					|(MSPI1_INT_STATUS<<5);

	SPI1->RESERVED=(u16)configuration;			//RESERVED is CR2

#endif
}

void MSPI_voidSendData(u16 Copy_u16Data)
{
	SPI1->DR=Copy_u16Data;
	while(GET_BIT(SPI1->SR,7)==1);
}

void MSPI_SetCallBack(void(*ptr)(void),u8 Copy_SpiIndex)
{
	SPI_PTR[Copy_SpiIndex-1]=ptr;
}


void SPI1_IRQHandler(void)
{
	SPI_PTR[0]();
}

void SPI2_IRQHandler(void)
{
	SPI_PTR[1]();
}

void SPI3_IRQHandler(void)
{
	SPI_PTR[2]();
}

void SPI4_IRQHandler(void)
{
	SPI_PTR[3]();
}





//void MSPI_voidInit(void){
//// make data frame format 8 bit
//SPI->CR1 &=~(1<<11);
//// config for CPOL and CPHA
//SPI->CR1 &=~(CPHA<<0);
//SPI->CR1 &=~(CPOL<<1);
////baud rate
//SPI->CR1 &=~((0b111)<<3);
//SPI->CR1 |=((BaudRate)<<3);
////MSB/LSB
//SPI->CR1 &=~(1<<7);
////select master or slave
//SPI->CR1 |=(1<<2);
//// SPI enable
//SPI->CR1 |=(1<<6);
//
//
//
//
//}
//u8 MSPI_u16Trancieve(u8 Copy_u8Data){
//SPI->DR =Copy_u8Data;
//while(GET_BIT(SPI->SR,7)==1);
//return (u8)SPI->DR;
//}
