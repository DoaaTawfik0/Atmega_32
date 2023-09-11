/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    EXTI            ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#include "EXTI_Config.h"

#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_Private.h"


EXTI_t  EXTI_AstrEXTIConfig[NUMBER_OF_INTERRUPT_PINS] =
{
		{ACTIVATED , ANY_LOGICAL_CHANGE},   /*INT0*/
		{DISACTIVATED},               /*INT1*/
		{DISACTIVATED}                /*INT2*/

};


