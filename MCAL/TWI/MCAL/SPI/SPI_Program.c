/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    SPI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "../Interrupt.h"

#include "SPI_Interface.h"
#include "SPI_Register.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



ES_t  SPI_enuMaster_Initialize(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Select SPI Speed Mode*/
#if  SPI_SPEED_MODE  == NORMAL_SPEED_MODE

	CLEAR_BIT(SPSR , SPSR_SPI2X);
	Local_enuErrorState = ES_OK;

#elif  SPI_SPEED_MODE  == DOUBLE_SPEED_MODE

	SET_BIT(SPSR , SPSR_SPI2X);
	Local_enuErrorState = ES_OK;

#else
#error  "Speed Mode is Incorrect"
#endif

	/*Select Data Order*/
#if  SPI_DATA_ORDER  == LSB_FIRST

	SET_BIT(SPCR , SPCR_DORD);
	Local_enuErrorState = ES_OK;

#elif  SPI_DATA_ORDER  == MSB_FIRST

	CLEAR_BIT(SPCR , SPCR_DORD);
	Local_enuErrorState = ES_OK;

#else
#error "Data Order is Incorrect"
#endif

	/*Select Clock Polarity*/
#if  SPI_CLOCK_POLARITY  == LEADING_RISING_EDGE

	CLEAR_BIT(SPCR , SPCR_CPOL);
	Local_enuErrorState = ES_OK;

#elif  SPI_CLOCK_POLARITY  == LEADING_FALLING_EDGE

	SET_BIT(SPCR , SPCR_CPOL);
	Local_enuErrorState = ES_OK;

#else
#error  "Clock Polarity is Incorrect"
#endif

	/*Select Clock Phase*/
#if  SPI_CLOCK_PHASE  == LEADING_SAMPLE

	CLEAR_BIT(SPCR , SPCR_CPHA);
	Local_enuErrorState = ES_OK;

#elif  SPI_CLOCK_PHASE  == LEADING_SETUP

	SET_BIT(SPCR , SPCR_CPHA);
	Local_enuErrorState = ES_OK;

#else
#error  "Clock Phase is Incorrect"
#endif

	/*Select SPI Clock Rate*/
#if  SPI_CLOCK_RATE  == NORMAL_BY_4_DOUBLE_BY_2

	CLEAR_BIT(SPCR , SPCR_SPR0);
	CLEAR_BIT(SPCR , SPCR_SPR1);
	Local_enuErrorState  = ES_OK;

#elif  SPI_CLOCK_RATE  == NORMAL_BY_16_DOUBLE_BY_8

	SET_BIT(SPCR , SPCR_SPR0);
	CLEAR_BIT(SPCR , SPCR_SPR1);
	Local_enuErrorState  = ES_OK;

#elif  SPI_CLOCK_RATE  == NORMAL_BY_64_DOUBLE_BY_32

	CLEAR_BIT(SPCR , SPCR_SPR0);
	SET_BIT(SPCR , SPCR_SPR1);
	Local_enuErrorState  = ES_OK;

#elif  SPI_CLOCK_RATE  == NORMAL_BY_128_DOUBLE_BY_64

	SET_BIT(SPCR , SPCR_SPR0);
	SET_BIT(SPCR , SPCR_SPR1);
	Local_enuErrorState  = ES_OK;

#else
#error "Clock Rate is Incorrect"
#endif

	/*SET Master*/
	SET_BIT(SPCR , SPCR_MSTR);

	return  Local_enuErrorState;
}

ES_t  SPI_enuSlaveInitialize(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Select SPI Speed Mode*/
#if  SPI_SPEED_MODE  == NORMAL_SPEED_MODE

	CLEAR_BIT(SPSR , SPSR_SPI2X);
	Local_enuErrorState = ES_OK;

#elif  SPI_SPEED_MODE  == DOUBLE_SPEED_MODE

	SET_BIT(SPSR , SPSR_SPI2X);
	Local_enuErrorState = ES_OK;

#else
#error  "Speed Mode is Incorrect"
#endif

	/*Select Data Order*/
#if  SPI_DATA_ORDER  == LSB_FIRST

	SET_BIT(SPCR , SPCR_DORD);
	Local_enuErrorState = ES_OK;

#elif  SPI_DATA_ORDER  == MSB_FIRST

	CLEAR_BIT(SPCR , SPCR_DORD);
	Local_enuErrorState = ES_OK;

#else
#error "Data Order is Incorrect"
#endif

	/*Select Clock Polarity*/
#if  SPI_CLOCK_POLARITY  == LEADING_RISING_EDGE

	CLEAR_BIT(SPCR , SPCR_CPOL);
	Local_enuErrorState = ES_OK;

#elif  SPI_CLOCK_POLARITY  == LEADING_FALLING_EDGE

	SET_BIT(SPCR , SPCR_CPOL);
	Local_enuErrorState = ES_OK;

#else
#error  "Clock Polarity is Incorrect"
#endif

	/*Select Clock Phase*/
#if  SPI_CLOCK_PHASE  == LEADING_SAMPLE

	CLEAR_BIT(SPCR , SPCR_CPHA);
	Local_enuErrorState = ES_OK;

#elif  SPI_CLOCK_PHASE  == LEADING_SETUP

	SET_BIT(SPCR , SPCR_CPHA);
	Local_enuErrorState = ES_OK;

#else
#error  "Clock Phase is Incorrect"
#endif

	/*SET Slave*/
	CLEAR_BIT(SPCR , SPCR_MSTR);

	return  Local_enuErrorState;
}


ES_t  SPI_enuTranceive(u8 Copy_u8TransmitData , u8* Copy_pu8ReceiveData)
{
	ES_t  Local_enuErrorState    = ES_NOK;

	SPDR = Copy_u8TransmitData;

	while(GET_BIT(SPSR , SPSR_SPIF) == 0);

	if(Copy_pu8ReceiveData != NULL)
	{
		*Copy_pu8ReceiveData = SPDR;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return  Local_enuErrorState;
}

ES_t   SPI_enuSPIEnable(void)
{
	ES_t  Local_enuErrorState  = ES_NOK;

	SET_BIT(SPCR , SPCR_SPE);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

ES_t   SPI_enuSPIDisable(void)
{
	ES_t  Local_enuErrorState  = ES_NOK;

	CLEAR_BIT(SPCR , SPCR_SPE);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

