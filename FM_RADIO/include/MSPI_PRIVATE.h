/*
 * MSPI_PRIVATE.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Misra
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define SPI1_BASE_ADDRESS					(0x40013000)
#define SPI2_BASE_ADDRESS					(0x40003800)
#define SPI3_BASE_ADDRESS					(0x40003C00)
#define SPI4_BASE_ADDRESS					(0x40013400)




typedef struct{
	u32 CR1;			//0x00
	u32 RESERVED;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_t;


#define SPI1				((volatile SPI_t*)SPI1_BASE_ADDRESS)
#define SPI2				((volatile SPI_t*)SPI2_BASE_ADDRESS)
#define SPI3				((volatile SPI_t*)SPI3_BASE_ADDRESS)
#define SPI4				((volatile SPI_t*)SPI4_BASE_ADDRESS)

//#define MSPI_BASE_ADRESS (0x40013000)
//
//
//
//typedef struct {
//	u32 CR1;
//	u32 reserve0;
//	u32 SR;
//	u32 DR;
//	u32 CRCPR;
//	u32 RXCRCR;
//	u32 TXCRCR;
//	u32 I2SCFGR;
//	u32 I2SPR;
//}MSPI_t;


#define SPI  ((volatile MSPI_t*)MSPI_BASE_ADRESS)



#endif /* MSPI_PRIVATE_H_ */
