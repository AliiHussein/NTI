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
#include "MCAL/UART/UART_Interface.h"

int main(void)
{
	
	Uart_init();
	LCD_init();
	ADC_init();
	
	uint8 data;
	uint16 value;
	uint16 volt;
	uint16 temp;
	
	LCD_write_command(0x80);
	LCD_write_string("Temp sent= ");
	LCD_write_command(0xc0);
	LCD_write_string("LDR Rec= ");
	
	while (1)
	{
	// Get ADC value
	ADC_read(A1, &value);
	
	// Volt equation
	volt = (5000UL*value) / 1024;
	
	// Temp equation
	temp = volt/10;
	
	Uart_Transmit(temp);
	Uart_Receive(&data);
	
	// Printing ADC value
	LCD_write_command(0x8b);
	LCD_write_string("    ");
	LCD_write_command(0x8b);
	LCD_write_number(temp);
	
	// Printing Volt value
	LCD_write_command(0xc9);
	LCD_write_string("    ");
	LCD_write_command(0xc9);
	LCD_write_number(data);
	
	

	_delay_ms(200);	
		
		
	}
}





