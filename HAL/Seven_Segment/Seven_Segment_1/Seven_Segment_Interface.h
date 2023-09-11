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

ES_t Seven_Segment_enuInitialize(void);
ES_t Seven_Segment_enuDisplayNumber(u8 Copy_u8Number);
ES_t Seven_Segment_enuEnableCommon(void);
ES_t Seven_Segment_enuDisableCommon(void);
ES_t Seven_Segment_enuEnableDot(void);
ES_t Seven_Segment_enuDisableDot(void);
ES_t Seven_Segment_enuClearDisplay(void);


#endif
