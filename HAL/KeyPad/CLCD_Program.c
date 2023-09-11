/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: CLCD            ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#include <util/delay.h>


#include "ERROR_STATE.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"


#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "CLCD_Config.h"





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuInit.                                         **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : void.                                                 **/
/** Functionality   : Initialize LCD                                        **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuInit()
{

	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT , RS_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(RW_PORT , RW_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(EN_PORT , EN_PIN , DIO_u8PIN_OUTPUT);

	DIO_enuSetPinDirection(D7_PORT , D7_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D6_PORT , D6_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D5_PORT , D5_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D4_PORT , D4_PIN , DIO_u8PIN_OUTPUT);

	DIO_enuSetPinValue(RS_PORT , RS_PIN ,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(RW_PORT , RW_PIN ,DIO_u8PIN_LOW);

	_delay_ms(40);



#if CLCD_MODE == EIGHT_BIT
	DIO_enuSetPinDirection(D3_PORT , D3_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D2_PORT , D2_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D1_PORT , D1_PIN , DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D0_PORT , D0_PIN , DIO_u8PIN_OUTPUT);



	CLCD_inu8SendCommand(FUNCTION_SET_EIGHT_BIT);


#elif CLCD_MODE == FOUR_BIT

	CLCD_inu8SendCommand(FUNCTION_SET_FOUR_BIT);
#else
	Local_enuErrorState = ES_ES_OUT_OF_RANGE;

#endif

	_delay_ms(1);

	CLCD_inu8SendCommand(DISPLAY_ON_OFF);

	_delay_ms(1);

	CLCD_inu8SendCommand(DISPLAY_CLEAR);

	_delay_ms(2);

	CLCD_inu8SendCommand(ENTRY_MODE_SET);

	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuSendCommand.                                  **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : copy_u8Command.                                       **/
/** Functionality   : Send Command to LCD                                   **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuSendCommand(u8 copy_u8Command)
{

	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN ,DIO_u8PIN_LOW);

	CLCD_u8Latch(copy_u8Command);

	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuSendData.                                     **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : copy_u8Data.                                          **/
/** Functionality   : Send Data to LCD                                      **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuSendData(u8 copy_u8Data)
{

	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN ,DIO_u8PIN_HIGH);

	CLCD_u8Latch(copy_u8Data);

	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_u8Latch.                                         **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : copy_u8Data.                                          **/
/** Functionality   : Local Function to serve send data & command function  **/
/*****************************************************************************/
/*****************************************************************************/

static ES_t CLCD_u8Latch(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;


	DIO_enuSetPinValue(RW_PORT , RW_PIN ,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN ,DIO_u8PIN_LOW);

	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));

#if CLCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Data>>0)&1));
#elif CLCD_MODE == FOUR_BIT

#else
	Local_enuErrorState = ES_ES_OUT_OF_RANGE;
#endif
	DIO_enuSetPinValue(EN_PORT , EN_PIN ,DIO_u8PIN_HIGH);
	_delay_ms(20);
	DIO_enuSetPinValue(EN_PORT , EN_PIN ,DIO_u8PIN_LOW);
	Local_enuErrorState = ES_OK;
	return  Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_inu8SendCommand.                                 **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : copy_u8Data.                                          **/
/** Functionality   : Local Function to serve other functions in lcd        **/
/*****************************************************************************/
/*****************************************************************************/

static inline ES_t CLCD_inu8SendCommand(u8 copy_u8Command)
{

	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN ,DIO_u8PIN_LOW);

	CLCD_u8Latch(copy_u8Command);

	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuSendString.                                   **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_pcString pointer to char.                        **/
/** Functionality   : Send String to function                               **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuSendString(const char* Copy_pcString)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8   Local_u8Iterator = 0;
	if(Copy_pcString != NULL)
	{
		while(Copy_pcString[Local_u8Iterator] != '\0')
		{
			CLCD_enuSendData(Copy_pcString[Local_u8Iterator]);
			Local_u8Iterator++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{

		Local_enuErrorState = ES_NULL_POINTER;
	}



	return Local_enuErrorState;

}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuGoToXY.                                       **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u8XPosition , Copy_u8YPosition.                  **/
/** Functionality   : Go to X & Y Position at LCD                           **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuGoToXY(u8 Copy_u8XPosition  , u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8   Local_u8Address = 0;
	if( ((Copy_u8XPosition >= 0) || (Copy_u8XPosition < 2)) && ((Copy_u8YPosition >= 0) && (Copy_u8YPosition < 16)))
	{
		if(Copy_u8XPosition == 0)
		{
			Local_u8Address = Copy_u8YPosition;
		}
		else
		{
			Local_u8Address = Copy_u8YPosition+0x40;
		}
		//Set DDRAM Address Command: 128 to set bit '8' with value one
		CLCD_inu8SendCommand(Local_u8Address+128);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuWriteSpecialCharacter.                        **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_pu8Pattern , Copy_u8PatternNumber , Copy_u8XPosition , Copy_u8YPosition **/
/** Functionality   : Write special char at lcd                             **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPosition  , u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8   Local_u8Iterator  ,Local_u8Address;;
	if(Copy_pu8Pattern != NULL)
	{
		Local_u8Address = Copy_u8PatternNumber*8;
		//Set CGRAM Address Command: 64 to set bit '7' with value one
		CLCD_inu8SendCommand(Local_u8Address+64);
		for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator++)
		{
			CLCD_enuSendData(Copy_pu8Pattern[Local_u8Iterator]);
		}
		CLCD_enuGoToXY(Copy_u8XPosition , Copy_u8YPosition);
		CLCD_enuSendData(Copy_u8PatternNumber);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;

}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : CLCD_enuWriteNumber.                                  **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u32Number                                        **/
/** Functionality   : Write any number on lcd                               **/
/*****************************************************************************/
/*****************************************************************************/

ES_t CLCD_enuWriteNumber(u32 Copy_u32Number)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32 Local_u32rev_num = 1;


	while(Copy_u32Number != 0)
	{
		Local_u32rev_num = ((Local_u32rev_num*10) + (Copy_u32Number%10));
		Copy_u32Number /= 10;
	}

	while(Local_u32rev_num != 1)
	{

		CLCD_enuSendData((Local_u32rev_num%10)+'0');

		Local_u32rev_num /= 10;

	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}


