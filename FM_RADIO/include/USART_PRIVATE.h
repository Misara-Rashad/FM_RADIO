/*
 * USART_PRIVATE.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Misra
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_



#define MSUART1_BASE_ADDRESS		(0x40011000)
#define MSUART2_BASE_ADDRESS		(0x40004400)
#define MSUART6_BASE_ADDRESS		(0x40011400)



typedef struct{
	u32	PE:1		;
	u32	FE:1		;
	u32	NF:1		;
	u32	ORE:1		;
	u32	IDLE:1		;
	u32	RXNE:1		;
	u32	TC:1		;
	u32	TXE:1		;
	u32	LBD:1		;
	u32	CTS:1		;
	u32	RESRVED:22	;

}MSUART_SR;



typedef struct{
	u32 SBK:1		;
	u32 RWU:1		;
	u32 RE:1		;
	u32 TE:1		;
	u32 IDLEIE:1		;
	u32 RXNEIE:1		;
	u32 TCIE:1		;
	u32 TXEIE:1		;
	u32 PEIE:1		;
	u32 PS:1		;
	u32 PCE:1		;
	u32 WAKE:1		;
	u32 M:1			;
	u32 UE:1		;
	u32 Reserved:1	;
	u32 OVER8:1		;
	u32	reserved2:16;
}MSUART_CR1;

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}MSUART_t;



#define USART1			((MSUART_t*)MSUART1_BASE_ADDRESS)
#define USART2			((MSUART_t*)MSUART2_BASE_ADDRESS)
#define USART6			((MSUART_t*)MSUART6_BASE_ADDRESS)


#endif /* USART_PRIVATE_H_ */
