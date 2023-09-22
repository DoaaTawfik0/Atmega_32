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
	u8 localvalue ;

//	DIO_enuSetPortDirection(DIO_PORTA,OUTPUT);
//	DIO_enuClearPortValue(DIO_PORTA);
//
//	DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,LOW);
//	DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,LOW);
//
//
	Switch_enuInitialize(Switch_AStrSwitchConfig);
	LED_enuInitialize(LED_AStrConfig);
	while(1)
	{
		Switch_enuGetSwitchState(&Switch_AStrSwitchConfig[0] , &localvalue);
		//DIO_enuClearPortValue(DIO_PORTA);
		if(localvalue == SWITCH_PRESSED)
		{

			DIO_enuSetPinValue(DIO_PORTA,DIO_PIN2,HIGH);
			//LED_enuTurn_LED_ON(&LED_AStrConfig[0]);
		}
		else if(localvalue == SWITCH_NOT_PRESSED)
		{
			DIO_enuSetPinValue(DIO_PORTA,DIO_PIN2,LOW);
			//LED_enuTurn_LED_OFF(&LED_AStrConfig[0]);
		}



	}
	return  0;
}
