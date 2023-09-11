/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: HAL           ***************/
/**************   SWC: Seven_Segment   ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/
#include "STD_TYPES.h"

#include "DIO_Interface.h"

#include "Seven_Segment_Config.h"
#include "Seven_Segment_Private.h"
#include "Seven_Segment_Interface.h"



SEG_t SEG_AstrSegConfig[NUMBER_OF_SEVEN_SEGMENT] =
{
		{
				DIO_u8PORTC   , DIO_u8PIN0    ,
				DIO_u8PORTC   , DIO_u8PIN1    ,
				DIO_u8PORTC   , DIO_u8PIN2    ,
				DIO_u8PORTC   , DIO_u8PIN3    ,
				DIO_u8PORTC   , DIO_u8PIN4    ,
				DIO_u8PORTC   , DIO_u8PIN5    ,
				DIO_u8PORTC   , DIO_u8PIN6    ,
				DIO_u8PORTD , DIO_u8PIN0 ,
				DIO_u8PORTC , DIO_u8PIN7 ,
				COMMON_CATHODE

		},
		{
				DIO_u8PORTD   , DIO_u8PIN1   ,
				DIO_u8PORTD   ,  DIO_u8PIN2   ,
				DIO_u8PORTD   , DIO_u8PIN3   ,
				DIO_u8PORTD   , DIO_u8PIN4    ,
				DIO_u8PORTD   , DIO_u8PIN5    ,
				DIO_u8PORTD   , DIO_u8PIN6    ,
				DIO_u8PORTD   , DIO_u8PIN7    ,
				DIO_u8PORTA , DIO_u8PIN0 ,
				NOT_CONNECTED , NOT_CONNECTED ,
				COMMON_ANODE
		}
};


