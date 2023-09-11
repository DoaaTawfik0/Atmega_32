/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    SPI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#ifndef  SPI_INTERFACE_H_
#define  SPI_INTERFACE_H_

#include "../../LIB/ERROR_STATE.h"

ES_t  SPI_enuMaster_Initialize(void);

ES_t  SPI_enuSlaveInitialize(void);

ES_t  SPI_enuTranceive(u8 Copy_u8TransmitData , u8* Copy_pu8ReceiveData);

ES_t   SPI_enuSPIEnable(void);

ES_t   SPI_enuSPIDisable(void);






#endif
