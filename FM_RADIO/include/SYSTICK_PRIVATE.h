/*
 * SYSTICK_PRIVATE.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Misra
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


/*		BASE ADDRESS  		*/
#define SYSTICK_BASE_ADDRESS		(0xE000E010)
/*****************************/



typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSYICK_t;


#define SYSTICK				((volatile SYSYICK_t*)SYSTICK_BASE_ADDRESS)






#endif /* SYSTICK_PRIVATE_H_ */
