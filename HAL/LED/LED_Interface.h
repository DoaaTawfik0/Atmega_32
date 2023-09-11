/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LED           ***************/
/**************   Version:1.00          ***************/
/*****************************************************/
/*****************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "ERROR_STATE.h"
#include "LED_Config.h"

ES_t LED_enuInitialize(LED_t* Copy_pstrLedStates);
ES_t LED_enuTurnON(LED_t* Copy_pstrLedSID);
ES_t LED_enuTurnOFF(LED_t* Copy_pstrLedID);




#endif
