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
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
uint16 C=200;
void toggle_led(void){
	static uint16 counts = 0;
	
	
	if(counts == 7812){
		
		led_toggle(portA, 5);
		counts = 0;
	}
	counts++;
	C=counts;
	
}

int main(void)
{
	// Init led
	LCD_init();
	led_init(portA, 5);
	
	// Disable GIE
	GIE_Disable();
	
	// Timer0 init
	timer0_init();
	timer0_callback(toggle_led);
	enable_timer0_int();
	
	// Global Interrupt
	GIE_Enable();
	
	LCD_write_string("Hello Nassif!");
	
	while (1)
	{
		LCD_write_command(0xc0);
		LCD_write_number(C);
	}
}



