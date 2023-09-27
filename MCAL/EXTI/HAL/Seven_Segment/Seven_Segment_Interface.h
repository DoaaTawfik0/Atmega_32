/*********************************************************/
/*********************************************************/
/**************   Author: Doaa Tawfik      ***************/
/**************   Layer:  HAL              ***************/
/**************   SWC:    Seven_Segment    ***************/
/**************   Version: 2.00            ***************/
/*********************************************************/
/*********************************************************/


#ifndef  SEVEN_SEGMENT_INTERFACE_H_
#define  SEVEN_SEGMENT_INTERFACE_H_

#include "../../LIB/ERROR_STATE.h"
#include "Seven_Segment_Config.h"


#define   SEG_NUM         2

ES_t SEVEN_SEG_enuInitialize(SEG_t *Copy_PStrConfig);

ES_t SEVEN_SEG_enuDisplay_Number(SEG_t *Copy_PArrSEG_ID , u8 Copy_u8Number);
ES_t SEVEN_SEG_enuClearDisplay(SEG_t *Copy_PArrSEG_ID);

ES_t SEVEN_SEG_enuEnableCommon(SEG_t *Copy_PArrSEG_ID);
ES_t SEVEN_SEG_enuDisableCommon(SEG_t *Copy_PArrSEG_ID);

ES_t SEVEN_SEG_enuEnableDot(SEG_t *Copy_PArrSEG_ID);
ES_t SEVEN_SEG_enuDisableDot(SEG_t *Copy_PArrSEG_ID);


#endif
