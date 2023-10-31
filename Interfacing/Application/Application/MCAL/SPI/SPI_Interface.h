/*
 * SPI_Interface.h
 *
 * Created: 10/31/2023 2:39:08 PM
 *  Author: Ali
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_init(void);
void SPI_send(uint8 value);
void SPI_recieve(uint8 * value);

#endif /* SPI_INTERFACE_H_ */