/*
 * TWI.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "std_macros.h"

#include "TWI_int.h"
#include "TWI_Config.h"
#include "TWI_private.h"


/*------------------------------------------------------------------------*/
void M_TWI_void_Init(void)
{
#if   TWI_MODE   ==   TWI_MASTER_MODE
	TWBR_REG=32; // 32 for 8Mhz & 100kHz / 2 for 8Mhz & 400khz 
	CLRBIT(TWSR_REG,TWSR_TWPS0);
	CLRBIT(TWSR_REG,TWSR_TWPS1);

#elif TWI_MODE   ==   TWI_SLAVE_MODE
	/* set SLAVE_ADDRESS and if GENERAL_CALL on  */
	TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL;

#endif

	/*EN ACK*/
	SETBIT(TWCR_REG,TWCR_TWEA);
	/*EN TWI */
	SETBIT(TWCR_REG,TWCR_TWEN);
}

/*------------------------------------------------------------------------*/

uint8 M_TWI_u8_StartCondition(void)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;

	/* Start Condition */
	SETBIT(TWCR_REG,TWCR_TWSTA);

	  /* to clear the flag */
	SETBIT(TWCR_REG,TWCR_TWINT);

	while(READBIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_START_COND_ACK)
	{
		local_error=START_ERROR;
	}
	else
	{

	}



	return  local_error ;
}

/***************************************************************************/

void M_TWI_void_StopCondition(void)

{

	SETBIT(TWCR_REG,TWCR_TWSTO);
	SETBIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */




}

/***************************************************************************/

uint8 M_TWI_u8_RepeatedStart(void)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;

	/* Start Condition */
	SETBIT(TWCR_REG,TWCR_TWSTA);

	/* to clear the flag */
	SETBIT(TWCR_REG,TWCR_TWINT);

	while(READBIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_REPEATED_START_COND_ACK)
	{
		local_error=REPEATED_STSRT_ERROR;
	}
	else
	{

	}

	return  local_error ;
}

/***************************************************************************/

uint8 M_TWI_u8_SendSlaveAddressWrite(uint8 Copy_u8Address)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;

	TWDR_REG = (Copy_u8Address << 1);

	/* Clear Start condition */
	CLRBIT(TWCR_REG,TWCR_TWSTA);

	/* to clear the flag */
	SETBIT(TWCR_REG,TWCR_TWINT);

	while(READBIT(TWCR_REG,TWCR_TWINT) == 0);


	if((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_WRITE_ACK)
	{
		local_error=SLAVE_ADDRESS_WRITE_ERROR;
	}
	else
	{

	}
	return  local_error ;
}

/***************************************************************************/

uint8 M_TWI_u8_SendSlaveAddressRead(uint8 Copy_u8Address)
{

	TWI_ERROR_STATUS local_error =NO_ERROR ;
	TWDR_REG = (Copy_u8Address << 1) | 1;

	CLRBIT(TWCR_REG,TWCR_TWSTA);
	SETBIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */
		while(READBIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_READ_ACK)
	{
		local_error=SLAVE_ADDRESS_READ_ERROR;
	}
	else
	{

	}
	return  local_error ;

}

/***************************************************************************/
uint8 M_TWI_u8_SendByte(uint8 Copy_u8Data)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;
	TWDR_REG = Copy_u8Data;
	//CLR_BIT(TWCR_REG,TWCR_TWSTA);
	SETBIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */

	while(READBIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_SEND_BYTE_ACK)
	{
		local_error=SEND_BYTE_ERROR;
	}
	else
	{

	}
	return  local_error ;

}

/***************************************************************************/

uint8   M_TWI_u8_ReadByte(uint8 *TWI_DATA)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;



	SETBIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */


	while(READBIT(TWCR_REG,TWCR_TWINT) == 0);
	if((TWSR_REG & 0xF8) != TWI_READ_BYTE_ACK)
	{
		local_error=READ_BYTE_ERROR;
	}
	else
	{
		*TWI_DATA = TWDR_REG;
	}
	return  local_error ;
}

