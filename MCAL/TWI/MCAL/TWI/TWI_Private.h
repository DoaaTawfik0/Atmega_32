/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    TWI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define   MASTER_MODE             2
#define   SLAVE_MODE              3

#define   PRESCALER_1             1UL
#define   PRESCALER_4             4UL
#define   PRESCALER_16            16UL
#define   PRESCALER_64            64UL

#define   DISABLE_GENERAL_CALL    0
#define   ENABLE_GENERAL_CALL     1

#define   START                          0x08
#define   REBEATED_START                 0x10
#define   SLA_R_ACK_RECEIVER             0x40
#define   SLA_W_ACK_TRANSMITTER          0x18
#define   MASTER_TRANSMITTED_DATA_ACK    0x28
#define   SLAVE_TRANSMITTED_DATA_ACK     0xB8
#define   MASTER_RECEIVED_DATA_ACK       0x50
#define   SLAVE_RECEIVED_DATA_ACK        0x80
#define   SLAVE_RECEIVE_SLA_W            0x60
#define   SLAVE_RECEIVE_SLA_R            0xA8

#define   READ                    1
#define   WRITE                   0


#define BIT_RATE(TWI_SPEED)       (((8000000UL/TWI_SPEED)-16UL) / (2UL*TWI_PRESCALER))



#endif

