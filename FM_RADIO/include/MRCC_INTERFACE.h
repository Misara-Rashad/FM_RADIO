/*
 * MRCC_INTERFACE.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Misra
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_



/*  	buses		 */
#define RCC_APB1					0
#define RCC_APB2					1
#define RCC_AHB1					2
#define RCC_AHB2					3
/******************************************/


/*		APB1		*/
#define RCC_APB1_TIM2				0
#define RCC_APB1_TIM3				1
#define RCC_APB1_TIM4				2
#define RCC_APB1_TIM5				3

#define RCC_APB1_WWDG				11

#define RCC_APB1_SPI2				14
#define RCC_APB1_SPI3				15

#define RCC_APB1_USART2				17

#define RCC_APB1_I2C1				21
#define RCC_APB1_I2C2				22
#define RCC_APB1_I2C3				23

#define RCC_APB1_PWR				28
/******************************************/


/*		APB2		*/
#define	RCC_APB2_TIM1				0

#define	RCC_APB2_USART1				4
#define	RCC_APB2_USART6				5

#define	RCC_APB2_ADC1				8

#define	RCC_APB2_SDIO				11

#define	RCC_APB2_SPI1				12
#define	RCC_APB2_SPI4				13

#define	RCC_APB2_SYSCFG				14

#define	RCC_APB2_TIM9				16
#define	RCC_APB2_TIM10				17
#define	RCC_APB2_TIM11				18
/******************************************/

/*		AHB1		*/
#define RCC_AHB1_GPIOAEN			0
#define RCC_AHB1_GPIOBEN			1
#define RCC_AHB1_GPIOCEN			2
#define RCC_AHB1_GPIODEN			3
#define RCC_AHB1_GPIOEEN			4
#define RCC_AHB1_GPIOHEN			7

#define RCC_AHB1_CRCEN				12

#define RCC_AHB1_DMA1EN				21
#define RCC_AHB1_DMA2EN				22

/******************************************/


/*		AHB2		*/
#define RCC_AHB2_OTGFS				7
/******************************************/


/*		CLOCK_SELECTION		*/
#define HSE							0
#define HSI							1
#define PLL							2
/******************************************/




/*		APIS INTERFACE		*/
void MRCC_INIT(void);

void MRCC_ENABLE_PERIPHERAL(u32 copy_32AddressBus,u32 copy_32peripheral);

void MRCC_DISABLE_PERIPHERAL(u32 copy_32AddressBus,u32 copy_32peripheral);
/******************************************/
#endif /* MRCC_INTERFACE_H_ */
