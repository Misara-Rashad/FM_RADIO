/* Standard Types File */
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"



/* RCC Specified Header Files */
#include "../include/MTIMER_Interface.h"
#include "../include/MTIMER_Config.h"
#include "../include/MTIMER_Private.h"




TIMER_configType Timer_configuration={
	TIMER2_SELECTION,
	TIMER_ARR_NOT_BUFFERED,
	TIMER_EGDE_ALIGNED_MODE,
	COUNT_UP,
	TIMER_NO_STOP,
	TIMER_ONLY_COUNTER_OVF_UNF_GENERATE,
	TIMER_PWM_MODE_1,
	TIMER_CHANNEL_4,
	ACTIVE_HIGH
};
