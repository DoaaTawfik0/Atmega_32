/*
 * main.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Doaa Tawfik
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/ERROR_STATE.h"

#include  "../MCAL/DIO/DIO_Interface.h"
#include  "../HAL/KeyPad/KeyPad_Interface.h"
#include  "../HAL/Character_LCD/CLCD_Interface.h"

#include  "util/delay.h"

int main()
{
	u8 Local_u8PressedKey;

	CLCD_enuInitialize();
	CLCD_enuClearDisplay();
	KPD_enuInitialize();

	while(1)
	{
		do
		{
			KPD_enuGetPressedKey(&Local_u8PressedKey);
		}while(Local_u8PressedKey == 0xff);
		CLCD_enuWriteNumber(Local_u8PressedKey);
		_delay_ms(300);
		CLCD_enuClearDisplay();



	}
	return  0;
}
