/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    EXTI          ***************/
/**************   Version: 2.00         ***************/
/******************************************************/
/******************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include  "../../LIB/ERROR_STATE.h"
#include  "EXTI_Config.h"


ES_t  EXTI_enuInitialize(EXTI_t *Copy_PStrEXTIConfig);

ES_t  EXTI_enuChangeSenseLevel(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);

ES_t  EXTI_enuEnableInterrupt(u8 Copy_u8EXTI_ID);
ES_t  EXTI_enuDisableInterrupt(u8 Copy_u8EXTI_ID);

ES_t  EXTI_enuCallBackFunction(volatile void (*Copy_pfunAppFun) (void*) , volatile void *Copy_PvidAppParameter, u8  Copy_u8EXTI_ID);

#endif
