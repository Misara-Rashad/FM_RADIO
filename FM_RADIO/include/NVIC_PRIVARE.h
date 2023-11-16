/*
 * NVIC_PRIVARE.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Misra
 */

#ifndef NVIC_PRIVARE_H_
#define NVIC_PRIVARE_H_

/*		BASE ADDRESS*/
#define NVIC_BASE_ADDRESS		0xE000E100
/*********************************/


typedef struct
{
	u32 ISER[8];
	u32 RESERVED1[24];
	u32 ICER[8];
	u32 RESERVED2[24];
	u32 ISPR[8];
	u32 RESERVED3[24];
	u32 ICPR[8];
	u32 RESERVED4[24];
	u32 IABR[8];
	u32 RESERVED5[56];
	u8 IPR[240];
	u32 RESERVED6[580];
	u32 STIR;
}NVIC_t;



#define NVIC    ((NVIC_t*)NVIC_BASE_ADDRESS)


#define AIRCR		(*(u32*)0xE000ED0C)




#define REG_DIV			32





#endif /* NVIC_PRIVARE_H_ */
