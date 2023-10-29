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
#include "MCAL/WDT/WDT_Interface.h"



void toggle_led_yel(void){
	_delay_ms(500);
	led_on(portA, 6);
	_delay_ms(500);
	led_off(portA, 6);
	
}

void toggle_led_blue(void){
	_delay_ms(500);
	led_on(portA, 5);
	_delay_ms(500);
	led_off(portA, 5);
	
}

void toggle_led_green(void){
	_delay_ms(3000);
	led_on(portA, 4);
	_delay_ms(500);
	led_off(portA, 4);
	
}

void toggle_led_red(void){
	_delay_ms(500);
	led_on(portB, 7);
	_delay_ms(500);
	led_off(portB, 7);
	
}

int main(void)
{
	led_init(portA, 4);
	led_init(portA, 5);
	led_init(portA, 6);
	led_init(portB, 7);
	
	/*
	led_off(portA, 4);
	led_off(portA, 5);
	led_off(portA, 6);
	led_off(portB, 7);
	*/
	//_delay_ms(500);
	
		
	while (1)
	{
		wdt_enable(T2_1_s);
		toggle_led_yel();
		wdt_disable();
		
		wdt_enable(T2_1_s);
		toggle_led_blue();
		wdt_disable();
		
		
		
		wdt_enable(T2_1_s);
		toggle_led_green();
		wdt_disable();
		
		/*
		wdt_enable(T2_1_s);
		toggle_led_red();
		wdt_disable();
		*/
		
		
	}
}





