/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LM35          ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../MCAL/ADC/ADC_Interface.h"

#include "LM35_Interface.h"
#include "LM35_Private.h"
#include "LM35_Config.h"



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LM35_enuInitialize.                                   **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : void.                                                 **/
/** Functionality   : Initializing Lm35 Sensor (Config of pin)              **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t  LM35_enuInitialize(void)
{
	ES_t Local_enuErrorState   = ES_NOK;

	u8 Local_u8Iterator;

	Local_enuErrorState = DIO_enuSetPinDirection(LM35_PORT_ID , LM35_PIN_ID , INPUT);

	return  Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LM35_enuGetTemperature.                               **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_pu16AnalogValue , Copy_pu8TempValue.             **/
/** Functionality   : Getting Temperature of Sensor                         **/
/*This function take a pointer to var that carry analog voltage in mv       **/
/*& pointer to another var to return Temp value on it                       **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t  LM35_enuGetTemperature(u16* Copy_pu16AnalogValue , u8* Copy_pu8TempValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_pu16AnalogValue != NULL) && (Copy_pu8TempValue != NULL))
	{
            *Copy_pu8TempValue = (u8)((*Copy_pu16AnalogValue)/10);

            Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
