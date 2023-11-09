
/*
 * I2C.c
 *
 * Created: 11/3/2023 2:32:38 PM
 *  Author: Ali
 */ 

#include "std_types.h"
#include "Bit_math.h"

#include "I2C_CFG.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

// TWCR REGISTER
// Enable ACK bit  -> TWEA
// Start condition -> TWSTA
// Stop condition  -> TWSTO
// Enable I2C      -> TWEN 

// TWSR REGISTER
// TWS 7 to 3 is the status
// TWPS0 = 0
// TWPS1 = 0

// TWDR REGISTER

// TWAR REGISTER
// Bits 7..1 – TWA: TWI (Slave) Address Register
// bit 0 -> GENREAL CALL

void I2C_MASTER_INIT(void)
{
	/*  Set prescaler 0  */
	CLRBIT(TWSR,TWPS0);
	CLRBIT(TWSR,TWPS1);
	
	TWBR = 18; // for 100K scl and 16Mhz freq uc
	
	
}
void I2C_SLAVE_INIT(uint8 slave_address)
{
	
	/*    Set Slave Address   */
	TWAR = slave_address<<1;
	
}

I2C_Error I2C_Send_Start_Condition(void)
{
	I2C_Error Local_var = I2C_ok;

	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( READBIT(TWCR,TWINT) == 0);
	
	/*  Check on ACK*/
	if((TWSR & 0xF8)!= I2C_SC_ACK)
	{
		
		Local_var = I2C_SC_Error;
	}
	else
	{
		
	}
	return Local_var;
	
}



I2C_Error I2C_Send_Repeated_Start_Condition(void)
{
	I2C_Error Local_var = I2C_ok;
		
	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( READBIT(TWCR,TWINT) == 0);
		
	
	/*  Check on ACK*/
	if((TWSR & 0xF8)!=I2C_RSC_ACK)
	{
		
		Local_var = I2C_RSC_Error;
	}
	return Local_var;
	
}
I2C_Error I2C_Send_Slave_Address_Write(uint8 slave_add)
{
	I2C_Error Local_var = I2C_ok;
	
	// for write you should put 0 on LSB
	// load slave address into data register
	TWDR = slave_add<<1; // write operation
	CLRBIT(TWDR,0);	 // write
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( READBIT(TWCR,TWINT) == 0);
	
	if((TWSR & 0xF8)!=0X18)
	{
		
		Local_var = I2C_MT_SLA_W_Error;
	}
	return Local_var;
	
}
I2C_Error I2C_Send_Slave_Address_Read(uint8 slave_add)
{
	I2C_Error Local_var = I2C_ok;
	
	// for write you should put 0 on LSB
	// load slave address into data register
	TWDR = slave_add<<1; // write operation
	SETBIT(TWDR,0);	 // read
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( READBIT(TWCR,TWINT) == 0);
	
	if((TWSR & 0xF8)!=I2C_MR_SLA_R_ACK)
	{
		
		Local_var = I2C_MR_SLA_R_Error;
	}
	return Local_var;
	
}
I2C_Error I2C_Send_Master_Send_Byte(uint8 master_data)
{
	I2C_Error Local_var = I2C_ok;
	
	TWDR = master_data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	/*      Polling on the Flag        */
	while(READBIT(TWCR,TWINT)==0) {  }
	
	if((TWSR & 0xF8)!=I2C_MT_DATA_ACK)
	{
		
		Local_var = I2C_MT_Data_Error;
	}
	return Local_var;
	
	
}
I2C_Error I2C_Send_Master_Read_Byte(uint8 *master_data_read)
{
	I2C_Error Local_var = I2C_ok;
	
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( READBIT(TWCR,TWINT) == 0);
	// return received data from TWDR
	
	
	if((TWSR & 0xF8)!=I2C_MR_DATA_ACK)
	{
		
		Local_var = I2C_MR_Data_Error;
	}
	else
	{
		*master_data_read = TWDR;
	}
	return Local_var;
	
	
}
void I2C_Send_Stop_Condition(void)
{
	
	
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

}

uint8 I2C_slave_avialable(){
	TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);
	while( READBIT(TWCR,TWINT) == 0);
	if(TWSR == 0x60) return 1;
	else return 0;
}