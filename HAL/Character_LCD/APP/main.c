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
#include  "../HAL/Character_LCD/CLCD_Interface.h"

//u8 arr[] = {0b00010001 , 0b00010001 , 0b00010001 , 0b00011111 , 0b00011111 , 0b00000000 , 0b00000110};

int main()
{
	CLCD_enuInitialize();

	CLCD_enuSendString("doaa tawfi");
	while(1)
	{
		//CLCD_enuWriteNumber(1331111);
		//_delay_ms(400);
		CLCD_enuControl_Cursor_Display(1);
		_delay_ms(200);
		//CLCD_enuControl_Cursor_Blink(1);
		//_delay_ms(700);
		//CLCD_enuControl_Cursor_Display(0);
		//_delay_ms(200);
		//CLCD_enuControl_Cursor_Blink(0);
		//_delay_ms(700);
		CLCD_enuCursor_OR_Display_Shift(1);
		//CLCD_enuClearDisplay();
		_delay_ms(400);
		//CLCD_enuCursor_OR_Display_Shift(2);
		//_delay_ms(400);
		//CLCD_enuClearDisplay();
		//_delay_ms(400);
	}
	return  0;
}
