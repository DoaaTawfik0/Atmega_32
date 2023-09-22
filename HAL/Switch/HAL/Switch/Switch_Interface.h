/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LED           ***************/
/**************   Version: 2.00         ***************/
/******************************************************/
/******************************************************/


#ifndef  SWITCH_INTERFACE_H_
#define  SWITCH_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "Switch_Config.h"


#define     SWITCH_PRESSED                   0
#define     SWITCH_NOT_PRESSED               1



ES_t   Switch_enuInitialize(Switch_t *Copy_PStrSwitchConfig);

ES_t    Switch_enuGetSwitchState(Switch_t *Copy_PArrSwitch_ID , u8 *Copy_pu8ReturnState);





#endif
