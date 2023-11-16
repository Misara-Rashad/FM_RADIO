/*
 * MDMA_INTERFACE.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Misra
 */

#ifndef MDMA_INTERFACE_H_
#define MDMA_INTERFACE_H_

//void DMA2_Init(void);
//
//void DMA2_SetStreamConfiguration(u8 Copy_u8StreamID,
//								u8 Copy_u8ChannelID,
//								u32 *Copy_pu32SourceAddress,
//								u32 *Copy_pu32DestinationAddress,
//								u8 Copy_u8ElementSize,
//								u16 Copy_u16BlockSize);
//
//
//void DMA2_SetCallBack(u8 Copy_u8StreamID,void(*ptr)(void));
//
//void DMA2_EnableStream(u8 Copy_u8StreamID);


/* initialisation function */
void DMA2_Init(void);

/* Set the configuration of the streams */
void DMA2_SetStreamConfiguration(u8 Copy_u8StreamID,
		                         u8 Copy_u8ChannelID,
								 u8 *Copy_pu32SourceAddress,
								 u32 *Copy_pu32DestinationAddress,
								 u8 Copy_u8ElementSize,
								 u16 Copy_u16BlockLength);

/* clear the interrupt flag clear register */
void DMA2_enableStream(u8 Copy_u8StreamID);

/* CallBack function */
void DMA2_SetCallBack(u8 Copy_u8StreamID,void (*ptr)(void));



#endif /* MDMA_INTERFACE_H_ */
