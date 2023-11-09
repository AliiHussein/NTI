/*
 * EEPROM_Private.h
 *
 * Created: 11/5/2023 9:45:11 AM
 *  Author: Ali
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEARH *((volatile uint8 *)0x3F)

#define EEARL *((volatile uint8 *)0x3E)

#define EEAR EEARL

#define EEDR *((volatile uint8 *)0x3D)

#define EECR *((volatile uint8 *)0x3C)
#define EERIE 3
#define EEMWE 2
#define EEWE  1
#define EERE  0

#endif /* EEPROM_PRIVATE_H_ */