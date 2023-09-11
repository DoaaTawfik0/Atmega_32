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

#include "LED_Private.h"
#include "LED_Config.h"

#include "DIO_Interface.h"


ES_t LED_enuInitialize(LED_t* Copy_pstrLedStates)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrLedStates != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0 ; Local_u8Iterator < LED_NUM ; Local_u8Iterator++)
		{

			Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrLedStates[Local_u8Iterator].LED_u8PortID,
					Copy_pstrLedStates[Local_u8Iterator].LED_u8PinID,
					DIO_u8PIN_OUTPUT);
			if(Copy_pstrLedStates[Local_u8Iterator].LED_u8ConnType == LED_SINK)
			{
				if(Copy_pstrLedStates[Local_u8Iterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedStates[Local_u8Iterator].LED_u8PortID,
							Copy_pstrLedStates[Local_u8Iterator].LED_u8PinID,
							DIO_u8PIN_LOW);
				}
				else if(Copy_pstrLedStates[Local_u8Iterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedStates[Local_u8Iterator].LED_u8PortID,
							Copy_pstrLedStates[Local_u8Iterator].LED_u8PinID,
							DIO_u8PIN_HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}

			}
			else if(Copy_pstrLedStates[Local_u8Iterator].LED_u8ConnType == LED_SOURCE)
			{
				if(Copy_pstrLedStates[Local_u8Iterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedStates[Local_u8Iterator].LED_u8PortID,
							Copy_pstrLedStates[Local_u8Iterator].LED_u8PinID,
							DIO_u8PIN_HIGH);
				}
				else if(Copy_pstrLedStates[Local_u8Iterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedStates[Local_u8Iterator].LED_u8PortID,
							Copy_pstrLedStates[Local_u8Iterator].LED_u8PinID,
							DIO_u8PIN_LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}

			}
			else
			{
				return ES_OUT_OF_RANGE;
			}

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
ES_t LED_enuTurnON(LED_t* Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID->LED_u8ConnType == LED_SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID , Copy_pstrLedID->LED_u8PinID , DIO_u8PIN_LOW);
		}
		else if(Copy_pstrLedID->LED_u8ConnType == LED_SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID , Copy_pstrLedID->LED_u8PinID , DIO_u8PIN_HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
ES_t LED_enuTurnOFF(LED_t* Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrLedID->LED_u8ConnType == LED_SINK)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID , Copy_pstrLedID->LED_u8PinID , DIO_u8PIN_HIGH);
	}
	else if(Copy_pstrLedID->LED_u8ConnType == LED_SOURCE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID , Copy_pstrLedID->LED_u8PinID , DIO_u8PIN_LOW);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;

	return Local_enuErrorState;
}
