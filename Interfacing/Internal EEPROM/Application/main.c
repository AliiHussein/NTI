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
#include "MCAL/TWI/TWI_int.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"

/* MASTER */
int main(void)
{
	
	LCD_init();
	
	uint8 data_sent = 'A';
	uint8 data_rec;
	
	LCD_write_string("Sent: ");
	LCD_write_command(0xc0);
	LCD_write_string("Reci: ");
	
	while(1){
		eeprom_write(123, data_sent);
		
		LCD_write_command(0x86);
		LCD_write_char(data_sent);
		
		eeprom_read(123, &data_rec);
		
		
		LCD_write_command(0xc6);
		LCD_write_char(data_rec);
		
		data_sent++;
		
		_delay_ms(1000);
		
	}
}





