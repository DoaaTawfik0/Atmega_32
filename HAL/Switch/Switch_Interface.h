/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Switch          ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "ERROR_STATE.h"
#include "Switch_Private.h"

ES_t Switch_enuInitialize(SW_t* Copy_AstrSwitches);
ES_t Switch_enuGetState(SW_t* Copy_AstrSwitches , u8* Copy_pu8SwitchState);


#endif



