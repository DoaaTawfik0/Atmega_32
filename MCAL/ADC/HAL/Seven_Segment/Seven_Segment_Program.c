/*********************************************************/
/*********************************************************/
/**************   Author: Doaa Tawfik      ***************/
/**************   Layer:  HAL              ***************/
/**************   SWC:    Seven_Segment    ***************/
/**************   Version: 2.00            ***************/
/*********************************************************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Private.h"


u8 SEG_Au8NumDisplay[] =
{
		0x3F , 0x06 , 0x5B ,
		0x4F , 0x66 , 0x6D ,
		0x7D , 0x07 , 0x7F ,
		0x6F
};



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuInitialize.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PStrConfig.                                      **/
/** Functionality   : Initializing Seven_Segments                           **/
/*This function take a pointer to struct of type SEG_t & we use this        **/
/*pointer to access array elements & set direction of this 7_Segment...     **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuInitialize(SEG_t *Copy_PStrConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PStrConfig != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0 ; Local_u8Iterator < SEG_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState  = DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8APort , Copy_PStrConfig[Local_u8Iterator].SEG_u8APin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8BPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8BPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8CPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8CPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8DPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8DPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8EPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8EPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8FPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8FPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8GPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8GPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8CommonPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8CommonPin , OUTPUT);
			Local_enuErrorState |= DIO_enuSetPinDirection(Copy_PStrConfig[Local_u8Iterator].SEG_u8DotPort , Copy_PStrConfig[Local_u8Iterator].SEG_u8DotPin , OUTPUT);

			if(Local_enuErrorState != ES_OK)
				break;
		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuDisplay_Number.                          **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID , Copy_Number.                        **/
/** Functionality   : Displat Number on seven_segment                       **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to Display number on the desired 7_SEG                        **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuDisplay_Number(SEG_t *Copy_PArrSEG_ID , u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;


	if(Copy_PArrSEG_ID != NULL)
	{
		if((Copy_u8Number >=0) && (Copy_u8Number <= 9))
		{

			if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState  = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8APort , Copy_PArrSEG_ID->SEG_u8APin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 0) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8BPort , Copy_PArrSEG_ID->SEG_u8BPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 1) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CPort , Copy_PArrSEG_ID->SEG_u8CPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 2) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DPort , Copy_PArrSEG_ID->SEG_u8DPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 3) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8EPort , Copy_PArrSEG_ID->SEG_u8EPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 4) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8FPort , Copy_PArrSEG_ID->SEG_u8FPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 5) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8GPort , Copy_PArrSEG_ID->SEG_u8GPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 6) & 1));

				if(Local_enuErrorState != ES_OK)
					return Local_enuErrorState;

			}
			else if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState  = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8APort , Copy_PArrSEG_ID->SEG_u8APin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 0) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8BPort , Copy_PArrSEG_ID->SEG_u8BPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 1) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CPort , Copy_PArrSEG_ID->SEG_u8CPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 2) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DPort , Copy_PArrSEG_ID->SEG_u8DPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 3) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8EPort , Copy_PArrSEG_ID->SEG_u8EPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 4) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8FPort , Copy_PArrSEG_ID->SEG_u8FPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 5) & 1));
				Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8GPort , Copy_PArrSEG_ID->SEG_u8GPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 6) & 1));

				if(Local_enuErrorState != ES_OK)
					return Local_enuErrorState;
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
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuClearDisplay.                            **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID                                       **/
/** Functionality   : Clear seven_segment                                   **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to clear the desired 7_SEG                                    **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuClearDisplay(SEG_t *Copy_PArrSEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrSEG_ID != NULL)
	{
		if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
		{
			Local_enuErrorState  = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8APort , Copy_PArrSEG_ID->SEG_u8APin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8BPort , Copy_PArrSEG_ID->SEG_u8BPin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CPort , Copy_PArrSEG_ID->SEG_u8CPin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DPort , Copy_PArrSEG_ID->SEG_u8DPin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8EPort , Copy_PArrSEG_ID->SEG_u8EPin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8FPort , Copy_PArrSEG_ID->SEG_u8FPin , LOW);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8GPort , Copy_PArrSEG_ID->SEG_u8GPin , LOW);

			if(Local_enuErrorState != ES_OK)
				return Local_enuErrorState;

		}
		else if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
		{
			Local_enuErrorState  = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8APort , Copy_PArrSEG_ID->SEG_u8APin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8BPort , Copy_PArrSEG_ID->SEG_u8BPin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CPort , Copy_PArrSEG_ID->SEG_u8CPin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DPort , Copy_PArrSEG_ID->SEG_u8DPin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8EPort , Copy_PArrSEG_ID->SEG_u8EPin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8FPort , Copy_PArrSEG_ID->SEG_u8FPin , HIGH);
			Local_enuErrorState |= DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8GPort , Copy_PArrSEG_ID->SEG_u8GPin , HIGH);

			if(Local_enuErrorState != ES_OK)
				return Local_enuErrorState;
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


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuEnableCommon.                            **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID                                       **/
/** Functionality   : Enable seven_segment Commpon Pin                      **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to Enable the desired 7_SEG Commpon Pin                       **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuEnableCommon(SEG_t *Copy_PArrSEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CommonPort , Copy_PArrSEG_ID->SEG_u8CommonPin , LOW);
	}
	else if (Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CommonPort , Copy_PArrSEG_ID->SEG_u8CommonPin , HIGH);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuDisableCommon.                           **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID                                       **/
/** Functionality   : Disable seven_segment Commpon Pin                     **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to Disable the desired 7_SEG Commpon Pin                      **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuDisableCommon(SEG_t *Copy_PArrSEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CommonPort , Copy_PArrSEG_ID->SEG_u8CommonPin , HIGH);
	}
	else if (Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8CommonPort , Copy_PArrSEG_ID->SEG_u8CommonPin , LOW);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuEnableDot.                               **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID                                       **/
/** Functionality   : Enable seven_segment Dot Pin                          **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to Enable the desired 7_SEG Dot Pin                           **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuEnableDot(SEG_t *Copy_PArrSEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DotPort , Copy_PArrSEG_ID->SEG_u8DotPin , HIGH);
	}
	else if (Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DotPort , Copy_PArrSEG_ID->SEG_u8DotPin , LOW);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : SEVEN_SEG_enuDisableDot.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_PArrSEG_ID                                       **/
/** Functionality   : Disable seven_segment Dot Pin                         **/
/*This function take a pointer to array element(Desired 7_SEG)              **/
/*& we use it to Disable the desired 7_SEG Dot Pin                           **/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

ES_t SEVEN_SEG_enuDisableDot(SEG_t *Copy_PArrSEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrSEG_ID->SEG_u8Type == COMMON_CATHODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DotPort , Copy_PArrSEG_ID->SEG_u8DotPin , LOW);
	}
	else if (Copy_PArrSEG_ID->SEG_u8Type == COMMON_ANODE)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_PArrSEG_ID->SEG_u8DotPort , Copy_PArrSEG_ID->SEG_u8DotPin , HIGH);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
