/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "DIO.h"

int main(void)
{
	DIO_voidSetPinDirection(portA, 2, OUTPUT);
	DIO_voidSetPortDirection(portB, OUTPUT);
	DIO_voidSetPortValue(portB, HIGH);
	
	DIO_voidSetPortDirection(portC, OUTPUT);
	DIO_voidSetPortValue(portC, LOW);
	while(1){
		
		DIO_voidSetPinValue(portA, 2, HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(portA, 2, LOW);
		_delay_ms(1000);
	}
    
}

