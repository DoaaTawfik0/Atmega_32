/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Switch          ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/
#include "STD_TYPES.h"
#include "Switch_Private.h"
#include "Switch_Config.h"
#include "DIO_Interface.h"

SW_t Switch_AstrSwitchState[SW_NUM] = {
		{DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_FLOAT},
		{DIO_u8PORTB , DIO_u8PIN3 , DIO_u8PIN_PULL_UP},
		{DIO_u8PORTC , DIO_u8PIN5 , DIO_u8PIN_PULL_UP}
};


