/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    EXTI          ***************/
/**************   Version: 2.00         ***************/
/******************************************************/
/******************************************************/

#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/ERROR_STATE.h"
#include  "../../LIB/BIT_MATH.h"

#include  "EXTI_Interface.h"
#include  "EXTI_Config.h"
#include  "EXTI_Private.h"
#include  "EXTI_Register.h"

#include  "../Interrupt.h"

/*****************************************************************************/
/*                       Glopal Variables                                    */
/*****************************************************************************/

static volatile void (*EXTI_GpfunISRFun[EXTI_NUM]) (void*) = {NULL , NULL , NULL};
static volatile void (*EXTI_GpISRPara[EXTI_NUM]) = {NULL , NULL , NULL};
/*****************************************************************************/
/*                       End of Glopal Variables                             */
/*****************************************************************************/


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
		for(Local_u8Iterator = 0 ; Local_u8Iterator < EXTI_NUM ; Local_u8Iterator++)
		{
			if(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_STATE == ACTIVATED)
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
					switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_SENSE_LEVEL)
					{
					case EXTI_FALLING_EDGE:
						SET_BIT(MCUCR , MCUCR_ISC01);
						CLEAR_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case EXTI_RISING_EDGE:
						SET_BIT(MCUCR , MCUCR_ISC01);
						SET_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case EXTI_ON_CHANGE:
						CLEAR_BIT(MCUCR , MCUCR_ISC01);
						SET_BIT(MCUCR , MCUCR_ISC00);
						Local_enuErrorState = ES_OK;
						break;
					case EXTI_LOW_LEVEL:
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
						switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_SENSE_LEVEL)
						{
						case EXTI_FALLING_EDGE:
							SET_BIT(MCUCR , MCUCR_ISC11);
							CLEAR_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case EXTI_RISING_EDGE:
							SET_BIT(MCUCR , MCUCR_ISC11);
							SET_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case EXTI_ON_CHANGE:
							CLEAR_BIT(MCUCR , MCUCR_ISC11);
							SET_BIT(MCUCR , MCUCR_ISC10);
							Local_enuErrorState = ES_OK;
							break;
						case EXTI_LOW_LEVEL:
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
							switch(Copy_pstrEXTIConfig[Local_u8Iterator].EXTI_SENSE_LEVEL)
							{
							case EXTI_FALLING_EDGE:
								CLEAR_BIT(MCUCSR , MCUCSR_ISC2);
								Local_enuErrorState = ES_OK;
								break;
							case EXTI_RISING_EDGE:
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
/** Function Name   : EXTI_enuChangeSenseLevel.                             **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_u8EXTI_ID , Copy_u8SenseLevel.                   **/
/** Functionality   : SET Sense Mode For EXTI                               **/
/*****************************************************************************/
/*****************************************************************************/

ES_t  EXTI_enuChangeSenseLevel(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_u8EXTI_ID >=0) && (Copy_u8EXTI_ID < 3))
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			/*Setting Interrupt Sense Control for INT0*/
			switch(Copy_u8SenseLevel)
			{

			case EXTI_FALLING_EDGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				CLEAR_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case EXTI_ON_CHANGE:
				CLEAR_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			case EXTI_LOW_LEVEL:
				CLEAR_BIT(MCUCR , MCUCR_ISC01);
				CLEAR_BIT(MCUCR , MCUCR_ISC00);
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;

			}
			break;
			case 1:
				/*Setting Interrupt Sense Control for INT1*/
				switch(Copy_u8SenseLevel)
				{
				case EXTI_FALLING_EDGE:
					SET_BIT(MCUCR , MCUCR_ISC11);
					CLEAR_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR , MCUCR_ISC11);
					SET_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case EXTI_ON_CHANGE:
					CLEAR_BIT(MCUCR , MCUCR_ISC11);
					SET_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				case EXTI_LOW_LEVEL:
					CLEAR_BIT(MCUCR , MCUCR_ISC11);
					CLEAR_BIT(MCUCR , MCUCR_ISC10);
					Local_enuErrorState = ES_OK;
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;

				}
				break;
				case 2:
					/*Setting Interrupt Sense Control for INT2*/
					switch(Copy_u8SenseLevel)
					{
					case EXTI_FALLING_EDGE:
						CLEAR_BIT(MCUCSR , MCUCSR_ISC2);
						Local_enuErrorState = ES_OK;
						break;
					case EXTI_RISING_EDGE:
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

	return Local_enuErrorState;
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


/*************************************************************************************************************/
/*************************************************************************************************************/
/** Function Name   : EXTI_enuCallBackFunction.                                                             **/
/** Return Type     : Error_State.                                                                          **/
/** Arguments       : Copy_pfunAppFun , Copy_pFunParameter.                                                 **/
/** Functionality   : Used to call Function from upper layer                                                **/
/** this function take pointer to function(argument of this function is generic pointer & it returns void)  **/
/** & take also generic pointer                              **/
/*************************************************************************************************************/
/*************************************************************************************************************/

ES_t  EXTI_enuCallBackFunction(volatile void (*Copy_pfunAppFun) (void*) , volatile void (*Copy_PvidAppParameter) , u8  Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_pfunAppFun != NULL) && (Copy_u8EXTI_ID >= 0) && (Copy_u8EXTI_ID < EXTI_NUM))
	{
		EXTI_GpfunISRFun[Copy_u8EXTI_ID] = Copy_pfunAppFun;
		EXTI_GpISRPara[Copy_u8EXTI_ID] = Copy_PvidAppParameter;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		if(Copy_pfunAppFun == NULL)
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}

	return  Local_enuErrorState;
}

/*************************************************************************************************************/
/*                                ISR For External Interrupt Zero                                            */
/*************************************************************************************************************/
ISR(VECT_INT0)
{
	if(EXTI_GpfunISRFun[0] != NULL)
	{
		EXTI_GpfunISRFun[0]((u8*)EXTI_GpISRPara[0]);
	}
}

/*************************************************************************************************************/
/*                                ISR For External Interrupt One                                             */
/*************************************************************************************************************/
ISR(VECT_INT1)
{
	if(EXTI_GpfunISRFun[1] != NULL)
	{
		EXTI_GpfunISRFun[1]((u8*)EXTI_GpISRPara[1]);
	}
}

/*************************************************************************************************************/
/*                                ISR For External Interrupt Two                                             */
/*************************************************************************************************************/
ISR(VECT_INT2)
{
	if(EXTI_GpfunISRFun[2] != NULL)
	{
		EXTI_GpfunISRFun[2]((u8*)EXTI_GpISRPara[2]);
	}
}
