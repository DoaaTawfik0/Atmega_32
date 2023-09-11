#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"


#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Private.h"
#include "Seven_Segment_Config.h"



extern  SEG_t SEG_AstrSegConfig[NUMBER_OF_SEVEN_SEGMENT];

u8 SEG_Au8NumDisplay[] = {0x3F , 0x06 , 0x5B ,
		                  0x4F , 0x66 , 0x6D ,
						  0x7D , 0x07 , 0x7F ,
						  0x6F};


ES_t Seven_Segment_enuInitialize(SEG_t *Copy_AstrSegConfig)
{
	ES_t Local_u8ErrorState = ES_NOK;

	u8  Local_u8Iterator;
	u32 Local_u32ErrorCheck = 0;
	if(Copy_AstrSegConfig != NULL)
	{
		for(Local_u8Iterator = 0 ; Local_u8Iterator < NUMBER_OF_SEVEN_SEGMENT ; Local_u8Iterator++)
		{
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 0);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8BPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 3);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 6);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 9);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8EPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 12);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8FPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 15);
			Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8GPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8APin , DIO_u8PIN_OUTPUT) << 18);
			if((Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPort < DIO_u8PORTD) && (Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPin < DIO_u8PIN7))
			{
				Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPin , DIO_u8PIN_OUTPUT) << 21);
			}
			else if ((Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPort == NOT_CONNECTED) || (Copy_AstrSegConfig[Local_u8Iterator].SEG_u8CommonPin == NOT_CONNECTED)) ;
			else
			{
				Local_u8ErrorState =ES_OUT_OF_RANGE;
			}
			if((Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPort < DIO_u8PORTD) && (Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPin < DIO_u8PIN7))
			{
				Local_u32ErrorCheck |= (DIO_enuSetPinDirection(Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPort , Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPin , DIO_u8PIN_OUTPUT) << 21);
			}
			else if ((Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPort == NOT_CONNECTED) || (Copy_AstrSegConfig[Local_u8Iterator].SEG_u8DotPin == NOT_CONNECTED)) ;
			else
			{
				Local_u8ErrorState =ES_OUT_OF_RANGE;
			}

			for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u8ErrorState)*8 ; Local_u8Iterator+=3)
			{
				if(((Local_u32ErrorCheck>>Local_u8Iterator) & 7) != ES_OK)
				{
					return Local_u8ErrorState;
				}
			}
			Local_u8ErrorState =ES_OK;

		}

	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}


	return Local_u8ErrorState;
}


ES_t Seven_Segment_enuDisplayNumber(u8 Copy_u8SegID , u8 Copy_u8Number)
{
	ES_t Local_u8ErrorState = ES_NOK;

	u8  Local_u8Iterator;
	u32 Local_u32ErrorCheck = 0;

	if((Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT) && (Copy_u8Number < 10))
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 0) & 1)) << 0);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 1) & 1)) << 3);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 2) & 1)) << 6);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 3) & 1)) << 9);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 4) & 1)) << 12);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 5) & 1)) << 15);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , ((SEG_Au8NumDisplay[Copy_u8Number] >> 6) & 1)) << 18);
		}
		else if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 0) & 1)) << 0);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 1) & 1)) << 3);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 2) & 1)) << 6);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 3) & 1)) << 9);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 4) & 1)) << 12);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 5) & 1)) << 15);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , !((SEG_Au8NumDisplay[Copy_u8Number] >> 6) & 1)) << 18);
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}

		for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u8ErrorState)*8 ; Local_u8Iterator+=3)
		{
			if(((Local_u32ErrorCheck>>Local_u8Iterator) & 7) != ES_OK)
			{
				return Local_u8ErrorState;
			}
		}
		Local_u8ErrorState =ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
ES_t Seven_Segment_enuEnableCommon(u8 Copy_u8SegID )
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT)
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPin , DIO_u8PIN_LOW);
		}
		else if (SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPin , DIO_u8PIN_HIGH);
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
ES_t Seven_Segment_enuDisableCommon(u8 Copy_u8SegID )
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT)
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPin , DIO_u8PIN_HIGH);
		}
		else if (SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CommonPin , DIO_u8PIN_LOW);
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
ES_t Seven_Segment_enuEnableDot(u8 Copy_u8SegID )
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT)
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPin , DIO_u8PIN_HIGH);
		}
		else if (SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPin , DIO_u8PIN_LOW);
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
ES_t Seven_Segment_enuDisableDot(u8 Copy_u8SegID )
{


	ES_t Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT)
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPin , DIO_u8PIN_LOW);
		}
		else if (SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u8ErrorState = DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPort ,SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DotPin , DIO_u8PIN_HIGH);
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
ES_t Seven_Segment_enuClearDisplay(u8 Copy_u8SegID )
{

	ES_t Local_u8ErrorState = ES_NOK;

	u8  Local_u8Iterator;
	u32 Local_u32ErrorCheck = 0;

	if(Copy_u8SegID < NUMBER_OF_SEVEN_SEGMENT)
	{
		if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , DIO_u8PIN_LOW) << 0);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , DIO_u8PIN_LOW) << 3);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , DIO_u8PIN_LOW) << 6);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , DIO_u8PIN_LOW) << 9);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , DIO_u8PIN_LOW) << 12);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , DIO_u8PIN_LOW) << 15);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , DIO_u8PIN_LOW) << 18);
		}
		else if(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , DIO_u8PIN_HIGH) << 0);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , DIO_u8PIN_HIGH) << 3);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , DIO_u8PIN_HIGH) << 6);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , DIO_u8PIN_HIGH) << 9);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , DIO_u8PIN_HIGH) << 12);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , DIO_u8PIN_HIGH) << 15);
			Local_u32ErrorCheck |= (DIO_enuSetPinValue(SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort , SEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , DIO_u8PIN_HIGH) << 18);
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}

		for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u8ErrorState)*8 ; Local_u8Iterator+=3)
		{
			if(((Local_u32ErrorCheck>>Local_u8Iterator) & 7) != ES_OK)
			{
				return Local_u8ErrorState;
			}
		}
		Local_u8ErrorState =ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;


}
