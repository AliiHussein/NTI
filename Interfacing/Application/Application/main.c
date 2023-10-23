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

int main(void)
{	
	ADC_init();
	LCD_init();

	uint16 val;
	uint16 volt;
	uint16 temp; // 1C -> 10 mV
	
	LCD_write_command(0x80);
	LCD_write_string("ADC= ");
	LCD_write_command(0xc0);
	LCD_write_string("Temp= ");
	
	while(1){
		// Get ADC value
		ADC_read(CH1, &val);
		
		// Volt equation
		volt = (5000UL*val) / 1024;
		
		// Temp equation
		temp = volt/10;
		
		// Printing ADC value
		LCD_write_command(0x86);
		LCD_write_string("    ");
		LCD_write_command(0x86);
		LCD_write_number(val);
		
		// Printing Volt value
		LCD_write_command(0xc6);
		LCD_write_string("    ");
		LCD_write_command(0xc6);
		LCD_write_number(temp);

		_delay_ms(200);
		
	}
    
}



