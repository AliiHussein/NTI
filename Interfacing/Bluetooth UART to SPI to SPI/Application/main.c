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
#include "MCAL/SPI/SPI_Interface.h"

/* MASTER */
int main(void)
{
	
	LCD_init();
	Uart_init();
	LCD_write_string("REC : ");
	LCD_write_command(0xc0);
	LCD_write_string("SENT: ");
	
	SPI_master_init();
	
	// leds init
	led_init(portA, 6);
	led_init(portA, 5);
	led_init(portA, 4);
	led_init(portC, 6);

	uint8 data = 0;
	while (1)
	{
			Uart_Receive(&data);
			LCD_write_command(0x86);
			LCD_write_string("    ");
			LCD_write_command(0x86);
			LCD_write_number(data);
			
			switch(data){
				case 'A':  break;
				case 'B': led_toggle(portA, 6); break;
				case 'C': led_toggle(portA, 5); break;
				case 'D': led_toggle(portA, 4); break;
				case '1': led_toggle(portC, 6); break;
			}
		
			SPI_send(data);
			
			
			
			LCD_write_command(0xc6);
			LCD_write_string("   ");
			LCD_write_command(0xc6);
			LCD_write_number(data);
			
			
			_delay_ms(1000);
		
		
		
		
	}
}





