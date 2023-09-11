/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    EXTI            ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


//#include "ERROR_STATE.h"

ES_t  EXTI_enuInitialize(EXTI_t *Copy_pstrEXTIConfig);


ES_t  EXTI_enuSetSenseMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);


ES_t  EXTI_enuEnableInterrupt(u8   Copy_u8EXTI_ID);
ES_t  EXTI_enuDisableInterrupt(u8  Copy_u8EXTI_ID);

ES_t  EXTI_enuCallBack(void(*Copy_pFunAPPFun)(void) , u8  Copy_u8EXTI_ID);




#endif
