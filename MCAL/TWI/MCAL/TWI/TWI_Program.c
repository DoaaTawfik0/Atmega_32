/********************************************************/
/********************************************************/
/**************   Author: Doaa Tawfik     ***************/
/**************   Layer:  MCAL            ***************/
/**************   SWC:    TWI             ***************/
/**************   Version: 1.00           ***************/
/********************************************************/
/********************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_Register.h"
#include "TWI_Private.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"

ES_t   TWI_enuInitialize(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	u8    Local_u8TWBRValue ;

	/*Choose Mode if Master or Slave*/
#if  TWI_MODE == MASTER_MODE

	Local_u8TWBRValue = (u8)BIT_RATE(TWI_SPEED);  //calculating value of TWBR

	if((Local_u8TWBRValue >=0) && (Local_u8TWBRValue <= 255))
	{
		TWBR = Local_u8TWBRValue;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
		return  Local_enuErrorState;
	}
	/*Choose Prescaler*/
#if  TWI_PRESCALER == PRESCALER_1

	CLEAR_BIT(TWSR , TWSR_TWPS0);
	CLEAR_BIT(TWSR , TWSR_TWPS1);
	Local_enuErrorState = ES_OK;

#elif  TWI_PRESCALER == PRESCALER_4

	SET_BIT(TWSR , TWSR_TWPS0);
	CLEAR_BIT(TWSR , TWSR_TWPS1);
	Local_enuErrorState = ES_OK;

#elif  TWI_PRESCALER == PRESCALER_16

	CLEAR_BIT(TWSR , TWSR_TWPS0);
	SET_BIT(TWSR , TWSR_TWPS1);
	Local_enuErrorState = ES_OK;

#elif  TWI_PRESCALER == PRESCALER_64

	SET_BIT(TWSR , TWSR_TWPS0);
	SET_BIT(TWSR , TWSR_TWPS1);
	Local_enuErrorState = ES_OK;
#else
#error "Invalid Prescaler"
#endif

	TWAR = (TWI_NODE_ADDRESS << 1) | TWI_GENERAL_CALL ;//Set Slave Address For Master

	SET_BIT(TWCR , TWCR_TWINT);//Clear Flag

	SET_BIT(TWCR , TWCR_TWEN);//Enable TWI

	Local_enuErrorState = ES_OK;

#elif  TWI_MODE == SLAVE_MODE

	TWAR = (TWI_NODE_ADDRESS << 1) | TWI_GENERAL_CALL ;//Set Slave Address For Master

	SET_BIT(TWCR , TWCR_TWINT);//Clear Flag

	SET_BIT(TWCR , TWCR_TWEN);//Enable TWI

	Local_enuErrorState = ES_OK;



#else
#error  "Invalid TWI Mode"
#endif

	return  Local_enuErrorState;
}


ES_t   TWI_enuStartCondition(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(TWCR , TWCR_TWSTA); //Set Start Condition Bit

	SET_BIT(TWCR , TWCR_TWINT); //Clear Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0); //Wait on Flag

	/*Checking if Start Condition Was Sent & Doing Bit_Masking for First 3 bits*/
	if((TWSR & 0xF8) == START)
		Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

ES_t   TWI_enuRebeatedStartCondition(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(TWCR , TWCR_TWSTA); //Set Start Condition Bit

	SET_BIT(TWCR , TWCR_TWINT); //Clear Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0); //Wait on Flag

	/*Checking if Rebeated Start Condition Was Sent & Doing Bit_Masking for First 3 bits*/
	if((TWSR & 0xF8) == REBEATED_START)
		Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

ES_t   TWI_enuStopCondition(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(TWCR , TWCR_TWINT); //Clear Flag

	SET_BIT(TWCR , TWCR_TWSTO);//Set Stop Bit Condition

	Local_enuErrorState  = ES_OK;

	return  Local_enuErrorState;
}

ES_t   TWI_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress  , u8 Copy_u8Operation)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_u8SlaveAddress > 1) && (Copy_u8SlaveAddress < 119) && ((Copy_u8Operation == READ) || (Copy_u8Operation == WRITE)))
	{

		TWDR = ((Copy_u8SlaveAddress << 1) | Copy_u8Operation); //TWDR Is Responsible for sending any data on bus

		SET_BIT(TWCR , TWCR_TWINT); //clear flag
		while(GET_BIT(TWCR , TWCR_TWINT) == 0); //wait on flag

		if(((TWSR & 0xF8) == SLA_R_ACK_RECEIVER) && (Copy_u8Operation == READ))
			Local_enuErrorState = ES_OK;
		else if(((TWSR & 0xF8) == SLA_W_ACK_TRANSMITTER) && (Copy_u8Operation == WRITE))
			Local_enuErrorState = ES_OK;
		else
			Local_enuErrorState = ES_NOK;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return  Local_enuErrorState;
}

ES_t   TWI_enuWriteData(u8 Copy_u8Data)
{
	ES_t  Local_enuErrorState = ES_NOK;

	TWDR = Copy_u8Data; //TWDR Is Responsible for sending any data on bus

	SET_BIT(TWCR , TWCR_TWINT); //clear flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0); //wait on flag

	if(((TWSR & 0xF8) == MASTER_TRANSMITTED_DATA_ACK))
		Local_enuErrorState = ES_OK;
	else if(((TWSR & 0xF8) == SLAVE_TRANSMITTED_DATA_ACK))
		Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}


ES_t   TWI_enuReadData(u8* Copy_pu8Data)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(TWCR , TWCR_TWINT); //clear flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0); //wait on flag

	if(((TWSR & 0xF8) == MASTER_RECEIVED_DATA_ACK))
	{
		*Copy_pu8Data = TWDR; // Receive data from bus

		Local_enuErrorState = ES_OK;
	}
	else if(((TWSR & 0xF8) == SLAVE_RECEIVED_DATA_ACK))
	{
		*Copy_pu8Data = TWDR; // Receive data from bus

		Local_enuErrorState = ES_OK;
	}


	return  Local_enuErrorState;
}

ES_t   TWI_enuCheckMyAddress(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SET_BIT(TWCR , TWCR_TWEA); //Enable Acknowledge bit

	SET_BIT(TWCR , TWCR_TWINT); //clear flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0); //wait on flag

	if(((TWSR & 0xF8) == SLAVE_RECEIVE_SLA_R))
		Local_enuErrorState = ES_OK;
	else if(((TWSR & 0xF8) == SLAVE_RECEIVE_SLA_W))
		Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



