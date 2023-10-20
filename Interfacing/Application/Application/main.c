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
	led_init(portA, 7);
	button_init(portB, 0);
	
	while(1){
		if(!button_read(portB, 0)){
			led_toggle(portA, 7);
			_delay_ms(300);
		}
	}
    
}

