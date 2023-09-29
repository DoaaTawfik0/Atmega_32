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

#include  "../MCAL/EXTI/EXTI_Interface.h"

#include  "../MCAL/GIE/GIE_Interface.h"

#include  "util/delay.h"

extern EXTI_t  EXTI_AstrConfig[3] ;

void Toggle();

void Clear();

void Set();

int main()
{
	GIE_enuEnable();
	EXTI_enuInitialize(EXTI_AstrConfig);


	//EXTI_enuEnableInterrupt(0);
	EXTI_enuCallBackFunction(Toggle , NULL , 0);
	EXTI_enuCallBackFunction(Set , NULL , 1);
	EXTI_enuCallBackFunction(Clear , NULL , 2);


	while(1)
	{

	}
	return  0;
}

void Toggle()
{

	DIO_enuTogglePinValue(DIO_PORTA , DIO_PIN0);

}

void Clear()
{
	DIO_enuSetPinValue(DIO_PORTA , DIO_PIN1 , LOW);

}

void Set()
{
	DIO_enuSetPinDirection(DIO_PORTA , DIO_PIN1 , OUTPUT);
	DIO_enuSetPinValue(DIO_PORTA , DIO_PIN1 , HIGH);

}

