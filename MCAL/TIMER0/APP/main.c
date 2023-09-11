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

#include "../MCAL/Interrupt.h"

#include "../MCAL/GIE/GIE_Interface.h"

#include "../MCAL/Timer0/Timer0_Interface.h"

void Toggle(void *P);
int main()
{
	PORT_voidInit();
	TIMER0_enuInitialize();
	TIMER0_enuGeneratePWM(250);
	//TIMER0_enuASynchDelay_ms(9000 , Toggle , NULL);
	//GIE_enuEnable();

	while(1)
	{
		/*for SynchDelay */
		/*
		 DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
		 TIMER0_enuSynchDelay_ms(5000);
		 */
	}



	return 0;
}
void Toggle(void *P)
{
	DIO_enuTogPinValue(DIO_u8PORTA,DIO_u8PIN0);
}
