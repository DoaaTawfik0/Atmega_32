/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    GIE             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#include   "../../LIB/STD_TYPES.h"
#include   "../../LIB/ERROR_STATE.h"
#include   "../../LIB/BIT_MATH.h"


#include   "GIE_Interface.h"
#include   "GIE_Private.h"


ES_t   GIE_enuEnable(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(SREG , SREG_I);

	return   Local_enuErrorState;
}

ES_t   GIE_enuDisable(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	CLEAR_BIT(SREG , SREG_I);

	return   Local_enuErrorState;
}
