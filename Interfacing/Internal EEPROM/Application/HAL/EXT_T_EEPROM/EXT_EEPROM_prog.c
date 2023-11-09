

#include "std_macros.h"
#include "MCAL/TWI/TWI_int.h"

#include "EXT_EEPROM_int.h"
#include "EXT_EEPROM_private.h"






void H_EXT_EEPROM_void_Init(void)
{
	M_TWI_void_Init();
}

/***************************************************************************/

void H_EXT_EEPROM_void_Write(uint16 Copy_u16ByteNo , uint8 Copy_u8Data)
{

	M_TWI_u8_StartCondition();
	M_TWI_u8_SendSlaveAddressWrite(EXT_EEPROM_ADDRESS_SEQ | (uint8)(Copy_u16ByteNo>>8) );
	M_TWI_u8_SendByte( (uint8)Copy_u16ByteNo);
	M_TWI_u8_SendByte(Copy_u8Data);
	M_TWI_void_StopCondition();

	_delay_ms(10);
}

/***************************************************************************/
uint8   H_EXT_EEPROM_void_Read(uint16 Copy_u16ByteNo)
{
	uint8 Local_u8Data = 0;

	M_TWI_u8_StartCondition();
	M_TWI_u8_SendSlaveAddressWrite(EXT_EEPROM_ADDRESS_SEQ | (uint8)(Copy_u16ByteNo>>8));
	M_TWI_u8_SendByte((uint8)Copy_u16ByteNo);
	M_TWI_u8_RepeatedStart();
	M_TWI_u8_SendSlaveAddressRead( EXT_EEPROM_ADDRESS_SEQ | (uint8)(Copy_u16ByteNo>>8));
	M_TWI_u8_ReadByte(&Local_u8Data);
	M_TWI_void_StopCondition();

	return Local_u8Data;
}
