/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: KeyPad          ***************/
/**************   Version: 2.00        ***************/
/*****************************************************/
/*****************************************************/


#ifndef  KEYPAD_INTERFACE_H_
#define  KEYPAD_INTERFACE_H_

ES_t  KPD_enuInitialize(void);

ES_t  KPD_enuGetPressedKey(u8* Copy_pu8PressedKey);




#endif
