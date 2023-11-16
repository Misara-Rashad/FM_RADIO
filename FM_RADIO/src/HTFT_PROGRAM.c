/*
 * HTFT_PROGRAM.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Misra
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_INTERFACE.h"
#include "../include/MSPI_INTERFACE.h"
#include "../include/SYSTICK_INTERFACE.h"
#include "../include/HTFT_INTERFACE.h"
#include "../include/HTFT_CONFIG.h"

static void TFT_voidWriteCMD(u8 Copy_u8CMD);
static void TFT_voidWriteDATA(u8 Copy_u8DATA);


static void TFT_voidWriteCMD(u8 Copy_u8CMD)
{
	MGPIO_SetPinValue(A0_PORT,A0_PIN,LOW);
	MSPI_voidSendData(Copy_u8CMD);
}

static void TFT_voidWriteDATA(u8 Copy_u8DATA)
{
	MGPIO_SetPinValue(A0_PORT,A0_PIN,HIGH);
	MSPI_voidSendData(Copy_u8DATA);
}

void TFT_voidInit(void)
{
	MGPIO_SetPinValue(RESET_PORT,RESER_PIN,HIGH);
	MSYSTICK_voidDelayMs(100);

	MGPIO_SetPinValue(RESET_PORT,RESER_PIN,LOW);
	MSYSTICK_voidDelayMs(1);

	MGPIO_SetPinValue(RESET_PORT,RESER_PIN,HIGH);
	MSYSTICK_voidDelayMs(100);

	MGPIO_SetPinValue(RESET_PORT,RESER_PIN,LOW);
	MSYSTICK_voidDelayMs(100);

	MGPIO_SetPinValue(RESET_PORT,RESER_PIN,HIGH);
	MSYSTICK_voidDelayms(120);


	//sleep out command
	TFT_voidWriteCMD(0x11);
	MSYSTICK_voidDelayms(150);

	//color mode selection
	TFT_voidWriteCMD(0x3A);
	TFT_voidWriteDATA(0x05);		//RGB 565

	//display on
	TFT_voidWriteCMD(0x29);

	//set x
	TFT_voidWriteCMD(0x2A);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(127);

	//set y
	TFT_voidWriteCMD(0x2B);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(0);
	TFT_voidWriteDATA(159);


	//RAM write
	TFT_voidWriteCMD(0x2c);

}



void TFT_voidSendImage(const u16 * ptr_to_image)
{
	for(u16 i=0;i<20480;i++)
		{
			TFT_voidWriteDATA(ptr_to_image[i]>>8);
			TFT_voidWriteDATA(ptr_to_image[i]);
		}
}

