/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: CLCD            ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

/*Defining LCD Mode
 *
 * EIGHT_BIT  define only 8 Pins (D7->D0) for data & 3 for control
 * FOUR_BIT   define only 4 Pins (D7->D4) for data & 3 for control
 *
 * */

#define CLCD_MODE    EIGHT_BIT


/*          Control Pins       */

#define    RS_PORT            DIO_u8PORTB
#define    RS_PIN             DIO_u8PIN0

#define    RW_PORT            DIO_u8PORTB
#define    RW_PIN             DIO_u8PIN1

#define    EN_PORT            DIO_u8PORTB
#define    EN_PIN             DIO_u8PIN2

/*          Data Pins       */
#define    D7_PORT            DIO_u8PORTA
#define    D7_PIN             DIO_u8PIN7

#define    D6_PORT            DIO_u8PORTA
#define    D6_PIN             DIO_u8PIN6

#define    D5_PORT            DIO_u8PORTA
#define    D5_PIN             DIO_u8PIN5

#define    D4_PORT            DIO_u8PORTA
#define    D4_PIN             DIO_u8PIN4

#define    D3_PORT            DIO_u8PORTA
#define    D3_PIN             DIO_u8PIN3

#define    D2_PORT            DIO_u8PORTA
#define    D2_PIN             DIO_u8PIN2

#define    D1_PORT            DIO_u8PORTA
#define    D1_PIN             DIO_u8PIN1

#define    D0_PORT            DIO_u8PORTA
#define    D0_PIN             DIO_u8PIN0



#endif

