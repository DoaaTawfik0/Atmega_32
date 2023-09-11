/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Seven_Segment   ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "ERROR_STATE.h"

#include "DIO_Interface.h"

#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Private.h"


ES_t Seven_Segment_enuInitialize(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32ErrorCheck = 0;
	u8 Local_u8Iterator = 0;

	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_APORT , SEG_APIN , DIO_u8PIN_OUTPUT) << 0);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_BPORT , SEG_BPIN , DIO_u8PIN_OUTPUT) << 3);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_CPORT , SEG_CPIN , DIO_u8PIN_OUTPUT) << 6);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_DPORT , SEG_DPIN , DIO_u8PIN_OUTPUT) << 9);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_EPORT , SEG_EPIN , DIO_u8PIN_OUTPUT) << 12);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_FPORT , SEG_FPIN , DIO_u8PIN_OUTPUT) << 15);
	Local_u32ErrorCheck |= (DIO_enuSetPinDirection(SEG_GPORT , SEG_GPIN , DIO_u8PIN_OUTPUT) << 18);

#if  SEG_COMMON_PIN <= DIO_u8PIN7 && SEG_COMMON_PORT <= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_COMMON_PIN , SEG_COMMON_PORT , DIO_u8PIN_OUTPUT);
#elif (SEG_COMMON_PIN == NOT_CONNECTED  || SEG_COMMON_PORT == NOT_CONNECTED)

#else
//#error "Your Common Pin has a Wrong Selection"

#endif


#if  SEG_DOT_PIN <= DIO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_DOT_PORT, DIO_u8PIN7 , DIO_u8PIN_OUTPUT);
#elif (SEG_COMMON_PIN == NOT_CONNECTED  || SEG_COMMON_PORT == NOT_CONNECTED)

#else

#error "Your Dot Pin has a Wrong Selection"

#endif

	for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u32ErrorCheck)*8 ; Local_u8Iterator += 3)
	{
		if(((Local_u32ErrorCheck>>Local_u8Iterator)&7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}Local_enuErrorState = ES_OK;



	return Local_enuErrorState;

}
ES_t Seven_Segment_enuDisplayNumber(u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32ErrorCheck = 0;
	u8 Local_u8Iterator;
	if(Copy_u8Number < 10)
	{
#if SEG_TYPE == COMMON_CATHODE
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_APORT , SEG_APIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 0) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 1) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 2) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 3) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 4) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 5) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN , ((SEG_Au8DisplayNumber[Copy_u8Number] >> 6) &1 ));
#elif SEG_TYPE == COMMON_ANODE
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_APORT , SEG_APIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 0) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 1) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 2) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 3) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 4) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 5) &1 ));
		Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN , !((SEG_Au8DisplayNumber[Copy_u8Number] >> 6) &1 ));
#else
#error"Seven Segment Type has a Wrong Selection"
#endif
	}
	else
	{
		return Local_enuErrorState;
	}
	for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u32ErrorCheck)*8 ; Local_u8Iterator += 3)
	{
		if(((Local_u32ErrorCheck>>Local_u8Iterator)&7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}
ES_t Seven_Segment_enuEnableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if SEG_COMMON_PORT <= DIO_u8PORTD && SEG_COMMON_PIN <= DIO_u8PIN7
#if SEG_TYPE == COMMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_LOW);
#elif SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_HIGH);
#else
	#error "Seven Segment Type has a wrong selection"
#endif
#elif SEG_COMMON_PORT == NOT_CONNECTED && SEG_COMMON_PIN == NOT_CONNECTED

#else
	#error "Seven Segment pin has a wrong selection"

#endif

	return Local_enuErrorState;

}
ES_t Seven_Segment_enuDisableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if SEG_COMMON_PORT <= DIO_u8PORTD && SEG_COMMON_PIN <= DIO_u8PIN7
#if SEG_TYPE == COMMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_HIGH);
#elif SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_LOW);
#else "Seven Segment Type has a wrong selection";
#endif
#elif SEG_COMMON_PORT == NOT_CONNECTED && SEG_COMMON_PIN == NOT_CONNECTED

#else
	#error"Seven Segment Common Pin has a wrong selection"

#endif

	return Local_enuErrorState;

}
ES_t Seven_Segment_enuEnableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if ((SEG_DOT_PORT <= DIO_u8PORTD) && (SEG_DOT_PIN <= DIO_u8PIN7))
#if SEG_TYPE == COMMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_HIGH);
#elif SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_LOW);
#else
	"Seven Segment Type has a wrong selection"
#endif
#elif ((SEG_COMMON_PORT == NOT_CONNECTED) && (SEG_COMMON_PIN == NOT_CONNECTED)

#else
	"Seven Segment pin has a wrong selection"

#endif

	return Local_enuErrorState;

}
ES_t Seven_Segment_enuDisableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if ((SEG_DOT_PORT <= DIO_u8PORTD) && (SEG_DOT_PIN <= DIO_u8PIN7))
#if SEG_TYPE == COMMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_LOW);
#elif SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_COMMON_PORT , SEG_COMMON_PIN , DIO_u8PIN_HIGH);
#else
	"Seven Segment Type has a wrong selection"
#endif
#elif ((SEG_COMMON_PORT == NOT_CONNECTED) && (SEG_COMMON_PIN == NOT_CONNECTED)

#else
	"Seven Segment pin has a wrong selection"

#endif

	return Local_enuErrorState;

}
ES_t Seven_Segment_enuClearDisplay(void)
{
	ES_t Local_enuErrorState = ES_NOK;

		u32 Local_u32ErrorCheck = 0;
		u8 Local_u8Iterator;

	#if SEG_TYPE == COMMON_CATHODE
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_APORT , SEG_APIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN , DIO_u8PIN_LOW );
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN , DIO_u8PIN_LOW );
	#elif SEG_TYPE == COMMON_ANODE
			Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_APORT , SEG_APIN , DIO_u8PIN_LOW );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN , DIO_u8PIN_HIGH );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN , DIO_u8PIN_HIGH );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN , DIO_u8PIN_HIGH );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN , DIO_u8PIN_HIGH );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN , DIO_u8PIN_HIGH );
						Local_u32ErrorCheck |= DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN , DIO_u8PIN_HIGH );
	#else
	#error"Seven Segment Type has a Wrong Selection"
	#endif


		for(Local_u8Iterator = 0 ; Local_u8Iterator < sizeof(Local_u32ErrorCheck)*8 ; Local_u8Iterator += 3)
		{
			if(((Local_u32ErrorCheck>>Local_u8Iterator)&7) != ES_OK)
			{
				return Local_enuErrorState;
			}
		}Local_enuErrorState = ES_OK;

		return Local_enuErrorState;

}


