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
	button_init(portD, 7);
	led_init(portA, 5);
	
	uint8 duty = 0;
	
	GIE_Disable();
	PWM0_OC0_duty(duty, PWM_FAST, INVERTED);
	timer0_init(PWM_PC, P8, INTERUPT_OFF, INVERTED);
	GIE_Enable();
	
	LCD_write_command(0x80);
	LCD_write_string("Duty= ");
	LCD_write_command(0x86);
	LCD_write_number(duty);
	LCD_write_command(0x89);
	LCD_write_string("%");
		
	while (1)
	{
		if(!button_read(portD, 7)){
			duty += 10;
			if(duty == 110){
				duty = 0;
				LCD_write_command(0x86);
				LCD_write_string("   ");
			}
			PWM0_OC0_duty(duty, PWM_FAST, INVERTED);
			LCD_write_command(0x86);
			LCD_write_number(duty);
			_delay_ms(300);
		}
		
	}
}

/*

PWM calculations

f = 100 KHz
T = 1/ 100k = 10 usecond

@ 50%
Ton = 5 usecond, toff = 5 usecond

@ 25%
Ton = 2.5 usecond, toff = 7.5 usecond

@ 70 %
Ton = 7 usecond, toff = 3 usecond

***************************************

Microcontroller timer
Freq = 16 MHz
Tick Time = Prescaler / Freq = 8 / 16MHz = 0.5 usecond
Time OVF = 0.5 * 256 = 128 usecond

@ 50%
On overflow counts = 5 / 0.5 = 10 counts, off = 10 counts

@ 25%
on = 5 counts, off = 15 counts

@ 70%
on = 14 counts, off = 6 counts

**************************************
Pot

20 count total

on = duty * total count = 255 - 0.25 * 20 = 255 - 5 = 250
off = 255 - (20 - on) = 240




*/





