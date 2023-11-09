/*
 * EEPROM_Interface.h
 *
 * Created: 11/5/2023 9:44:54 AM
 *  Author: Ali
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void eeprom_write(uint16 add, uint8 data);
uint8 eeprom_read(uint16 add);



#endif /* EEPROM_INTERFACE_H_ */