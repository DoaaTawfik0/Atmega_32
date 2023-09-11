/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Switch          ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"

#include "Switch_Config.h"
#include "Switch_Interface.h"
#include "Switch_Private.h"

#include "DIO_Interface.h"


ES_t Switch_enuInitialize(SW_t* Copy_AstrSwitches)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator;
	if(Copy_AstrSwitches != NULL)
	{
		for(Local_u8Iterator = 0 ; Local_u8Iterator < SW_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrSwitches[Local_u8Iterator].SW_u8PortID ,
					Copy_AstrSwitches[Local_u8Iterator].SW_u8PinID  ,
					DIO_u8PIN_INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrSwitches[Local_u8Iterator].SW_u8PortID ,
					Copy_AstrSwitches[Local_u8Iterator].SW_u8PinID  ,
					Copy_AstrSwitches[Local_u8Iterator].SW_u8Status );

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
ES_t Switch_enuGetState(SW_t* Copy_AstrSwitches , u8* Copy_pu8SwitchState)
{
	ES_t Local_enuErrorState = ES_NOK;
	if((Copy_AstrSwitches != NULL) && (Copy_pu8SwitchState != NULL))
	{
		Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrSwitches->SW_u8PortID ,
				Copy_AstrSwitches->SW_u8PinID  ,
				Copy_pu8SwitchState);

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;

}
