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

void toggle_Yellow(void){
	led_toggle(portA, 6);
	_delay_ms(100);
}

void toggle_Blue(void){
	led_toggle(portA, 5);
	_delay_ms(100);
}

void toggle_Green(void){
	led_toggle(portA, 4);
	_delay_ms(100);
}

void toggle_RED(void){
	led_toggle(portB, 7);
	_delay_ms(100);
}

int main(void)
{	
	// Leds Initialization
	led_init(portA, 6);
	led_init(portA, 5);
	led_init(portA, 4);
	led_init(portB, 7);
		
	// EXT interrupt Initialization	
	EXT_init(EXT0, FALLING);
	EXT_init(EXT1, FALLING);
	EXT_init(EXT2, FALLING);
	EXT_callback(toggle_Blue, EXT0);
	EXT_callback(toggle_RED, EXT1);
	EXT_callback(toggle_Yellow, EXT2);
	
	// Button Init
	button_init(portD, 7);
	
	// Global Interrupt Enabled
	GIE_Enable();
	
	/*  
		Button 1 -> PD7 :: normal button
		Button 2 -> PD6 :: EXT0 -> PD2 
		Button 3->  PD5 :: EXT2 -> PB2
		Button 4 -> PD3 :: EXT1 -> PD3
	
	 */
	
	while(1){
		if(!button_read(portD, 7)){
			toggle_Green();
		}
	}
    
}



