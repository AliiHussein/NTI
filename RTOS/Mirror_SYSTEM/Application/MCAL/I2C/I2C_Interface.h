/*
 * I2C_Interface.h
 *
 * Created: 11/3/2023 2:33:11 PM
 *  Author: Ali
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum {
	I2C_ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_MT_SLA_W_Error,
	I2C_MR_SLA_R_Error,
	I2C_MT_Data_Error,
	I2C_MR_Data_Error,

}I2C_Error;


void I2C_MASTER_INIT(void);
void I2C_SLAVE_INIT(uint8 slave_address);

I2C_Error I2C_Send_Start_Condition(void);
I2C_Error I2C_Send_Repeated_Start_Condition(void);
I2C_Error I2C_Send_Slave_Address_Write(uint8 slave_add);
I2C_Error I2C_Send_Slave_Address_Read(uint8 slave_add);
I2C_Error I2C_Send_Master_Send_Byte(uint8 master_data);
I2C_Error I2C_Send_Master_Read_Byte(uint8 *master_data_read);
void      I2C_Send_Stop_Condition(void);

uint8 I2C_slave_avialable(void);

#endif /* I2C_INTERFACE_H_ */