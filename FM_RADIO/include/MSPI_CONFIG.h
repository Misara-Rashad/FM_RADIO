/*
 * MSPI_CONFIG.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Misra
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

#define MSPI_STATUS					MSPI_ENABLE

#define MSPI1_DATA_FRAME			SPI_DATA_8BIT

#define MSPI1_MASTER_SLAVE			MSPI_MASTER

#define MSPI1_PRESCALAR				MSPI_FPCLK_DIVIDED_BY_2

#define MSPI1_DATA_ORDER			MSPI_MSB_FIRST

#define MSPI1_CPOL_MODE				CK_1_IDLE

#define MSPI1_CPHA_MODE				SECOND_FRIST_DATA_CAPTURED

#define	MSPI1_SS_MANAGE				SW_SLAVE_MANAGEMENT

#define MSPI1_INT_STATUS			MSPI_INT_DIASBLE

#define MSPI_SS_PORT				PORTA

#define MSPI_SS_PIN					PIN0





//#define CPOL 1
//#define CPHA 1
//
//#define BaudRate  0b000





#endif /* MSPI_CONFIG_H_ */
