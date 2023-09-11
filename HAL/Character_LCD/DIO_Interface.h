/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: MCAL          ***************/
/**************   SWC: DIO             ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "ERROR_STATE.h"

#define DIO_u8PORTA             0
#define DIO_u8PORTB             1
#define DIO_u8PORTC             2
#define DIO_u8PORTD             3

#define DIO_u8PIN0          0
#define DIO_u8PIN1          1
#define DIO_u8PIN2          2
#define DIO_u8PIN3          3
#define DIO_u8PIN4          4
#define DIO_u8PIN5          5
#define DIO_u8PIN6          6
#define DIO_u8PIN7          7





#define DIO_u8PIN_HIGH          1
#define DIO_u8PIN_LOW           0

#define DIO_u8PIN_FLOAT         0
#define DIO_u8PIN_PULL_UP       1

#define DIO_u8PIN_OUTPUT       1
#define DIO_u8PIN_INPUT        0

#define DIO_u8PORT_OUTPUT       0xFF
#define DIO_u8PORT_INPUT        0

#define DIO_u8PORT_HIGH         0xFF
#define DIO_u8PORT_LOW          0


//Initialization Function
ES_t DIO_enuInitialize(void);

//Set_Direction_Functions
ES_t DIO_enuSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction);
ES_t DIO_enuSetPortDirection(u8 copy_u8Port , u8 copy_u8Direction);

//Set_Value_Functions
ES_t DIO_enuSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value);
ES_t DIO_enuSetPortValue(u8 copy_u8Port , u8 copy_u8Value);

//Toggle_Value_Functions
ES_t DIO_enuTogPinValue(u8 copy_u8Port , u8 copy_u8Pin);
ES_t DIO_enuTogPortValue(u8 copy_u8Port);

//Get_Value_Functions
ES_t DIO_enuGetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8* copy_Pu8Value);
ES_t DIO_enuGetPortValue(u8 copy_u8Port , u8* copy_pu8Value);


#endif
