/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: KeyPad          ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"

#include"DIO_Interface.h"

#include "Keypad_Config.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Private.h"



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : KeyPad_u8PressedKey.                                  **/
/** Return Type     : u8.                                                   **/
/** Arguments       : void.                                                 **/
/** Functionality   : Getting Pressed Key in KeyPad.                        **/
/*****************************************************************************/
/*****************************************************************************/
u8 KeyPad_u8PressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8RowIndex , Local_u8ColumnIndex , Local_Pin_State;


	static u8 Local_u8KPDArr[KPD_ROW_NUMBER][KPD_COLUMN_NUMBER] = KPD_ARR_VALUE ;

	static u8 Local_u8KPDColumnsArray[KPD_COLUMN_NUMBER] = {KPD_COLUMN0_PIN , KPD_COLUMN1_PIN , KPD_COLUMN2_PIN , KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowsArray[KPD_ROW_NUMBER] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};


	for(Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < KPD_COLUMN_NUMBER ; Local_u8ColumnIndex++)
	{
		/* Activation Current Column by setting its value with LOW */
		DIO_enuSetPinValue(KPD_PORT , Local_u8KPDColumnsArray[Local_u8ColumnIndex] , DIO_u8PIN_LOW);

		for(Local_u8RowIndex = 0 ; Local_u8RowIndex < KPD_ROW_NUMBER ; Local_u8RowIndex++)
		{
			/*Reading Current Row Value*/
			DIO_enuGetPinValue(KPD_PORT , Local_u8KPDRowsArray[Local_u8RowIndex] , &Local_Pin_State);

			/*Checking on Pin State*/
			if(Local_Pin_State == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*Polling(Busy Waiting until key is released)*/
				while(Local_Pin_State == DIO_u8PIN_LOW)
				{
					DIO_enuGetPinValue(KPD_PORT , Local_u8KPDRowsArray[Local_u8RowIndex] , &Local_Pin_State);
				}
				return Local_u8PressedKey;
			}
		}
		/* Deactivate Current Column by setting its value with HIGH */
		DIO_enuSetPinValue(KPD_PORT , Local_u8KPDColumnsArray[Local_u8ColumnIndex] , DIO_u8PIN_HIGH);
	}


	return Local_u8PressedKey;
}
