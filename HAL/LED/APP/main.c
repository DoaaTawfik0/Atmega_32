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

#include  "../HAL/LED_Interface.h"
#include  "../HAL/LED_Config.h"


#include "util/delay.h"

extern LED_t LED_AStrConfig[LED_NUM] ;

int main()
{

	LED_enuInitialize(LED_AStrConfig);

	while(1)
	{
		LED_enuTurn_LED_ON(&LED_AStrConfig[0]);
		_delay_ms(400);
		LED_enuTurn_LED_ON(&LED_AStrConfig[1]);
		_delay_ms(400);
		LED_enuTurn_LED_ON(&LED_AStrConfig[2]);
		_delay_ms(400);
		LED_enuTurn_LED_OFF(&LED_AStrConfig[0]);
		_delay_ms(400);
		LED_enuTurn_LED_OFF(&LED_AStrConfig[1]);
		_delay_ms(400);
		LED_enuTurn_LED_OFF(&LED_AStrConfig[2]);
		_delay_ms(400);

	}


	return  0;
}
