/*
 * H_Bridge.c
 *
 * Created: 11/5/2023 9:56:10 AM
 *  Author: Mahmoud Nassef
 */ 

#include "std_macros.h"

#include "MCAL/DIO/DIO.h"
#include "H-Bridge.h"
#include "MCAL/Timer0/Timer0_Interface.h"

void Motor_Init(void)
{
	DIO_voidSetPinDirection(portB,PWM,OUTPUT);
	DIO_voidSetPinDirection(portB,DIR,OUTPUT);
	DIO_voidSetPinDirection(portB,ENABLE,OUTPUT);
	timer0_init(PWM_FAST, P8, INTERUPT_OFF, NON_INVERTED);
}

 
void Rotate_Forward(float32 pwm)
{
	DIO_voidSetPinValue(portB,ENABLE,HIGH);
	DIO_voidSetPinValue(portB,DIR,HIGH);
	PWM0_OC0_duty(pwm, PWM_FAST, NON_INVERTED);
}

void Rotate_Backward(float32 pwm)
{
	DIO_voidSetPinValue(portB,ENABLE,HIGH);
	DIO_voidSetPinValue(portB,DIR,LOW);
	PWM0_OC0_duty(pwm, PWM_FAST, NON_INVERTED);
}

void Motor_Stop(void)
{
	DIO_voidSetPinValue(portB,ENABLE,LOW);
	DIO_voidSetPinValue(portB,PWM,LOW);
	PWM0_OC0_duty(0, PWM_FAST, NON_INVERTED);
}