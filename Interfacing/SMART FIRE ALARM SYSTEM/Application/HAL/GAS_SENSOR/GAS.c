/*
 * GAS.c
 *
 * Created: 11/5/2023 12:15:22 PM
 *  Author: Ali
 */ 


#include "std_macros.h"

#include "MCAL/DIO/DIO.h"

#include "GAS_CFG.h"
#include "GAS_Interface.h"
#include "GAS_CFG.h"

void gas_sensor_init(void){
	DIO_voidSetPinDirection(PORT, PIN, INPUT);
}
uint8 READ_gas_sensor(void){
	return DIO_voidGetBitValue(PORT, PIN);
}