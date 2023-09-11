/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    TWI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define   TWI_MODE              MASTER_MODE

#define   TWI_SPEED             100000UL     //Speed should be from 100KHZ To 400KHZ

#define   TWI_PRESCALER         PRESCALER_1

#define   TWI_NODE_ADDRESS      5           //Node Address(Master/Slave)Should be in Range From 2 to 118



#define   TWI_GENERAL_CALL      DISABLE_GENERAL_CALL

#endif
