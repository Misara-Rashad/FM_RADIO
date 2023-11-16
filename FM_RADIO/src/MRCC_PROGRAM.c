/*
 * MRCC_PROGRAM.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Misra
 */


#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"


#include "MRCC_INTERFACE.h"
#include "MRCC_CONFIG.h"
#include "MRCC_PRIVATE.h"



/*
 * MRCC_INIT function enable system clock by selecting between three modes
 * 1.HSE
 * 2.HSI
 * 3.PLL
 */
void MRCC_INIT(void)
{
#if (SYS_CLK==HSE)
	SET_BIT(RCC-> CR,HSE_ON);				//enable HSE clock
	while(!GET_BIT(RCC->CR,HSE_RDY));		//wait until HSE becomes ready
	(RCC->CFGR)&=SWITCH_MASK;				//after HSE becomes ready switch to HSE clock
	(RCC->CFGR)|=SWITCH_HSE;

#elif (SYS_CLK==HSI)
	SET_BIT(RCC->CR,HSI_ON);				//enable HSI clock
	while(!GET_BIT(RCC->CR,HSI_RDY));		//wait until HSI becomes ready
	(RCC->CFGR)&=SWITCH_MASK;				//after HSI becomes ready switch to HSI clock
	(RCC->CFGR)|=SWITCH_HSI;

#elif (SYS_CLK==PLL)
	SET_BIT(RCC->CR,PLL_ON);				//enable PLL clock
	while(!GET_BIT(RCC->CR,PLL_RDY));		//wait until PLL becomes ready
	(RCC->CFGR)&=SWITCH_MASK;				//after PLL becomes ready switch to PLL clock
	(RCC->CFGR)|=SWITCH_PLL;

#endif
}




/*
 * MRCC_ENABLE_PERIPHERAL function Enable clock for specific peripheral
 * through its address bus
 */
void MRCC_ENABLE_PERIPHERAL(u32 copy_32AddressBus,u32 copy_32peripheral)
{
	switch(copy_32AddressBus)
	{
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,copy_32peripheral);
		break;

	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,copy_32peripheral);
		break;

	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,copy_32peripheral);
		break;

	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,copy_32peripheral);
		break;

	default:
		break;
	}
}





/*
 * MRCC_DISABLE_PERIPHERAL function Disable clock for specific peripheral
 * through its address bus
 */
void MRCC_DISABLE_PERIPHERAL(u32 copy_32AddressBus,u32 copy_32peripheral)
{
	switch(copy_32AddressBus)
	{
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,copy_32peripheral);
		break;

	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,copy_32peripheral);
		break;

	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,copy_32peripheral);
		break;

	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,copy_32peripheral);
		break;

	default:
		break;
	}
}






