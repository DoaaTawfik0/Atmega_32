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

#include "../MCAL/TWI/TWI_Interface.h"


#define CODE    1

//MASTER
#if CODE == 0

int main()
{

	TWI_enuInitialize();
	while(1)
	{
		if(ES_OK == TWI_enuStartCondition())
		{
			if(ES_OK == TWI_enuWriteSlaveAddress(5,0))
			{
				if(ES_OK == TWI_enuWriteData('9'))
				{
					TWI_enuStopCondition();
				}
			}

		}

	}
	return 0;
}
//SLAVE
#elif CODE == 1

int main()
{
	u8 Data;
	TWI_enuInitialize();

	while(1)
	{
		if(ES_OK == TWI_enuCheckMyAddress())
		{
			if(ES_OK == TWI_enuReadData(&Data))
			{
				DIO_enuSetPortValue(DIO_u8PORTA , Data);
			}
		}


	}
	return 0;
}

#endif

