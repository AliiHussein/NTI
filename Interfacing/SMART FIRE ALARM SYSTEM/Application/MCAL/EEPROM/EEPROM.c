/*
 * EEPROM.c
 *
 * Created: 11/5/2023 9:44:40 AM
 *  Author: Ali
 */ 

#include "std_macros.h"

#include "EEPROM_CFG.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"




void eeprom_write(uint16 add, uint8 data){
	while(READBIT(EECR, EEWE) != 0); // wait until EEWE becomes zero
	EEAR = add;
	EEDR = data;
	SETBIT(EECR, EEMWE);
	SETBIT(EECR, EEWE);
}

uint8 eeprom_read(uint16 add){
	while(READBIT(EECR, EEWE) != 0); // wait until EEWE becomes zero
	EEAR = add;
	SETBIT(EECR, EERE);
	return EEDR;
}