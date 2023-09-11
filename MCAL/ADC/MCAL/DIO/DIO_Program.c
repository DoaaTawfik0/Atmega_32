#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_Config.h"
#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_Private.h"



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuSetPortDirection.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Setting Port Value                                    **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuSetPortValue(u8 copy_u8Port , u8 copy_u8Value)
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(copy_u8Port <= DIO_u8PORTD)
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA : PORTA = copy_u8Value ; break;
		case DIO_u8PORTB : PORTB = copy_u8Value ; break;
		case DIO_u8PORTC : PORTC = copy_u8Value ; break;
		case DIO_u8PORTD : PORTD = copy_u8Value ; break;
		} Local_u8ErrorState = ES_OK ;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;

}
/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuTogPortValue.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Toggling Port Value                                   **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuTogPortValue(u8 copy_u8Port)
{

	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if(copy_u8Port <= DIO_u8PORTD)
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA : PORTA = ~PORTA ; break;
		case DIO_u8PORTB : PORTB = ~PORTB ; break;
		case DIO_u8PORTC : PORTC = ~PORTC ; break;
		case DIO_u8PORTD : PORTD = ~PORTD ; break;
		} Local_u8ErrorState = ES_OK ;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;

}
/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuGetPortValue.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Getting Port Value                                    **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuGetPortValue(u8 copy_u8Port , u8* copy_pu8Value)
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(copy_pu8Value != NULL)
	{
		if(copy_u8Port <= DIO_u8PORTD)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA : *copy_pu8Value = PINA ; break;
			case DIO_u8PORTB : *copy_pu8Value = PINB ; break;
			case DIO_u8PORTC : *copy_pu8Value = PINC ; break;
			case DIO_u8PORTD : *copy_pu8Value = PIND  ; break;
			} Local_u8ErrorState = ES_OK ;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuSetPinValue.                                   **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Setting Pin Value                                     **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
	{
		if(copy_u8Value == HIGH)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA , copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB , copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC , copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;
		}
		else if(copy_u8Value == LOW)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: CLEAR_BIT(PORTA , copy_u8Pin); break;
			case DIO_u8PORTB: CLEAR_BIT(PORTB , copy_u8Pin); break;
			case DIO_u8PORTC: CLEAR_BIT(PORTC , copy_u8Pin); break;
			case DIO_u8PORTD: CLEAR_BIT(PORTD , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}


	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuTogPinValue.                                   **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Toggling Pin Value                                    **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuTogPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA: TOGGLE_BIT(PORTA , copy_u8Pin); break;
		case DIO_u8PORTB: TOGGLE_BIT(PORTB , copy_u8Pin); break;
		case DIO_u8PORTC: TOGGLE_BIT(PORTC , copy_u8Pin); break;
		case DIO_u8PORTD: TOGGLE_BIT(PORTD , copy_u8Pin); break;
		}Local_u8ErrorState = ES_OK;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : DIO_enuGetPinValue.                                   **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Port & Value.                                         **/
/** Functionality   : Getting Pin Value                                     **/
/*****************************************************************************/
/*****************************************************************************/
ES_t DIO_enuGetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8* copy_Pu8Value)//pu8 pointer to u8
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if(copy_Pu8Value != NULL)
	{
		if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: *copy_Pu8Value = GET_BIT(PINA , copy_u8Pin); break;
			case DIO_u8PORTB: *copy_Pu8Value = GET_BIT(PINB , copy_u8Pin); break;
			case DIO_u8PORTC: *copy_Pu8Value = GET_BIT(PINC , copy_u8Pin); break;
			case DIO_u8PORTD: *copy_Pu8Value = GET_BIT(PIND , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;

		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}

	return Local_u8ErrorState;

}

