/*
 * MDMA_PRIBVATE.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Misra
 */

#ifndef MDMA_PRIBVATE_H_
#define MDMA_PRIBVATE_H_

//
//#define DMA1_BASE_ADDRESS		(0x40026000)
//#define DMA2_BASE_ADDRESS		(0x40026400)
//
//
//
//
//
//typedef struct{
//	u32 CR;
//	u32 NDTR;
//	u32 PAR;
//	u32 M0AR;
//	u32 M1AR;
//	u32 FCR;
//}DMA_STREAM_t;
//
//typedef struct{
//	u32 LISR;
//	u32 HISR;
//	u32 LIFCR;
//	u32 HIFCR;
//	DMA_STREAM_t s[8];
//}DMA_REG_t;
//
//#define DMA1		((DMA_REG_t*)DMA1_BASE_ADDRESS)
//#define DMA2		((DMA_REG_t*)DMA2_BASE_ADDRESS)
//



/* Base Address for DMA1,DMA2*/
#define MDMA1_BASE_ADDRESS  (0x40026000)
#define MDMA2_BASE_ADDRESS  (0x40026400)

//#define NULL_PRT  ((void*)0)


typedef struct
{
	u32 CR;
	u32 NDTR;
	u32 PAR;
	u32 M0AR;
	u32 M1AR;
	u32 FCR;
}DMA_STREAM_T;


typedef struct
{
	u32 LISR;
	u32 HISR;
	u32 LIFC;
	u32 HIFC;
	DMA_STREAM_T S[8];
}DMA_t;


/* CREATE POINTER FOR BASE ADDRESSES */
#define MDMA1 	((volatile DMA_t*)MDMA1_BASE_ADDRESS)

#define MDMA2	((volatile DMA_t*)MDMA2_BASE_ADDRESS)
#endif /* MDMA_PRIBVATE_H_ */
