/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    EXTI            ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/



#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"

#include "EXTI_Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"

#include "Interrupt.h"


/*
 * Creating Global Pointer To Function To use in Call_Back Function
 * EXTI_ApFunINTFun >> INTFun is an array of pointer to function
 */
static volatile void (* EXTI_ApFunINTFun[3])(void) = {NULL , NULL , NULL};




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : EXTI_enuInitialize.                                   **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_pstrEXTIConfig.                                  **/
/** Functionality   : Initialize EXTI                                       **/
/*****************************************************************************/
/*****************************************************************************/


ES_t  EXTI_enuInitialize(EXTI_t *Copy_pstrEXTIConfig)
{
	ES_t  Local_enuErrorState = ES_NOK;
	u8    Local_u8Iterator = 0;

	if(Copy_pstrEXTIConfig != NULL)
	{
		/*Iterate on AstrEXTIConfig to check which interrupt pin is activated & initialize it*/
		for(Local_u8Iterator = 0 ; Local_u8Iterator < NUMBER_OF_INTERRUPT_PINS ; Local_u8Iterator++)
		{
			if(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_u8State == ACTIVATED)
			{
				switch(Local_u8Iterator)
				{
				case 0:

					/*Clearing MCUCR bits for INT1*/

					CLEAR_BIT(MCUCR , MCUCR_ISC10);
					CLEAR_BIT(MCUCR , MCUCR_ISC11);

					/*Enable PIE For INT0*/
					SET_BIT(GICR , GICR_INT0);

					/*Choosing Interrupt Sense Control for INT0*/
					switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_u8SenseLevel)
					{
					case FALLING_EDGE:
						SET_BIT(MCUCR , MCUCR_ISC01);
						CLEAR_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case RISING_EDGE:
						SET_BIT(MCUCR , MCUCR_ISC01);
						SET_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case ANY_LOGICAL_CHANGE:
						CLEAR_BIT(MCUCR , MCUCR_ISC01);
						SET_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case LOW_LEVEL:
						CLEAR_BIT(MCUCR , MCUCR_ISC01);
						CLEAR_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;

					}
					break;
					case 1:

						/*Clearing MCUCR bits for INT1*/

						CLEAR_BIT(MCUCR , MCUCR_ISC00);
						CLEAR_BIT(MCUCR , MCUCR_ISC01);

						/*Enable PIE For INT1*/
						SET_BIT(GICR , GICR_INT1);

						/*Choosing Interrupt Sense Control for INT1*/
						switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_u8SenseLevel)
						{
						case FALLING_EDGE:
							SET_BIT(MCUCR , MCUCR_ISC11);
							CLEAR_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case RISING_EDGE:
							SET_BIT(MCUCR , MCUCR_ISC11);
							SET_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case ANY_LOGICAL_CHANGE:
							CLEAR_BIT(MCUCR , MCUCR_ISC11);
							SET_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case LOW_LEVEL:
							CLEAR_BIT(MCUCR , MCUCR_ISC11);
							CLEAR_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						default:
							Local_enuErrorState = ES_OUT_OF_RANGE;

						}
						break;
						case 2:

							/*Enable PIE For INT2*/
							SET_BIT(GICR , GICR_INT2);

							/*Choosing Interrupt Sense Control for INT2*/
							switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_u8SenseLevel)
							{
							case FALLING_EDGE:
								CLEAR_BIT(MCUCSR , MCUCSR_ISC2);
								Local_enuErrorState = ES_OK;
								break;
							case RISING_EDGE:
								SET_BIT(MCUCSR , MCUCSR_ISC2);
								Local_enuErrorState = ES_OK;
								break;
							default:
								Local_enuErrorState = ES_OUT_OF_RANGE;
							}
							break;
							default:
								Local_enuErrorState = ES_OUT_OF_RANGE;

				}

			}

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return   Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : EXTI_enuSetSenseMode.                                 **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u8EXTI_ID , Copy_u8SenseLevel.                   **/
/** Functionality   : SET Sense Mode For EXTI                               **/
/*****************************************************************************/
/*****************************************************************************/

ES_t  EXTI_enuSetSenseMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel)

{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_u8EXTI_ID >= 0) &&(Copy_u8EXTI_ID < 3))
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:

			/*Choosing Interrupt Sense Control for INT0*/
			switch(Copy_u8SenseLevel)
			{
			case FALLING_EDGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				CLEAR_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case ANY_LOGICAL_CHANGE:
				CLEAR_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR , MCUCR_ISC01);
				CLEAR_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;

			}
			break;
			case 1:

				/*Choosing Interrupt Sense Control for INT1*/
				switch(Copy_u8SenseLevel)
				{
				case FALLING_EDGE:
					SET_BIT(MCUCR , MCUCR_ISC11);
					CLEAR_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case RISING_EDGE:
					SET_BIT(MCUCR , MCUCR_ISC11);
					SET_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case ANY_LOGICAL_CHANGE:
					CLEAR_BIT(MCUCR , MCUCR_ISC11);
					SET_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR , MCUCR_ISC11);
					CLEAR_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;

				}
				break;
				case 2:

					/*Choosing Interrupt Sense Control for INT2*/
					switch(Copy_u8SenseLevel)
					{
					case FALLING_EDGE:
						CLEAR_BIT(MCUCSR , MCUCSR_ISC2);
						Local_enuErrorState = ES_OK;
						break;
					case RISING_EDGE:
						SET_BIT(MCUCSR , MCUCSR_ISC2);
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;

					}
					break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return   Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : EXTI_enuEnableInterrupt.                              **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u8EXTI_ID.                                       **/
/** Functionality   : Disable Interrupt EXTI                                **/
/*****************************************************************************/
/*****************************************************************************/

ES_t  EXTI_enuEnableInterrupt(u8 Copy_u8EXTI_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;
	if((Copy_u8EXTI_ID >= 0) &&(Copy_u8EXTI_ID < 3))
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			/*Enable PIE For INT0*/
			SET_BIT(GICR , GICR_INT0);
			Local_enuErrorState = ES_OK;
			break;
		case 1:
			/*Enable PIE For INT1*/
			SET_BIT(GICR , GICR_INT1);
			Local_enuErrorState = ES_OK;
			break;
		case 2:
			/*Enable PIE For INT2*/
			SET_BIT(GICR , GICR_INT2);
			Local_enuErrorState = ES_OK;

			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return   Local_enuErrorState;
}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : EXTI_enuDisableInterrupt.                             **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u8EXTI_ID.                                       **/
/** Functionality   : Disable Interrupt EXTI                                **/
/*****************************************************************************/
/*****************************************************************************/

ES_t  EXTI_enuDisableInterrupt(u8 Copy_u8EXTI_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;
	if((Copy_u8EXTI_ID >= 0) &&(Copy_u8EXTI_ID < 3))
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			/*Disable PIE For INT0*/
			CLEAR_BIT(GICR , GICR_INT0);
			Local_enuErrorState = ES_OK;
			break;
		case 1:
			/*Disable PIE For INT1*/
			CLEAR_BIT(GICR , GICR_INT1);
			Local_enuErrorState = ES_OK;
			break;
		case 2:
			/*Disable PIE For INT2*/
			CLEAR_BIT(GICR , GICR_INT2);
			Local_enuErrorState = ES_OK;

			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return   Local_enuErrorState;
}

ES_t  EXTI_enuCallBack(void(*Copy_pFunAPPFun)(void) , u8  Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pFunAPPFun != NULL && Copy_u8EXTI_ID >= 0 && Copy_u8EXTI_ID < 3)
	{
		EXTI_ApFunINTFun[Copy_u8EXTI_ID] = Copy_pFunAPPFun;
		Local_enuErrorState = ES_OK;
	}

	return  Local_enuErrorState;
}


/*ISR Function For Interrupt 0*/
ISR(VECT_INT0)
{
	if(EXTI_ApFunINTFun[0] != NULL)
	{
		EXTI_ApFunINTFun[0]();
	}

}

/*ISR Function For Interrupt 1*/
ISR(VECT_INT1)
{
	if(EXTI_ApFunINTFun[1] != NULL)
	{
		EXTI_ApFunINTFun[1]();
	}
}

/*ISR Function For Interrupt 2*/
ISR(VECT_INT2)
{
	if(EXTI_ApFunINTFun[2] != NULL)
	{
		EXTI_ApFunINTFun[2]();
	}

}




