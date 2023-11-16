/*
 * HEXPARSER_PROGRAM.c
 *
 *  Created on: Oct 1, 2023
 *      Author: Misra
 */



#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/HEX_PARSER_INTERFACE.h"



#define FLASH_BASE_ADDRESS			(0x08000000)



u16 DataBuffer[100];


static u8 HexParser_u8AsciiHex(u8 A_u8Ascii)
{
	u8 hex_value=0;

	if(A_u8Ascii>='0'  && A_u8Ascii<='9')
	{
		hex_value=A_u8Ascii-'0';
	}
	else if(A_u8Ascii>='A'  && A_u8Ascii<='F')
	{
		hex_value=A_u8Ascii-'A'+10;
	}

	return hex_value;
}



void HexParser_voidParseData(u8 A_pu8Data[])
{
	u8 cc_high,cc_low,digit0,digit1,digit2,digit3;

	u16 cc;

	u32 address;
	cc_high=HexParser_u8AsciiHex(A_pu8Data[1]);
	cc_low=HexParser_u8AsciiHex(A_pu8Data[2]);

	cc=(cc_high<<4)|(cc_low);


	//low address
	digit0=HexParser_u8AsciiHex(A_pu8Data[3]);
	digit1=HexParser_u8AsciiHex(A_pu8Data[4]);
	digit2=HexParser_u8AsciiHex(A_pu8Data[5]);
	digit3=HexParser_u8AsciiHex(A_pu8Data[6]);

	address=(FLASH_BASE_ADDRESS)|(digit0<<12)|(digit1<<8)|(digit2<<4)|(digit3<<0);

	for(u8 i=0;i<(cc/2);i++)
	{
		digit0=HexParser_u8AsciiHex(A_pu8Data[4*i+9]);
		digit0=HexParser_u8AsciiHex(A_pu8Data[4*i+10]);
		digit0=HexParser_u8AsciiHex(A_pu8Data[4*i+11]);
		digit0=HexParser_u8AsciiHex(A_pu8Data[4*i+12]);

		DataBuffer[i]=(digit0<<12)|(digit1<<8)|(digit2<<4)|(digit3<<0);
	}

	FMI_vFlashWrite(address,DataBuffer,cc/2);

}
