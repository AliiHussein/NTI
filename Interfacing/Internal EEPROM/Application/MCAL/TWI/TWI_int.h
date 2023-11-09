/*
 * TWI_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_






typedef enum
{
	NO_ERROR,
	START_ERROR,
	REPEATED_STSRT_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	SEND_BYTE_ERROR,
	READ_BYTE_ERROR

}TWI_ERROR_STATUS;
void M_TWI_void_Init(void);
uint8 M_TWI_u8_StartCondition(void);
void M_TWI_void_StopCondition(void);
uint8 M_TWI_u8_RepeatedStart(void);
uint8 M_TWI_u8_SendSlaveAddressWrite(uint8);
uint8 M_TWI_u8_SendSlaveAddressRead(uint8);
uint8 M_TWI_u8_SendByte(uint8);
uint8 M_TWI_u8_ReadByte(uint8 *TWI_DATA);

#endif /* TWI_TWI_INT_H_ */
