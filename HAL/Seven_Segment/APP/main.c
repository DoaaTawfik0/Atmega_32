/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Doaa Tawfik
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/ERROR_STATE.h"

#include  "util/delay.h"

#include  "../MCAL/DIO/DIO_Interface.h"

#include  "../HAL/Seven_Segment/Seven_Segment_Interface.h"
#include  "../HAL/Seven_Segment/Seven_Segment_Config.h"

extern SEG_t  SEG_AStrConfig[SEG_NUM];

int main()
{
	u8 Local_u8Iterator;


	SEVEN_SEG_enuInitialize(SEG_AStrConfig);
	SEVEN_SEG_enuEnableCommon(&SEG_AStrConfig[0]);
	SEVEN_SEG_enuEnableCommon(&SEG_AStrConfig[1]);
	while(1)
	{
		for(Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator++)
		{

			SEVEN_SEG_enuDisplay_Number(&SEG_AStrConfig[0] , Local_u8Iterator);
			 SEVEN_SEG_enuDisplay_Number(&SEG_AStrConfig[1] , Local_u8Iterator);
			 SEVEN_SEG_enuEnableDot(&SEG_AStrConfig[1]);
			 // DIO_enuSetPortValue(DIO_PORTD , Local_u8Error);
			_delay_ms(1000);
			SEVEN_SEG_enuDisableDot(&SEG_AStrConfig[1]);
			_delay_ms(400);
		}


	}
	return  0;
}
