/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  APP           ***************/
/**************   SWC:    UART          ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

#include "../MCAL/Port/Port_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

#include "../MCAL/UART/UART_Interface.h"

int main()
{
	char data[50];
	//u8  Data;

	PORT_voidInit();
	USART_enuInitialize();

	//USART_enuSynchReceiveChar(&Data);
	//USART_enuSynchSendChar(Data);

	while(1)
	{

		USART_enuSynchReceiveString(data);
		USART_enuSynchSendString(data);
		USART_enuSynchSendString("\r");
	}
	return 0;
}

