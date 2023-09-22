/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LED           ***************/
/**************   Version: 2.00         ***************/
/******************************************************/
/******************************************************/

#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/ERROR_STATE.h"
#include  "../../LIB/BIT_MATH.h"

#include  "../../MCAL/DIO/DIO_Interface.h"

#include  "Switch_Config.h"
#include  "Switch_Private.h"
#include  "Switch_Interface.h"

Switch_t  Switch_AStrSwitchConfig[SWITCH_NUM] =
{
		{DIO_PORTC , DIO_PIN0 , PULL_UP},
		{DIO_PORTB , DIO_PIN1 , FLOAT}
};
