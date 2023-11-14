/*
 * Ultrasonic.c
 *
 * Created: 11/14/2023 7:48:03 PM
 *  Author: Mahmoud Nassef
 */ 

#include "std_macros.h"

#include "Ultrasonic.h"
#include "MCAL/Timer1/TIMER1_Interface.h"
#include "MCAL/DIO/DIO.h"

void Ultrasonic_init(void)
{
	Timer1_Init();
	DIO_voidSetPinDirection(portA,5,OUTPUT);
}

void Ultrasonic_Read_Distance(uint16 *d)
{
	DIO_voidSetPinValue(portA,5,HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(portA,5,LOW);
	uint16 t;
	Timer1_ICU_Read_ONTIME(&t);
	*d = 17000 * t;
}