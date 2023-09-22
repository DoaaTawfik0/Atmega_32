/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: YOGA 640
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/ERROR_STATE.h"

#include  "../MCAL/DIO/DIO_Register.h"
#include  "../MCAL/DIO/DIO_Interface.h"

#include "util/delay.h"


int main()
{
	u8 localvalue;
	/*SET_BIT(DDRA , DIO_PIN0);
	SET_BIT(DDRA , DIO_PIN1);
	SET_BIT(DDRA , DIO_PIN2);
	SET_BIT(DDRA , DIO_PIN3);
	SET_BIT(DDRA , DIO_PIN4);
	SET_BIT(DDRA , DIO_PIN5);
	SET_BIT(DDRA , DIO_PIN6);
	SET_BIT(DDRA , DIO_PIN7);
	*/
	//DIO_enuSetPortDirection(DIO_PORTA , OUTPUT);
	DIO_enuSetPinDirection(DIO_PORTA , DIO_PIN7 , OUTPUT);
	while(1)
	{
		//_delay_ms(3000);

		/*DIO_enuSetPortValue(DIO_PORTA , 0X45);
		_delay_ms(300);
		DIO_enuGetPortValue(DIO_PORTA ,&localvalue);
		DIO_enuSetPortValue(DIO_PORTA , 0X50);
		_delay_ms(300);
		DIO_enuSetPortValue(DIO_PORTA , localvalue);
		_delay_ms(300);*/

		//DIO_enuTogglePortValue(DIO_PORTA);
		//  _delay_ms(300);
		//  DIO_enuClearPortValue(DIO_PORTA);
		//  _delay_ms(300);
		//DIO_enuSetPortValue(DIO_PORTA , 0xFF);
		DIO_enuSetPinValue(DIO_PORTA , DIO_PIN7 , LOW);
		_delay_ms(700);

		DIO_enuTogglePinValue(DIO_PORTA , DIO_PIN7);
		_delay_ms(300);
	}


	return  0;
}
