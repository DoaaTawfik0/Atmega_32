/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: CLCD            ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "ERROR_STATE.h"
#include "STD_TYPES.h"
ES_t CLCD_enuInit();

ES_t CLCD_enuSendCommand(u8 copy_u8Command);
ES_t CLCD_enuSendData(u8 copy_u8Data);

ES_t CLCD_enuSendString(const char* Copy_pcString);
ES_t CLCD_enuGoToXY(u8 Copy_u8XPosition  , u8 Copy_u8YPosition);
ES_t CLCD_enuWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPosition  , u8 Copy_u8YPosition);
ES_t CLCD_enuWriteNumber(u32 Copy_u32Number);

#endif
