/*
 * MSPI_INTERFACE.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Misra
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


/*		MSPI_STATUS		*/
#define MSPI_DISABLE 			0
#define MSPI_ENABLE 			1
/**********************************/

/*		MSPI1_DATA_FRAME		*/
#define SPI_DATA_8BIT			0
#define SPI_DATA_16BIT			1
/**********************************/

/*		MSPI1_MASTER_SLAVE		*/
#define MSPI_SLAVE						0
#define MSPI_MASTER						1
/**********************************/

/*		MSPI1_PRESCALAR		*/
#define MSPI_FPCLK_DIVIDED_BY_2			0
#define MSPI_FPCLK_DIVIDED_BY_4			1
#define MSPI_FPCLK_DIVIDED_BY_8			2
#define MSPI_FPCLK_DIVIDED_BY_16		3
#define MSPI_FPCLK_DIVIDED_BY_32		4
#define MSPI_FPCLK_DIVIDED_BY_64		5
#define MSPI_FPCLK_DIVIDED_BY_128		6
#define MSPI_FPCLK_DIVIDED_BY_256		7
/**********************************/

/*		MSPI1_DATA_ORDER		*/
#define MSPI_MSB_FIRST			0
#define MSPI_LSB_FIRST			1
/**********************************/

/*		MSPI1_CPOL_MODE		*/
#define CK_0_IDLE						0
#define CK_1_IDLE						1
/**********************************/

/*		MSPI1_CPHA_MODE		*/
#define FIRST_FRIST_DATA_CAPTURED		0
#define SECOND_FRIST_DATA_CAPTURED		1
/**********************************/

/*		MSPI1_SS_MANAGE		*/
#define HW_SLAVE_MANAGEMENT		0
#define SW_SLAVE_MANAGEMENT		1
/**********************************/

/*		MSPI1_INT_STATUS		*/
#define MSPI_INT_DIASBLE		0
#define MSPI_INT_ENABLED		1
/*********************************/

























void MSPI_voidInit(void);
void MSPI_voidSendData(u16 Copy_u16Data);
void MSPI_SetCallBack(void(*ptr)(void),u8 Copy_SpiIndex);


//void MSPI_voidInit(void);
//u8 MSPI_u16Trancieve(u8 Copy_u8Data);


#endif /* MSPI_INTERFACE_H_ */
