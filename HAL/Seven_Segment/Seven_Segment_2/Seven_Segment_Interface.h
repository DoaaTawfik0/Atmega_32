/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Seven_Segment   ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/


#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_



#include "ERROR_STATE.h"
#include "STD_TYPES.h"
#include "Seven_Segment_Config.h"

ES_t Seven_Segment_enuInitialize(SEG_t *Copy_AstrSegConfig);
ES_t Seven_Segment_enuDisplayNumber(u8 Copy_u8SegID , u8 Copy_u8Number);
ES_t Seven_Segment_enuEnableCommon(u8 Copy_u8SegID );
ES_t Seven_Segment_enuDisableCommon(u8 Copy_u8SegID );
ES_t Seven_Segment_enuEnableDot(u8 Copy_u8SegID );
ES_t Seven_Segment_enuDisableDot(u8 Copy_u8SegID );
ES_t Seven_Segment_enuClearDisplay(u8 Copy_u8SegID );




#endif
