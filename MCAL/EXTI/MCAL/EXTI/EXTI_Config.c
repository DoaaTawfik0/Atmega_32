/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    EXTI          ***************/
/**************   Version: 2.00         ***************/
/******************************************************/
/******************************************************/

#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/ERROR_STATE.h"

#include  "EXTI_Private.h"
#include  "EXTI_Config.h"
#include  "EXTI_Interface.h"


EXTI_t  EXTI_AstrConfig[EXTI_NUM] = {
		{EXTI_FALLING_EDGE , ACTIVATED},
		{EXTI_RISING_EDGE  , ACTIVATED},
		{EXTI_FALLING_EDGE , ACTIVATED}
};
