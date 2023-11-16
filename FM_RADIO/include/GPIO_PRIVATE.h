/*
 * GPIO_PRIVATE.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Misra
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



#define DEBUG_PINS							((Copy_u8Port==PORTA)&& (Copy_u8Pin==PIN13 || Copy_u8Pin==PIN14 || Copy_u8Pin==PIN15 ))\
											|| ((Copy_u8Port==PORTB)&& (Copy_u8Pin==PIN3 || Copy_u8Pin==PIN4 ) )


/*			BASE_ADDRESSES		*/
#define GPIOA_BASE_ADDRESS				(0x40020000)
#define GPIOB_BASE_ADDRESS				(0x40020400)
#define GPIOC_BASE_ADDRESS				(0x40020800)
#define GPIOD_BASE_ADDRESS				(0x40020C00)
#define GPIOE_BASE_ADDRESS				(0x40021000)
#define GPIOH_BASE_ADDRESS				(0x40021C00)
/*************************************/



typedef struct{
u32 MODER;
u32 OTYPER;
u32 OSPEEDR;
u32 PUPDR;
u32 IDR;
u32 ODR;
u32 BSRR;
u32 LCKR;
u32 AFRL;
u32 AFRH;
}GPIO_t;


#define GPIOA		((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB		((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC		((volatile GPIO_t*)GPIOC_BASE_ADDRESS)
#define GPIOD		((volatile GPIO_t*)GPIOD_BASE_ADDRESS)
#define GPIOE		((volatile GPIO_t*)GPIOE_BASE_ADDRESS)
#define GPIOH		((volatile GPIO_t*)GPIOH_BASE_ADDRESS)



#endif /* GPIO_PRIVATE_H_ */
