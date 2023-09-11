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

#define NUMBER_OF_SEVEN_SEGMENT  2


typedef struct
{
	u8 SEG_u8APort;
	u8 SEG_u8APin;

	u8 SEG_u8BPort;
	u8 SEG_u8BPin;

	u8 SEG_u8CPort;
	u8 SEG_u8CPin;

	u8 SEG_u8DPort;
	u8 SEG_u8DPin;

	u8 SEG_u8EPort;
	u8 SEG_u8EPin;

	u8 SEG_u8FPort;
	u8 SEG_u8FPin;

	u8 SEG_u8GPort;
	u8 SEG_u8GPin;

	u8 SEG_u8CommonPort;
	u8 SEG_u8CommonPin;

	u8 SEG_u8DotPort;
	u8 SEG_u8DotPin;

	u8 SEG_u8Type;
}SEG_t;





#endif




