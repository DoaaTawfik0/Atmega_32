/*********************************************************/
/*********************************************************/
/**************   Author: Doaa Tawfik      ***************/
/**************   Layer:  HAL              ***************/
/**************   SWC:    Seven_Segment    ***************/
/**************   Version: 2.00            ***************/
/*********************************************************/
/*********************************************************/


#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/ERROR_STATE.h"
#include  "../../LIB/BIT_MATH.h"

#include  "../../MCAL/DIO/DIO_Interface.h"

#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Private.h"


SEG_t  SEG_AStrConfig[SEG_NUM] =
{

		{
				.SEG_u8APort = DIO_PORTA       , .SEG_u8APin = DIO_PIN0       ,
				.SEG_u8BPort = DIO_PORTA       , .SEG_u8BPin = DIO_PIN1       ,
				.SEG_u8CPort = DIO_PORTA       , .SEG_u8CPin = DIO_PIN2       ,
				.SEG_u8DPort = DIO_PORTA       , .SEG_u8DPin = DIO_PIN3       ,
				.SEG_u8EPort = DIO_PORTA       , .SEG_u8EPin = DIO_PIN4       ,
				.SEG_u8FPort = DIO_PORTA       , .SEG_u8FPin = DIO_PIN5       ,
				.SEG_u8GPort = DIO_PORTA       , .SEG_u8GPin = DIO_PIN6       ,
				.SEG_u8CommonPort = DIO_PORTA  , .SEG_u8CommonPin = DIO_PIN7  ,
				.SEG_u8DotPort = DIO_PORTC     , .SEG_u8DotPin = DIO_PIN0     ,
				.SEG_u8Type = COMMON_ANODE

		},
		{
				.SEG_u8APort = DIO_PORTB       , .SEG_u8APin = DIO_PIN0       ,
				.SEG_u8BPort = DIO_PORTB       , .SEG_u8BPin = DIO_PIN1       ,
				.SEG_u8CPort = DIO_PORTB       , .SEG_u8CPin = DIO_PIN2       ,
				.SEG_u8DPort = DIO_PORTB       , .SEG_u8DPin = DIO_PIN3       ,
				.SEG_u8EPort = DIO_PORTB       , .SEG_u8EPin = DIO_PIN4       ,
				.SEG_u8FPort = DIO_PORTB       , .SEG_u8FPin = DIO_PIN5       ,
				.SEG_u8GPort = DIO_PORTB       , .SEG_u8GPin = DIO_PIN6       ,
				.SEG_u8CommonPort = DIO_PORTB  , .SEG_u8CommonPin = DIO_PIN7  ,
				.SEG_u8DotPort = DIO_PORTC     , .SEG_u8DotPin = DIO_PIN1     ,
				.SEG_u8Type = COMMON_CATHODE

		},
};

