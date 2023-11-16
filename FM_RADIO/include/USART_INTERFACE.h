/*
 * USART_INTERFACE.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Misra
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


#define USART1_OVER16				0
#define USART1_OVER8				1

#define USART1_DISABLED		0
#define USART1_ENABLED		1

#define DATA_8BIT			0
#define DATA_9BIT			1

#define PARITY_DISABLED		0
#define PARITY_ENABLED		1

#define EVEN_PARITY			0
#define ODD_PARITY			1

#define	TRASNMIT_DISABLED	0
#define TRANSMIT_ENABLED	1

#define RECEIVER_DISABLED	0
#define RECEIVER_ENABLED	1

#define STOPBITS_1			0
#define STOPBITS_HALF		1
#define STOPBITS_2			2
#define STOPBITS_ONEANDHALF		3

#define CLK_PIN_DISABLED	0
#define CLK_PIN_ENABLED		1

#define CPOL_LOW			0
#define CPOL_HIGH			1

#define CPHA_READ_FIRST		0
#define CPHA_WRITE_FIRST	1

#define HALF_DUPLEX_DISABLED	0
#define HALF_DUPLEX_ENABLED		1

#define PRESCALAR_2				1
#define PRESCALAR_4				2
#define PRESCALAR_6				3

#define BAUD_RATE_9600_OVER16			(0x683)
#define BAUD_RATE_9600_OVER8			(0xD00)



void MUSART_voidInit(void);
void MUSART_Transmit(u8* Copy_u8Data,u8 Copy_u8Length);
u8 MUSART_Receive(void);
void MUSART_voidEnable(void);
void MUSART_voidDisable(void);
void MUSART_voidCallBack(void(*ptr)(void));


#endif /* USART_INTERFACE_H_ */
