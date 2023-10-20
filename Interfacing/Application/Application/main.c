/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED.h"
#include "MCAL/DIO.h"

int main(void)
{
	led_init(portA, 7);
	while(1){
		
		led_toggle(portA, 7);
		_delay_ms(1000);
	}
    
}

