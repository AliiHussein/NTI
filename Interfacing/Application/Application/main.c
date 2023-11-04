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
#include "MCAL/I2C/I2C_Interface.h"

/* MASTER */
int main(void)
{
	
	LCD_init();
	//LCD_write_string("I2C Master");
	LCD_write_string("HELP!");
	
	I2C_MASTER_INIT();
	
	uint8 count = 0;
	
	LCD_write_command(0xc0);
	LCD_write_string("Sent: ");
	
	
	while(1){
		I2C_Send_Start_Condition();
		I2C_Send_Slave_Address_Write(0x02);
		I2C_Send_Master_Send_Byte(count);
		I2C_Send_Stop_Condition();
		
		LCD_write_command(0xc7);
		LCD_write_number(count);
		
		count++;
		
		_delay_ms(1000);
		
	}
}





