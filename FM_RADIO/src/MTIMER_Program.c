









/* Standard Types File */
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

/* RCC Specified Header Files */
#include "../include/MTIMER_Interface.h"
#include "../include/MTIMER_Config.h"
#include "../include/MTIMER_Private.h"



void TIMER_Init(TIMER_configType *Configuration){
	if(Configuration->timer_id == TIMER2_SELECTION){
		TIMER2->CR1 = (Configuration->PreloadType    << ARPE)\
				|(Configuration->AlignedType         << CMS0)\
				|(Configuration->CountMode           << DIR )\
				|(Configuration->OnePulseMode        << OPM)\
				|(Configuration->UpdateRequestSource << URS);
		/* Adjust the slave mode selection */
		/* Use the internal clock */
		TIMER2->SMCR = 0;
		/* Set UG Bit */
		TIMER2->EGR = 1;

		/* Choose the Output Compare mode of the channel */
		if(Configuration->ChannelID == TIMER_CHANNEL_1){
			/* Adjust the output compare Channel Mode */
			TIMER2->CCMR1 = (TIMER2->CCMR1 & CHANNEL1_MASK)|(Configuration->Mode <<OC1M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER2->CCMR1,OC1PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER2->CCER , CC1P);
			}
			else{
				SET_BIT(TIMER2->CCER , CC1P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER2->CCER , CC1E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_2){
			/* Adjust the output compare Channel Mode */
			TIMER2->CCMR1 = (TIMER2->CCMR1 & CHANNEL2_MASK)|(Configuration->Mode <<OC2M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER2->CCMR1,OC2PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER2->CCER , CC2P);
			}
			else{
				SET_BIT(TIMER2->CCER , CC2P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER2->CCER , CC2E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_3){
			/* Adjust the output compare Channel Mode */
			TIMER2->CCMR2 = (TIMER2->CCMR2 & CHANNEL3_MASK)|(Configuration->Mode <<OC3M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER2->CCMR2,OC3PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER2->CCER , CC3P);
			}
			else{
				SET_BIT(TIMER2->CCER , CC3P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER2->CCER , CC3E);
		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_4){
			/* Adjust the output compare Channel Mode */
			TIMER2->CCMR2 = (TIMER2->CCMR2 & CHANNEL4_MASK)|(Configuration->Mode <<OC4M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER2->CCMR2,OC4PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER2->CCER , CC4P);
			}
			else{
				SET_BIT(TIMER2->CCER , CC4P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER2->CCER , CC4E);
		}

	}
	else if(Configuration->timer_id == TIMER5_SELECTION){
		TIMER5->CR1 = (Configuration->PreloadType    << ARPE)\
				|(Configuration->AlignedType         << CMS0)\
				|(Configuration->CountMode           << DIR )\
				|(Configuration->OnePulseMode        << OPM)\
				|(Configuration->UpdateRequestSource << URS);
		/* Adjust the slave mode selection */
		/* Use the internal clock */
		TIMER5->SMCR = 0;
		/* Set UG Bit */
		TIMER5->EGR = 1;

		/* Choose the Output Compare mode of the channel */
		if(Configuration->ChannelID == TIMER_CHANNEL_1){
			/* Adjust the output compare Channel Mode */
			TIMER5->CCMR1 = (TIMER5->CCMR1 & CHANNEL1_MASK)|(Configuration->Mode <<OC1M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER5->CCMR1,OC1PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER5->CCER , CC1P);
			}
			else{
				SET_BIT(TIMER5->CCER , CC1P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER5->CCER , CC1E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_2){
			/* Adjust the output compare Channel Mode */
			TIMER5->CCMR1 = (TIMER5->CCMR1 & CHANNEL2_MASK)|(Configuration->Mode <<OC2M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER5->CCMR1,OC2PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER5->CCER , CC2P);
			}
			else{
				SET_BIT(TIMER5->CCER , CC2P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER5->CCER , CC2E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_3){
			/* Adjust the output compare Channel Mode */
			TIMER5->CCMR2 = (TIMER5->CCMR2 & CHANNEL3_MASK)|(Configuration->Mode <<OC3M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER5->CCMR2,OC3PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER5->CCER , CC3P);
			}
			else{
				SET_BIT(TIMER5->CCER , CC3P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER5->CCER , CC3E);
		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_4){
			/* Adjust the output compare Channel Mode */
			TIMER5->CCMR2 = (TIMER5->CCMR2 & CHANNEL4_MASK)|(Configuration->Mode <<OC4M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER5->CCMR2,OC4PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER5->CCER , CC4P);
			}
			else{
				SET_BIT(TIMER5->CCER , CC4P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER5->CCER , CC4E);
		}

	}
	else if(Configuration->timer_id == TIMER3_SELECTION){
		TIMER3->CR1 = (Configuration->PreloadType    << ARPE)\
				|(Configuration->AlignedType         << CMS0)\
				|(Configuration->CountMode           << DIR )\
				|(Configuration->OnePulseMode        << OPM)\
				|(Configuration->UpdateRequestSource << URS);
		/* Adjust the slave mode selection */
		/* Use the internal clock */
		TIMER3->SMCR = 0;
		/* Set UG Bit */
		TIMER3->EGR = 1;

		/* Choose the Output Compare mode of the channel */
		if(Configuration->ChannelID == TIMER_CHANNEL_1){
			/* Adjust the output compare Channel Mode */
			TIMER3->CCMR1 = (TIMER3->CCMR1 & CHANNEL1_MASK)|(Configuration->Mode <<OC1M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER3->CCMR1,OC1PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER3->CCER , CC1P);
			}
			else{
				SET_BIT(TIMER3->CCER , CC1P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER3->CCER , CC1E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_2){
			/* Adjust the output compare Channel Mode */
			TIMER3->CCMR1 = (TIMER3->CCMR1 & CHANNEL2_MASK)|(Configuration->Mode <<OC2M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER3->CCMR1,OC2PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER3->CCER , CC2P);
			}
			else{
				SET_BIT(TIMER3->CCER , CC2P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER3->CCER , CC2E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_3){
			/* Adjust the output compare Channel Mode */
			TIMER3->CCMR2 = (TIMER3->CCMR2 & CHANNEL3_MASK)|(Configuration->Mode <<OC3M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER3->CCMR2,OC3PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER3->CCER , CC3P);
			}
			else{
				SET_BIT(TIMER3->CCER , CC3P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER3->CCER , CC3E);
		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_4){
			/* Adjust the output compare Channel Mode */
			TIMER3->CCMR2 = (TIMER3->CCMR2 & CHANNEL4_MASK)|(Configuration->Mode <<OC4M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER3->CCMR2,OC4PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER3->CCER , CC4P);
			}
			else{
				SET_BIT(TIMER3->CCER , CC4P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER3->CCER , CC4E);
		}

	}
	else if(Configuration->timer_id == TIMER4_SELECTION){
		TIMER4->CR1 = (Configuration->PreloadType    << ARPE)\
				|(Configuration->AlignedType         << CMS0)\
				|(Configuration->CountMode           << DIR )\
				|(Configuration->OnePulseMode        << OPM)\
				|(Configuration->UpdateRequestSource << URS);
		/* Adjust the slave mode selection */
		/* Use the internal clock */
		TIMER4->SMCR = 0;
		/* Set UG Bit */
		TIMER4->EGR = 1;

		/* Choose the Output Compare mode of the channel */
		if(Configuration->ChannelID == TIMER_CHANNEL_1){
			/* Adjust the output compare Channel Mode */
			TIMER4->CCMR1 = (TIMER4->CCMR1 & CHANNEL1_MASK)|(Configuration->Mode <<OC1M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER4->CCMR1,OC1PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER4->CCER , CC1P);
			}
			else{
				SET_BIT(TIMER4->CCER , CC1P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER4->CCER , CC1E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_2){
			/* Adjust the output compare Channel Mode */
			TIMER4->CCMR1 = (TIMER4->CCMR1 & CHANNEL2_MASK)|(Configuration->Mode <<OC2M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER4->CCMR1,OC2PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER4->CCER , CC2P);
			}
			else{
				SET_BIT(TIMER4->CCER , CC2P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER4->CCER , CC2E);

		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_3){
			/* Adjust the output compare Channel Mode */
			TIMER4->CCMR2 = (TIMER4->CCMR2 & CHANNEL3_MASK)|(Configuration->Mode <<OC3M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER4->CCMR2,OC3PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER4->CCER , CC3P);
			}
			else{
				SET_BIT(TIMER4->CCER , CC3P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER4->CCER , CC3E);
		}
		else if(Configuration->ChannelID == TIMER_CHANNEL_4){
			/* Adjust the output compare Channel Mode */
			TIMER4->CCMR2 = (TIMER4->CCMR2 & CHANNEL4_MASK)|(Configuration->Mode <<OC4M0);
			/* Set OC1PE Bit */
			SET_BIT(TIMER4->CCMR2,OC4PE);
			/* Adjust the polarity
			 * Active High   0
			 * Active Low    1
			 *  */
			if(Configuration->ActiveType == ACTIVE_HIGH){
				CLR_BIT(TIMER4->CCER , CC4P);
			}
			else{
				SET_BIT(TIMER4->CCER , CC4P);
			}

			/* Set the channel to be active to output the desired signal */
			SET_BIT(TIMER4->CCER , CC4E);
		}

	}


}


void TIMER_Start(TIMER_IDType Timer_Number){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		SET_BIT(TIMER2->CCER,CC4E);
		SET_BIT(TIMER2->CR1,CEN);
		break;
	case TIMER3_SELECTION:
		SET_BIT(TIMER3->CR1,CEN);
		break;
	case TIMER4_SELECTION:
		SET_BIT(TIMER4->CR1,CEN);
		break;
	case TIMER5_SELECTION:
		SET_BIT(TIMER5->CR1,CEN);
		break;
	}

}


void TIMER_Stop(TIMER_IDType Timer_Number){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		CLR_BIT(TIMER2->CCER,CC4E);
		CLR_BIT(TIMER2->CR1,CEN);
		break;
	case TIMER3_SELECTION:
		CLR_BIT(TIMER2->CCER,CC4E);
		CLR_BIT(TIMER3->CR1,CEN);
		break;
	case TIMER4_SELECTION:
		CLR_BIT(TIMER2->CCER,CC4E);
		CLR_BIT(TIMER4->CR1,CEN);
		break;
	case TIMER5_SELECTION:
		CLR_BIT(TIMER2->CCER,CC4E);
		CLR_BIT(TIMER5->CR1,CEN);
		break;
	}
}


void TIMER_SetPrescaler(TIMER_IDType Timer_Number , TIMER_PrescalerType prescaler){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		TIMER2->PSC = prescaler;
		break;
	case TIMER3_SELECTION:
		TIMER3->PSC = prescaler;
		break;
	case TIMER4_SELECTION:
		TIMER4->PSC = prescaler;
		break;
	case TIMER5_SELECTION:
		TIMER5->PSC = prescaler;
		break;
	}

}



void TIMER_SetCompareValue(TIMER_IDType Timer_Number, TIMER_ChannelType ChannelID , TIMER_OutputCompareValue ComapreValue){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		switch(ChannelID){
		case TIMER_CHANNEL_1:
			TIMER2->CCR1 = ComapreValue;
			break;
		case TIMER_CHANNEL_2:
			TIMER2->CCR2 = ComapreValue;
			break;
		case TIMER_CHANNEL_3:
			TIMER2->CCR3 = ComapreValue;
			break;
		case TIMER_CHANNEL_4:
			TIMER2->CCR4 = ComapreValue;
			break;
		}
		break;

	case TIMER3_SELECTION:
		switch(ChannelID){
		case TIMER_CHANNEL_1:
			TIMER3->CCR1 = ComapreValue;
			break;
		case TIMER_CHANNEL_2:
			TIMER3->CCR2 = ComapreValue;
			break;
		case TIMER_CHANNEL_3:
			TIMER3->CCR3 = ComapreValue;
			break;
		case TIMER_CHANNEL_4:
			TIMER3->CCR4 = ComapreValue;
			break;
		}
		break;

	case TIMER4_SELECTION:
		switch(ChannelID){
		case TIMER_CHANNEL_1:
			TIMER4->CCR1 = ComapreValue;
			break;
		case TIMER_CHANNEL_2:
			TIMER4->CCR2 = ComapreValue;
			break;
		case TIMER_CHANNEL_3:
			TIMER4->CCR3 = ComapreValue;
			break;
		case TIMER_CHANNEL_4:
			TIMER4->CCR4 = ComapreValue;
			break;
		}
		break;

	case TIMER5_SELECTION:
		switch(ChannelID){
		case TIMER_CHANNEL_1:
			TIMER5->CCR1 = ComapreValue;
			break;
		case TIMER_CHANNEL_2:
			TIMER5->CCR2 = ComapreValue;
			break;
		case TIMER_CHANNEL_3:
			TIMER5->CCR3 = ComapreValue;
			break;
		case TIMER_CHANNEL_4:
			TIMER5->CCR4 = ComapreValue;
			break;
		}
		break;
	}
}


void TIMER_SetARR(TIMER_IDType Timer_Number , TIMER_AutoReloadType AutoReloadValue){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		TIMER2->ARR = AutoReloadValue;
		break;
	case TIMER3_SELECTION:
		TIMER3->ARR = AutoReloadValue;
		break;
	case TIMER4_SELECTION:
		TIMER4->ARR = AutoReloadValue;
		break;
	case TIMER5_SELECTION:
		TIMER5->ARR = AutoReloadValue;
		break;
	}

}


void TIMER_ClearTimerCount(TIMER_IDType Timer_Number){
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		TIMER2->CNT = 0;
		break;
	case TIMER3_SELECTION:
		TIMER3->CNT = 0;
		break;
	case TIMER4_SELECTION:
		TIMER4->CNT = 0;
		break;
	case TIMER5_SELECTION:
		TIMER5->CNT = 0;
		break;
	}

}




void TIMER_SetDutyCycle(TIMER_IDType Timer_Number, TIMER_ChannelType ChannelID ,u8 DutyCycle){
	u32 TimerOnValue =0;
	switch(Timer_Number)
	{
	case TIMER2_SELECTION:
		TimerOnValue = (((TIMER2->ARR+1) * DutyCycle)/100)-1;
		break;
	case TIMER3_SELECTION:
		TimerOnValue = (((TIMER3->ARR+1) * DutyCycle)/100)-1;
		break;
	case TIMER4_SELECTION:
		TimerOnValue = (((TIMER4->ARR+1) * DutyCycle)/100)-1;
		break;
	case TIMER5_SELECTION:
		TimerOnValue = (((TIMER5->ARR+1) * DutyCycle)/100)-1;
		break;
	}
	TIMER_SetCompareValue(Timer_Number, ChannelID,  TimerOnValue);
}



