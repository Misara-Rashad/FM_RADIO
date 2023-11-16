/*
 * MDMA_PROGRAM.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Misra
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MDMA_INTERFACE.h"
#include "../include/MDMA_PRIBVATE.h"
#include "../include/MDMA_CONFIG.h"



//static void (*DMA2_S0_ptr[8])(void);
//
//void DMA2_Init(void)
//{
//
//}
//
//void DMA2_SetStreamConfiguration(u8 Copy_u8StreamID,
//								u8 Copy_u8ChannelID,
//								u32 *Copy_pu32SourceAddress,
//								u32 *Copy_pu32DestinationAddress,
//								u8 Copy_u8ElementSize,
//								u16 Copy_u16BlockSize)
//{
//
//}
//
//
//void DMA2_SetCallBack(u8 Copy_u8StreamID,void(*ptr)(void))
//{
//
//}
//
//void DMA2_EnableStream(u8 Copy_u8StreamID)
//{
//
//}
//
//void DMA2_Stream0_IRQHandler(void)
//{
//
//}
//




static void (*DMA2_S0_ptr[8]) (void)={((void*)0)};



/* initialisation function */
void DMA2_Init(void)
{
	/* When the EN (Stream Enable) bit is read as 0,
	the software is allowed to program the Configuration*/
	MDMA2->S[0].CR &=~(1<<0);
	/* bit 10 for increment memory address
	 * bit 9 for increment peripheral address
	 * bit 7 for data transfer direction (we set it as memory to memory
	 * bit 4 for transfer complete interrupt enable */
	MDMA2->S[0].CR =(1<<10) | (1<<9) | (1<<7) | (1<<4);
	/* bit 0,1 FIFO threshold selection bits used to select the FIFO mode
	 * bit 2 Direct mode disable bot used to enable and disable the direct mode */
	MDMA2->S[0].FCR =(1<<2) | (1<<1) | (1<<0);

}



/* Set the configuration of the streams */
void DMA2_SetStreamConfiguration(u8 Copy_u8StreamID,
		u8 Copy_u8ChannelID,
		u8 *Copy_pu32SourceAddress,
		u32 *Copy_pu32DestinationAddress,
		u8 Copy_u8ElementSize,
		u16 Copy_u16BlockLength)
{
	/* When the EN (Stream Enable) bit is read as 0,
		the software is allowed to program the Configuration*/
	MDMA2->S[Copy_u8StreamID].CR &=~(1<<0);
	/* select the given channel */
	MDMA2->S[Copy_u8StreamID].CR |=(Copy_u8ChannelID<<25);
	/* These bits are set to one when i choose the Memory and peripheral element size */
	MDMA2->S[Copy_u8StreamID].CR |=((Copy_u8ElementSize<<13)|(Copy_u8ElementSize<<11));
	/* put the given number for block length into NDTR Register */
	MDMA2->S[Copy_u8StreamID].NDTR =Copy_u16BlockLength;
	/* put the given number for SourceAddress into 	M0AR Register */
	MDMA2->S[Copy_u8StreamID].M0AR =Copy_pu32SourceAddress;
	/* put the given number for DestinationAddress into 	M1AR Register */
	MDMA2->S[Copy_u8StreamID].M1AR =Copy_pu32DestinationAddress;
}



/* clear the interrupt flag clear register */
void DMA2_enableStream(u8 Copy_u8StreamID)
{
	/* clear interrupt flag for stream 0 */
	MDMA2->LIFC =(1<<0)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
	/* bit 0 for Stream enable again after finishing the configuration */
	MDMA2->S[Copy_u8StreamID].CR |=(1<<0);
}


/* call back function */
void DMA2_SetCallBack(u8 Copy_u8StreamID,void (*ptr)(void))
{
	if(ptr!=NULL_PTR){
		DMA2_S0_ptr[Copy_u8StreamID]=ptr;
	}
	else
	{
		/*Do nothing */
	}
}

/* interrupt handler function */
void DMA2_Stream0_IRQHandler(void)
{
	if(DMA2_S0_ptr!=NULL_PTR){
		DMA2_S0_ptr[0]();

	}
	else
	{
		/*Do nothing */
	}
}

