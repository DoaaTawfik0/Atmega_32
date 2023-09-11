#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

//Function to initialize Ports Direction & values
ES_t DIO_enuInitialize(void)
{
	ES_t Local_enuErrorState = ES_OK;
	DDRA = CONC(PA_PIN7_DIR , PA_PIN6_DIR , PA_PIN5_DIR , PA_PIN4_DIR , PA_PIN3_DIR , PA_PIN2_DIR , PA_PIN1_DIR , PA_PIN0_DIR);
	DDRB = CONC(PB_PIN7_DIR , PB_PIN6_DIR , PB_PIN5_DIR , PB_PIN4_DIR , PB_PIN3_DIR , PB_PIN2_DIR , PB_PIN1_DIR , PB_PIN0_DIR);
	DDRC = CONC(PC_PIN7_DIR , PC_PIN6_DIR , PC_PIN5_DIR , PC_PIN4_DIR , PC_PIN3_DIR , PC_PIN2_DIR , PC_PIN1_DIR , PC_PIN0_DIR);
	DDRD = CONC(PD_PIN7_DIR , PD_PIN6_DIR , PD_PIN5_DIR , PD_PIN4_DIR , PD_PIN3_DIR , PD_PIN2_DIR , PD_PIN1_DIR , PD_PIN0_DIR);


	PORTA = CONC(PA_PIN7_VAL , PA_PIN6_VAL , PA_PIN5_VAL , PA_PIN4_VAL , PA_PIN3_VAL , PA_PIN2_VAL , PA_PIN1_VAL , PA_PIN0_VAL);
	PORTB = CONC(PB_PIN7_VAL , PB_PIN6_VAL , PB_PIN5_VAL , PB_PIN4_VAL , PB_PIN3_VAL , PB_PIN2_VAL , PB_PIN1_VAL , PB_PIN0_VAL);
	PORTC = CONC(PC_PIN7_VAL , PC_PIN6_VAL , PC_PIN5_VAL , PC_PIN4_VAL , PC_PIN3_VAL , PC_PIN2_VAL , PC_PIN1_VAL , PC_PIN0_VAL);
	PORTD = CONC(PD_PIN7_VAL , PD_PIN6_VAL , PD_PIN5_VAL , PD_PIN4_VAL , PD_PIN3_VAL , PD_PIN2_VAL , PD_PIN1_VAL , PD_PIN0_VAL);

	return Local_enuErrorState;
}
                                             /*************Port Functions***************/
//Function to set Port Direction
ES_t DIO_enuSetPortDirection(u8 copy_u8Port , u8 copy_u8Direction)
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(copy_u8Port <= DIO_u8PORTD)
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA : DDRA = copy_u8Direction ; break;
		case DIO_u8PORTB : DDRB = copy_u8Direction ; break;
		case DIO_u8PORTC : DDRC = copy_u8Direction ; break;
		case DIO_u8PORTD : DDRD = copy_u8Direction ; break;
		} Local_u8ErrorState = ES_OK ;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}
//Function to Set Port Value
ES_t DIO_enuSetPortValue(u8 copy_u8Port , u8 copy_u8Value)
{
	ES_t Local_u8ErrorState = ES_NOK;
	if(copy_u8Port <= DIO_u8PORTD)
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA : PORTA = copy_u8Value ; break;
		case DIO_u8PORTB : PORTB = copy_u8Value ; break;
		case DIO_u8PORTC : PORTC = copy_u8Value ; break;
		case DIO_u8PORTD : PORTD = copy_u8Value ; break;
		} Local_u8ErrorState = ES_OK ;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;

}
//Function to Toggle Port Value
ES_t DIO_enuTogPortValue(u8 copy_u8Port)
{

	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if(copy_u8Port <= DIO_u8PORTD)
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA : PORTA = ~PORTA ; break;
		case DIO_u8PORTB : PORTB = ~PORTB ; break;
		case DIO_u8PORTC : PORTC = ~PORTC ; break;
		case DIO_u8PORTD : PORTD = ~PORTD ; break;
		} Local_u8ErrorState = ES_OK ;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;

}
//Function to Get Port Value
ES_t DIO_enuGetPortValue(u8 copy_u8Port , u8* copy_pu8Value)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if(copy_pu8Value != NULL)
	{
		if(copy_u8Port <= DIO_u8PORTD)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA : *copy_pu8Value = PINA ; break;
			case DIO_u8PORTB : *copy_pu8Value = PINB ; break;
			case DIO_u8PORTC : *copy_pu8Value = PINC ; break;
			case DIO_u8PORTD : *copy_pu8Value = PIND  ; break;
			} Local_u8ErrorState = ES_OK ;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
                                             /*************Pin Functions***************/
//Function to Set Pin Direction
ES_t DIO_enuSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
	{
		if(copy_u8Direction == OUTPUT)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(DDRA , copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(DDRB , copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(DDRC , copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(DDRD , copy_u8Pin); break;

			}Local_u8ErrorState = ES_OK;
		}
		else if(copy_u8Direction == INPUT)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: CLEAR_BIT(DDRA , copy_u8Pin); break;
			case DIO_u8PORTB: CLEAR_BIT(DDRB , copy_u8Pin); break;
			case DIO_u8PORTC: CLEAR_BIT(DDRC , copy_u8Pin); break;
			case DIO_u8PORTD: CLEAR_BIT(DDRD , copy_u8Pin); break;

			}Local_u8ErrorState = ES_OK;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}


	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
//Function to Set Pin Value
ES_t DIO_enuSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
	{
		if(copy_u8Value == HIGH)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA , copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB , copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC , copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;
		}
		else if(copy_u8Value == LOW)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: CLEAR_BIT(PORTA , copy_u8Pin); break;
			case DIO_u8PORTB: CLEAR_BIT(PORTB , copy_u8Pin); break;
			case DIO_u8PORTC: CLEAR_BIT(PORTC , copy_u8Pin); break;
			case DIO_u8PORTD: CLEAR_BIT(PORTD , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}


	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
//Function to Toggle Pin Value
ES_t DIO_enuTogPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA: TOGGLE_BIT(PORTA , copy_u8Pin); break;
		case DIO_u8PORTB: TOGGLE_BIT(PORTB , copy_u8Pin); break;
		case DIO_u8PORTC: TOGGLE_BIT(PORTC , copy_u8Pin); break;
		case DIO_u8PORTD: TOGGLE_BIT(PORTD , copy_u8Pin); break;
		}Local_u8ErrorState = ES_OK;

	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
//Function to Get Pin Value
ES_t DIO_enuGetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8* copy_Pu8Value)//pu8 pointer to u8
{
	ES_t Local_u8ErrorState = ES_NOK; //0 indicates no problem
	if(copy_Pu8Value != NULL)
	{
		if((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Port <= DIO_u8PORTD))
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: *copy_Pu8Value = GET_BIT(PINA , copy_u8Pin); break;
			case DIO_u8PORTB: *copy_Pu8Value = GET_BIT(PINB , copy_u8Pin); break;
			case DIO_u8PORTC: *copy_Pu8Value = GET_BIT(PINC , copy_u8Pin); break;
			case DIO_u8PORTD: *copy_Pu8Value = GET_BIT(PIND , copy_u8Pin); break;
			}Local_u8ErrorState = ES_OK;

		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}

	return Local_u8ErrorState;

}

