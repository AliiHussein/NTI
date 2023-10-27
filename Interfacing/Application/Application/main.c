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

int main(void)
{
	// Init led
	LCD_init();
	led_init(portA, 5);
	
	LCD_write_string("Hello Nassif!");
	
	// Timer0 init
	
	
	while(1){
		led_on(portA, 5);
		timer0_delay_us(1000000);
		led_off(portA, 5);
		timer0_delay_us(1000000);
		
		led_on(portA, 5);
		timer0_delay_ms(1000);
		led_off(portA, 5);
		timer0_delay_ms(1000);
		
		led_on(portA, 5);
		timer0_delay_us(1);
		led_off(portA, 5);
		timer0_delay_us(1);
		
	}
	
	
}



