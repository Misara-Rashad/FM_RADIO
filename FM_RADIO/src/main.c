/*		includes		*/
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_INTERFACE.h"
#include "../include/MRCC_INTERFACE.h"
#include "../include/EXTI_INTERFACE.h"
#include "../include/NVIC_INTERFACE.h"
#include "../include/SYSTICK_INTERFACE.h"
#include "../include/MSPI_INTERFACE.h"
#include "../include/HLEDMATRIX_INTERFACE.h"
#include "../include/HIR_INTERFACE.h"
#include "../include/HTFT_INTERFACE.h"
#include "../include/HTFT_CONFIG.h"
#include "../include/H2R2DAC_INTERFACE.h"
#include "../include/image.h"
#include "../include/image2.h"
#include "../include/Audio.h"
/********************************************************/



/*		macros used		*/
///* Remote Buttons */
#define REMOTE_BUTTON_1 48
#define REMOTE_BUTTON_2 24
#define REMOTE_BUTTON_3 122
#define REMOTE_BUTTON_4 16
#define REMOTE_BUTTON_5 56
#define REMOTE_BUTTON_6 90
#define REMOTE_BUTTON_7 66
#define REMOTE_BUTTON_8 74
#define REMOTE_BUTTON_9 82
#define REMOTE_BUTTON_INC 168
#define REMOTE_BUTTON_DEC 224
/********************************************************/



/*		global variables		*/
u8 Hamza[]={0, 102, 102, 126, 102, 102, 126, 0, 0, 126, 6, 28, 48, 96, 126, 0, 0, 66, 90, 90, 90, 126, 126, 0, 0, 102, 102, 126, 102, 102, 126, 0, 0, 102, 102, 126, 126, 102, 102, 0,0,0,0,0,0,0,0,0};
u8 Diab[]={0, 126, 70, 70, 70, 70, 126, 0, 0, 126, 24, 24, 24, 24, 126, 0, 0, 126, 66, 66, 126, 66, 66, 0, 0, 126, 70, 126, 126, 70, 126, 0,0,0,0,0,0,0,0,0};
/********************************************************/


int main()
{
	/*		RCC initialization		*/
	MRCC_INIT();
	MRCC_ENABLE_PERIPHERAL(RCC_AHB1,RCC_AHB1_GPIOAEN);
	MRCC_ENABLE_PERIPHERAL(RCC_AHB1,RCC_AHB1_GPIOBEN);
	MRCC_ENABLE_PERIPHERAL(RCC_AHB1, RCC_AHB1_GPIOCEN);
	MRCC_ENABLE_PERIPHERAL(RCC_APB2, RCC_APB2_SYSCFG);
	MRCC_ENABLE_PERIPHERAL(RCC_APB2,RCC_APB2_SPI1);

	/*      NVIC enable the EXTI15        */
	MNVIC_voidEnableInterrupt(40);

	/*		systick initialization		*/
	MSYSTICK_voidInit();
	MSYSTICK_CallBack(HIR_Data_Handler);
	
	/*		spi initialization		*/
	MSPI_voidInit();

	MGPIO_SetMode(A0_PORT,A0_PIN,OUTPUT);			//A0
	MGPIO_SetOutputPinMode(A0_PORT,A0_PIN,LOW_SPEED,OUTPUT_PUSH_PULL);


	MGPIO_SetMode(RESET_PORT,RESER_PIN,OUTPUT);			//RESET pin
	MGPIO_SetOutputPinMode(RESET_PORT,RESER_PIN,LOW_SPEED,OUTPUT_PUSH_PULL);

	MGPIO_SetMode(PORTA,PIN5,ALT_FUNC);				//spi sck pin
	MGPIO_PinAlternateFunction(PORTA,PIN5,AF5);

	MGPIO_SetMode(PORTA,PIN7,ALT_FUNC);				//spi mosi pin
	MGPIO_PinAlternateFunction(PORTA,PIN7,AF5);


	TFT_voidInit();
	HLEDMATRIX_VoidInit();
	H2R2DAC_voidInit();

	/*      set EXTI15 for PORTC*/
	MEXTI_voidInterruptSetport(EXTI_LINE15, EXTI_PORTC);
	MEXTI_voidInterruptTrigger(EXTI_LINE15, FALLING_EDGE);
	MGPIO_SetInputPin(PORTC,PIN15,PULL_UP);

	/*      set call back for EXTI15        */
	MEXTI_voidCallBack(HIR_Frame_Hanler, EXTI_LINE15);

	/*      enable EXTI15       */
	MEXTI_voidInterruptEnableDisable(EXTI_LINE15, EXTI_ENABLED);

	u8 *ptr=NULL_PTR;
	u8 size=0;
	while(1)
	{


		if (data == REMOTE_BUTTON_1)
		{
			TFT_voidSendImage(image_data_HamzaNamara);
			ptr=Hamza;
			size=40;
			data=0;
		}
		else if (data == REMOTE_BUTTON_2)
		{
			TFT_voidSendImage(image_data_AmrDiab);
			HR2RDAC_voidSetData(a_raw,120505);
			ptr=Diab;
			size=32;
			data=0;
		}

		if(ptr==Diab)
		{
			for(u8 i=0;i<size;i++)
			{
				for(u8 j=0;j<5;j++)
				{
					HLEDMATRIX_VoidSDisplay(ptr);
				}
				ptr++;
			}
			ptr=Diab;
		}
		else if (ptr==Hamza)
		{
			for(u8 i=0;i<size;i++)
			{
				for(u8 j=0;j<10;j++)
				{
					HLEDMATRIX_VoidSDisplay(ptr);
				}
				ptr++;
			}
			ptr=Hamza;
		}


	}
	return 0;
}