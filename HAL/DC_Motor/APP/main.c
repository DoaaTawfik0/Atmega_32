/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: YOGA 640
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/ERROR_STATE.h"

#include  "../MCAL/DIO/DIO_Interface.h"

#include  "../HAL/DC_Motor/DC_Motor_Interface.h"
#include  "../HAL/DC_Motor/DC_Motor_Config.h"

#include "util/delay.h"


extern DC_MOTOR_t  DC_MOTOR_AStrConfig[MOTOR_NUM];

int main()
{
	DC_MOTOR_enuInitialize(DC_MOTOR_AStrConfig);

	while(1)
	{

		DC_MOTOR_enuTurnRight(&DC_MOTOR_AStrConfig[0]);
		DC_MOTOR_enuTurnRight(&DC_MOTOR_AStrConfig[1]);
		_delay_ms(1000);
		DC_MOTOR_enuTurnLeft(&DC_MOTOR_AStrConfig[0]);
		DC_MOTOR_enuTurnLeft(&DC_MOTOR_AStrConfig[1]);
		_delay_ms(1000);
		DC_MOTOR_enuTurnRight(&DC_MOTOR_AStrConfig[0]);
		DC_MOTOR_enuTurnLeft(&DC_MOTOR_AStrConfig[1]);
		_delay_ms(1000);
		DC_MOTOR_enuTurnLeft(&DC_MOTOR_AStrConfig[0]);
		DC_MOTOR_enuTurnRight(&DC_MOTOR_AStrConfig[1]);
		_delay_ms(1000);
		DC_MOTOR_enuStop(&DC_MOTOR_AStrConfig[0]);
		DC_MOTOR_enuStop(&DC_MOTOR_AStrConfig[1]);
		_delay_ms(1000);
	}
	return  0;
}
