/*
 * I2C_Private.h
 *
 * Created: 11/3/2023 2:33:00 PM
 *  Author: Ali
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWBR *((volatile uint8 *)0x20)

#define TWCR *((volatile uint8 *)0x56)
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

#define TWSR *((volatile uint8 *)0x21)
#define TWS7  7
#define TWS6  6
#define TWS5  5
#define TWS4  4
#define TWS3  3
#define TWPS1 1
#define TWPS0 0

#define TWDR *((volatile uint8 *)0x23)

#define TWAR *((volatile uint8 *)0x22)
#define TWA6  7
#define TWA5  6
#define TWA4  5
#define TWA3  4
#define TWA2  3
#define TWA1  2
#define TWA0  1
#define TWGCE 0

/*Macros for Checking(Master Transmit)*/
#define I2C_SC_ACK            0x08
#define I2C_RSC_ACK           0x10
#define I2C_MT_SLA_W_ACK      0x18
#define I2C_MT_DATA_ACK       0x28


/*Macros for Checking(Master Receive)*/
#define I2C_MR_SLA_R_ACK        0x40
#define I2C_MR_DATA_ACK  0x80


#endif /* I2C_PRIVATE_H_ */