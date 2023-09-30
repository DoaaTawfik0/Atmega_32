/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  APP           ***************/
/**************   SWC:    ADC           ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

#include "../MCAL/Port/Port_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

#include "../MCAL/GIE/GIE_Interface.h"

#include "../MCAL/ADC/ADC_Interface.h"

#include "../HAL/LM35/LM35_Interface.h"

#include "util/delay.h"


int main()
{
	DIO_enuSetPinDirection(DIO_PORTA , DIO_PIN0 , INPUT);
	DIO_enuSetPortDirection(DIO_PORTC , OUTPUT);
	//DIO_enuSetPortDirection(DIO_PORTD , OUTPUT);

	u16 x , y ;
	u8 temp;
	GIE_enuDisable();

	ADC_enuEnable();
	ADC_enuInitialize();
	ADC_enuDisableTriggeringMode();
	LM35_enuInitialize();

	//x carry digital value
	//y carry analog voltage in mv

	while(1)
	{
		ADC_enuSynchAnalogRead(0 , &x);
		ADC_enuGetAnalogValue(x , &y);
		LM35_enuGetTemperature(&y , &temp);
		DIO_enuSetPortValue(DIO_PORTC , temp);

	}



	return 0;
}

