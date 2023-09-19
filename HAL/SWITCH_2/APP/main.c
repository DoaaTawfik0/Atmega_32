/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: YOGA 640
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/ERROR_STATE.h"

#include  "../MCAL/DIO/DIO_Interface.h"

#include  "../HAL/LED/LED_Interface.h"
#include  "../HAL/LED/LED_Config.h"

#include  "../HAL/Switch/Switch_Interface.h"
#include  "../HAL/Switch/Switch_Config.h"



#include "util/delay.h"

extern Switch_t  Switch_AStrSwitchConfig[SWITCH_NUM];
extern LED_t LED_AStrConfig[LED_NUM];

int main()
{
	u8 Local_u8SW1 , Local_u8SW2;


	LED_enuInitialize(LED_AStrConfig);
	Switch_enuInitialize(Switch_AStrSwitchConfig);

	while(1)
	{
		Switch_enuGetSwitchState(&Switch_AStrSwitchConfig[0] , &Local_u8SW1);
		DIO_enuSetPortDirection(DIO_PORTC , OUTPUT);
		DIO_enuSetPortValue(DIO_PORTC,Local_u8SW1);
		_delay_ms(3000);

		//Switch_enuGetSwitchState(&Switch_AStrSwitchConfig[0] , &Local_u8SW2);
//		if(Local_u8SW1 == 0)
//		{
//			DIO_enuSetPinValue(DIO_PORTA , DIO_PIN0 , HIGH);
//		}
//		else if(Local_u8SW1 == 1)
//		{
//			DIO_enuSetPinValue(DIO_PORTA , DIO_PIN0 , LOW);
//			DIO_enuSetPortDirection(DIO_PORTC , OUTPUT);
//			DIO_enuSetPortValue(DIO_PORTC,Local_u8SW1);
//		}

	}


	return  0;
}
