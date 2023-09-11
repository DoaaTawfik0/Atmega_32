/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "../Interrupt.h"

#include "Timer0_Register.h"
#include "Timer0_Interface.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"


static u32 TIMER0_u32NumOVF = 0;
static u32 TIMER0_u32Preload = 0;

volatile static void (* TIMER0_pfunISRFun)(void*) = NULL;
volatile static void * TIMER0_pvidISRParameter = NULL;

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuInitialize.                                   **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : void.                                                   **/
/** Functionality   : Setting MODE of Operation , Clock Source & OC0 Pin Mode **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuInitialize(void)
{
	ES_t   Local_enuErrorState = ES_NOK;

	/*Mode Select*/
#if  MODE_OF_OPERATION == NORMAL_MODE
	//Choose Normal Mode
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == TOGGLE_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == SET_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == PWM_PHASE_CORRECT_MODE
	//Choose Phase Correct PWM Mode
	SET_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == PHASE_PWM_CLEAR_UP_SET_DOWN    /*clear oc0 up_counting ,, set oc0 down_counting*/

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);


#elif  OC0_MODE == PHASE_PWM_SET_UP_CLEAR_DOWN     /*set oc0 up_counting ,, clear oc0 down_counting*/

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == CTC_MODE
	//Choose CTC Mode
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == TOGGLE_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == SET_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == FAST_PWM_MODE
	//Choose Fast PWM Mode
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == FAST_PWM_CLEAR_CTC_SET_TOP

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == FAST_PWM_SET_CTC_CLEAR_TOP

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#else
#error "Mode of Operation is Incorrect"

#endif

	/*Clock Select*/
#if  CLOCK_SOURCE == NO_CLOCK_SOURCE

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == NO_PRESCALER

	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;



#elif  CLOCK_SOURCE == PRESCALER_8

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_64

	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_256

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_1024

	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == EXTERNAL_T0PIN_FALLING_EDGE

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == EXTERNAL_T0PIN_RISING_EDGE

	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#else
#error "Clock Source is Incorrect"

#endif


	return  Local_enuErrorState;

}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuSetPreload.                                   **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u8Preload.                                         **/
/** Functionality   : Setting TCNT0 Register to Preload Value                 **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t   Local_enuErrorState = ES_NOK;

	TCNT0 = Copy_u8Preload;
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuSetCTC.                                       **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u8OCR0Value.                                       **/
/** Functionality   : Setting OCR0 Register to CTC Value                      **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuSetCTC(u8 Copy_u8OCR0Value)
{
	ES_t   Local_enuErrorState = ES_NOK;

	OCR0 = Copy_u8OCR0Value;
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuSynchDelay_ms.                                **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u32DelayTime.                                      **/
/** Functionality   : Implementing delay in timer using Polling System        **/
/**                   Work in Normal Mode                                     **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuSynchDelay_ms(u32 Copy_u32DelayTime)
{
	ES_t   Local_enuErrorState = ES_NOK;

	CLEAR_BIT(TIMSK , TIMSK_TOIE0);//Close Interrupt

	f32    Local_f32OverFlowTime = (((f32)TIMER_PRESCALER/TIMER_F_CPU)*256) ;//calculate OverFlow Time

	f32 Local_f32NumOVF = Copy_u32DelayTime/Local_f32OverFlowTime;

	if((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF+1;//increment number of overflow with one to reach nearest integer number

		Local_f32NumOVF = Local_f32NumOVF - (u32)Local_f32NumOVF;//calculate fraction in number of overflow
		u8 Local_u8Preload = 256*(1-Local_f32NumOVF);//calculate preload

		TCNT0 = Local_u8Preload;//**************
		while(Local_u32NumOVF > 0)
		{
			while(GET_BIT(TIFR , TIFR_TOV0) == 0);//wait on flag
			SET_BIT(TIFR , TIFR_TOV0);//clearing flag by writing logical one
			Local_u32NumOVF--;
		}
	}
	else
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF;
		while(Local_u32NumOVF > 0)
		{
			while(GET_BIT(TIFR , TIFR_TOV0) == 0);//wait on flag
			SET_BIT(TIFR , TIFR_TOV0);//clearing flag by writing logical one
			Local_u32NumOVF--;
		}

	}

	Local_enuErrorState = ES_OK;
	return  Local_enuErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuASynchDelay_ms.                               **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u32DelayTime,Copy_pfunAppFun,Copy_pvidAppParameter **/
/** Functionality   : Implementing delay in timer using Interrupt System      **/
/**                   Work in Normal Mode & CTC Mode                          **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuASynchDelay_ms(u32 Copy_u32DelayTime ,volatile void(*Copy_pfunAppFun)(void*) , void* Copy_pvidAppParameter)//Interrupt ISR
{
	ES_t   Local_enuErrorState = ES_NOK;

#if MODE_OF_OPERATION == NORMAL_MODE
	f32    Local_f32OverFlowTime = (((f32)TIMER_PRESCALER/TIMER_F_CPU)*256) ;//calculate OverFlow Time

	f32 Local_f32NumOVF = Copy_u32DelayTime/Local_f32OverFlowTime;

	if((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF+1;//increment number of overflow with one to reach nearest integer number
		Local_f32NumOVF = Local_f32NumOVF - (u32)Local_f32NumOVF;//calculate fraction in number of overflow
		u8 Local_u8Preload = 256*(1-Local_f32NumOVF);//calculate preload

		TIMER0_u32NumOVF = Local_u32NumOVF;
		TIMER0_u32Preload = Local_u8Preload;
		TCNT0 = TIMER0_u32Preload;
	}
	else
	{
		TIMER0_u32NumOVF = (u32)Local_f32NumOVF;
	}
	Local_enuErrorState = ES_OK;

	if(Copy_pfunAppFun != NULL)
	{
		TIMER0_pfunISRFun = Copy_pfunAppFun;
		TIMER0_pvidISRParameter = Copy_pvidAppParameter;
		SET_BIT(TIMSK , TIMSK_TOIE0);//Overflow interrupt enable

		TCNT0 = TIMER0_u32Preload;//initialize TCNT0 With Preload Value

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

#elif  MODE_OF_OPERATION == CTC_MODE


	if(Copy_pfunAppFun != NULL)
	{
		TIMER0_pfunISRFun = Copy_pfunAppFun;
		TIMER0_pvidISRParameter = Copy_pvidAppParameter;
		SET_BIT(TIMSK , TIMSK_OCIE0);//output compare interrupt enable

		TIMER0_enuSetCTC(OCR0_VALUE);//initialize OCR0 With CTC Value

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


#else

#endif

	return  Local_enuErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuGeneratePWM.                                  **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u8DutyCycle.                                       **/
/** Functionality   : Generating PWM Signal & Work in 2 Modes:                **/
/**                   1-Fast PWM    2-Phase Correct PWM                       **/
/**                                                                           **/
/**  This function will take value from 0 to 255 as a parameter               **/
/**  and will do some calculations to calculate OCR0 Value                    **/
/**                                                                           **/
/**                                                                           **/
/*******************************************************************************/
/*******************************************************************************/

ES_t TIMER0_enuGeneratePWM(u8  Copy_u8DutyCycle)
{

	ES_t  Local_enuErrorState  = ES_NOK;

#if   MODE_OF_OPERATION == FAST_PWM_MODE

#if   OC0_MODE == FAST_PWM_CLEAR_CTC_SET_TOP

	f32  Local_f32PeriodTime = OVF_COUNTS*((f32)TIMER_PRESCALER/TIMER_F_CPU);//Period Time Equal OVF Time
	f32  Local_f32DutyCycleAsPercentage = ((f32)Copy_u8DutyCycle/255);
	f32  Local_f32CompareMatchTime  = Local_f32PeriodTime*Local_f32DutyCycleAsPercentage;
	u8   Local_u8OCR0Value =  (u8)((OVF_COUNTS*Local_f32CompareMatchTime)/Local_f32PeriodTime);

	TIMER0_enuSetCTC(Local_u8OCR0Value);

#elif  OC0_MODE == FAST_PWM_SET_CTC_CLEAR_TOP

	f32  Local_f32PeriodTime = OVF_COUNTS*((f32)TIMER_PRESCALER/TIMER_F_CPU);//Period Time Equal OVF Time
	f32  Local_f32DutyCycleAsPercentage = ((f32)Copy_u8DutyCycle/255);
	f32  Local_f32CompareMatchTime  = Local_f32PeriodTime*(1-Local_f32DutyCycleAsPercentage);
	u8   Local_u8OCR0Value = (u8)((OVF_COUNTS*Local_f32CompareMatchTime)/Local_f32PeriodTime);

	TIMER0_enuSetCTC(Local_u8OCR0Value);
	Local_enuErrorState = ES_OK;


#else
#endif

#elif   MODE_OF_OPERATION == PWM_PHASE_CORRECT_MODE

#if   OC0_MODE == PHASE_PWM_CLEAR_UP_SET_DOWN
	//*******
	f32  Local_f32PeriodTime = OVF_COUNTS*((f32)TIMER_PRESCALER/TIMER_F_CPU);//Period Time Equal Two of OVF Time
	f32  Local_f32DutyCycleAsPercentage = ((f32)Copy_u8DutyCycle/255);
	f32  Local_f32CompareMatchTime  = Local_f32PeriodTime*Local_f32DutyCycleAsPercentage;
	u8   Local_u8OCR0Value = (u8)((OVF_COUNTS*Local_f32CompareMatchTime)/(Local_f32PeriodTime/2));

	TIMER0_enuSetCTC(Local_u8OCR0Value);
	Local_enuErrorState = ES_OK;

#elif  OC0_MODE == PHASE_PWM_SET_UP_CLEAR_DOWN

	f32  Local_f32PeriodTime = OVF_COUNTS*((f32)TIMER_PRESCALER/TIMER_F_CPU);//Period Time Equal Two of OVF Time
	f32  Local_f32DutyCycleAsPercentage = ((f32)Copy_u8DutyCycle/255);
	f32  Local_f32CompareMatchTime  = Local_f32PeriodTime*(1-Local_f32DutyCycleAsPercentage);
	u8   Local_u8OCR0Value = (u8)((OVF_COUNTS*Local_f32CompareMatchTime)/(Local_f32PeriodTime/2));

	TIMER0_enuSetCTC(Local_u8OCR0Value);
	Local_enuErrorState = ES_OK;


#else
#endif

#else
#error  "Mode Of Operation is Incorrect"


#endif

	return   Local_enuErrorState;
}



/*
 *ISR for Timer OverFlow
 */
ISR(VECT_TIMER0_OVF)
{

	if(TIMER0_pfunISRFun != NULL)
	{
		static u32 Local_u32Counter = 0;
		Local_u32Counter++;
		if(Local_u32Counter == TIMER0_u32NumOVF)
		{
			TCNT0 = TIMER0_u32Preload;
			TIMER0_pfunISRFun(TIMER0_pvidISRParameter);
			Local_u32Counter = 0;
		}
	}
}

/*
 *ISR for Timer Compare Match
 */
ISR(VECT_TIMER0_COMP)
{

	if(TIMER0_pfunISRFun != NULL)
	{
		static u32 Local_u32Counter = 0;

		if(Local_u32Counter == SW_COUNTER)
		{
			TIMER0_pfunISRFun(TIMER0_pvidISRParameter);
			Local_u32Counter = 0;
		}
		Local_u32Counter++;
	}
}

