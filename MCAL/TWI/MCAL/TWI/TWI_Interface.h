/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    TWI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

ES_t   TWI_enuInitialize(void);

ES_t   TWI_enuStartCondition(void);
ES_t   TWI_enuRebeatedStartCondition(void);

ES_t   TWI_enuStopCondition(void);

ES_t   TWI_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress  , u8 Copy_u8Operation);

ES_t   TWI_enuCheckMyAddress(void);

ES_t   TWI_enuWriteData(u8 Copy_u8Data);
ES_t   TWI_enuReadData(u8* Copy_pu8Data);


#endif

