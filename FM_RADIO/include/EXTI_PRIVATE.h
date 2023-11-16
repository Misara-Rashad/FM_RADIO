/*
 * EXTI_PRIVATE.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*		BASE ADDRESS*/
#define EXTI_BASE_ADDRESS			(0x40013C00)
#define SYSCFG_BASE_ADDRESS			(0x40013800)
/*********************************************/



typedef struct {
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;


typedef struct {
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 RESERVED[2];
	u32 CMPCR;
}SYSCFG_t;




#define EXTI			((volatile EXTI_t*)EXTI_BASE_ADDRESS)
#define SYSCFG			((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)

#endif /* EXTI_PRIVATE_H_ */
