/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LED           ***************/
/**************   Version:1.00          ***************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"

#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Private.h"

LED_t LED_AstrLedStates[LED_NUM]=
{
		{DIO_u8PORTA , DIO_u8PIN0 , LED_SINK , LED_OFF},
		{DIO_u8PORTB , DIO_u8PIN0 , LED_SOURCE , LED_ON},
		{DIO_u8PORTB , DIO_u8PIN1 , LED_SOURCE , LED_ON}

};

