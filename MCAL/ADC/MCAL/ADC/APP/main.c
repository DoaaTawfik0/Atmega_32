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

#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/EXTI/EXTI_Config.h"
#include "../MCAL/GIE/GIE_Interface.h"

#include "../MCAL/ADC/ADC_Interface.h"
#include "util/delay.h"

void Set(void* t);

int main()
{
	DIO_enuSetPinDirection(DIO_PORTA , DIO_PIN0 , INPUT);
	DIO_enuSetPortDirection(DIO_PORTC , OUTPUT);
	DIO_enuSetPortDirection(DIO_PORTD , OUTPUT);

	u16 x ;

	GIE_enuDisable();
	ADC_enuEnable();
	ADC_enuInitialize();

	//	ADC_enuSelectChannel(2);
	ADC_enuDisableTriggeringMode();//work in single Mode
	// ADC_enuAsynchAnalogRead(0 , Set , &x);

	//	ADC_enuDisableADCInterrupt();
	while(1)
	{
		//ADC_enuAsynchAnalogRead(0 , Set , &x);
		ADC_enuSynchAnalogRead(0 , &x);
		DIO_enuSetPortValue(DIO_PORTC , x);
		DIO_enuSetPortValue(DIO_PORTD , (x>>8));
		//    	ADC_enuStartConversion();
		//    	ADC_enuPollingSystem();
		//        ADC_enuReadHighValue(&ADC_READ_8_Bit);
		//        DIO_enuSetPortValue(DIO_PORTC , ADC_READ_8_Bit);
	}



	return 0;
}
void Set(void* t)
{
	DIO_enuSetPinDirection(DIO_PORTB , DIO_PIN6 , OUTPUT);
	DIO_enuSetPinValue(DIO_PORTB , DIO_PIN6 , HIGH);


}
