/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED/LED.h"
#include "HAL/Button/Button.h"
#include "HAL/LCD/LCD.h"
#include "HAL/SevenSeg/SevenSeg.h"
#include "HAL/KEYPAD/KEYPAD.h"

#include "MCAL/DIO/DIO.h"
#include "MCAL/EXT/EXT_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

void toggle(void){
	led_toggle(portA, 6);
}

int main(void)
{	
	led_init(portA, 6);
	led_init(portA, 5);
	
	led_on(portA, 5);
	
	EXT_init(EXT1, FALLING);
	EXT_callback(toggle, EXT1);
	
	GIE_Enable();
	while(1){
	
		
	}
    
}



