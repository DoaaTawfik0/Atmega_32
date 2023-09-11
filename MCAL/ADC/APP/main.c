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


int main()
{
	u8  ADC_READ_8_Bit = 0;
	u16 ADC_READ_16_Bit = 0;

	PORT_voidInit();

	ADC_enuEnable();
	ADC_enuInitialize();

	ADC_enuSelectChannel(2);
    ADC_enuDisableTriggeringMode();//work in single Mode
	ADC_enuDisableInterruptMode();

    while(1)
	{

    	ADC_enuStartConversion();
    	ADC_enuPollingSystem();
        ADC_enuReadHighValue(&ADC_READ_8_Bit);
        DIO_enuSetPortValue(DIO_u8PORTC , ADC_READ_8_Bit);
	}



	return 0;
}
