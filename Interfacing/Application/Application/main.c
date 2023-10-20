/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED.h"
#include "MCAL/DIO.h"
#include "HAL/Button.h"

int main(void)
{
	led_init(portA, 6);
	button_init(portD, 7);
	DIO_voidSetPinDirection(portC, 5, OUTPUT);
	DIO_voidSetPinValue(portC, 5, LOW);
	seven_seg_init();
	seven_seg_write(2, 1);
	while(1){
		if(!button_read(portD, 7)){
			led_toggle(portA, 6);
			_delay_ms(300);
		}
		
	}
    
}

