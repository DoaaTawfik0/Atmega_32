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

#include "../../MCAL/DIO/DIO_Interface.h"

#include  "Switch_Interface.h"
#include  "Switch_Config.h"
#include  "Switch_Private.h"



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : Switch_enuInitialize.                                 **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PStrSwitchConfig.                                **/
/** Functionality   : Initializing Switchs                                  **/
/*This function take a pointer to struct of type Switch_t & we use this     **/
/*pointer to access array elements & set direction of this switch & value   **/
/*to pin of this switch(flaot/pulll_up)                                     **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


ES_t  Switch_enuInitialize(Switch_t *Copy_PStrSwitchConfig)
{
	ES_t Local_enuErrorState   = ES_NOK;

	if(Copy_PStrSwitchConfig != NULL)
	{
		u8 Local_u8Iterator;

		for(Local_u8Iterator = 0 ; Local_u8Iterator < SWITCH_NUM ; Local_u8Iterator++)
		{

			if((Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Port_ID >= DIO_PORTA) && ( Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Port_ID <= DIO_PORTD))
			{
				if((Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Pin_ID >= DIO_PIN0) && ( Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Pin_ID <= DIO_PIN7))
				{
					Local_enuErrorState  = DIO_enuSetPinDirection(Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Port_ID , Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Pin_ID , INPUT);
					Local_enuErrorState |= DIO_enuSetPinValue(Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Port_ID , Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8Pin_ID , Copy_PStrSwitchConfig[Local_u8Iterator].Switch_u8State );
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;

				}

			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;

			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return  Local_enuErrorState;

}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : Switch_enuGetSwitchState.                             **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSwitch_ID,Copy_pu8ReturnState.               **/
/** Functionality   : Getting State of Switch                               **/
/*This function take a pointer to array element(Desired switch)             **/
/*& we use it to access the desired switch & get it's state                 **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t Switch_enuGetSwitchState(Switch_t *Copy_PArrSwitch_ID , u8 *Copy_pu8ReturnState)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_PArrSwitch_ID != NULL) && (Copy_pu8ReturnState != NULL))
	{

		if((Copy_PArrSwitch_ID->Switch_u8Port_ID >= DIO_PORTA) && (Copy_PArrSwitch_ID->Switch_u8Port_ID <= DIO_PORTD))
		{

			if((Copy_PArrSwitch_ID->Switch_u8Pin_ID >= DIO_PIN0) && (Copy_PArrSwitch_ID->Switch_u8Pin_ID <= DIO_PIN7))
			{
				Local_enuErrorState =  DIO_enuGetPinValue(Copy_PArrSwitch_ID->Switch_u8Port_ID , Copy_PArrSwitch_ID->Switch_u8Pin_ID , Copy_pu8ReturnState);
			}
			else
			{
				Local_enuErrorState  =  ES_OUT_OF_RANGE;
			}

		}
		else
		{
			Local_enuErrorState  =  ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorState  =  ES_NULL_POINTER;
	}

	return  Local_enuErrorState;
}




