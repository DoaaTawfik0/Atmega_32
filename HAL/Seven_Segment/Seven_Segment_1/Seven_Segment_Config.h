/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Seven_Segment   ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

#include "STD_TYPES.h"
#include "ERROR_STATE.h"

#include "DIO_Interface.h"

#define SEG_APORT DIO_u8PORTA
#define SEG_APIN  DIO_u8PIN0

#define SEG_BPORT DIO_u8PORTA
#define SEG_BPIN  DIO_u8PIN1

#define SEG_CPORT DIO_u8PORTA
#define SEG_CPIN  DIO_u8PIN2

#define SEG_DPORT DIO_u8PORTA
#define SEG_DPIN  DIO_u8PIN3

#define SEG_EPORT DIO_u8PORTA
#define SEG_EPIN  DIO_u8PIN4

#define SEG_FPORT DIO_u8PORTA
#define SEG_FPIN  DIO_u8PIN5

#define SEG_GPORT DIO_u8PORTA
#define SEG_GPIN  DIO_u8PIN6

#define SEG_COMMON_PORT     DIO_u8PORTD
#define SEG_COMMON_PIN      DIO_u8PIN7

#define SEG_DOT_PORT        NOT_CONNECTED
#define SEG_DOT_PIN         NOT_CONNECTED


#define SEG_TYPE            COMMON_CATHODE




#endif
