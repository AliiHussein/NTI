/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"

#include "HAL/LCD/LCD.h"

#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"


uint8 temp_data;
uint8 gas_data;
uint8 flame_data;

void DISPLAY(void){
	LCD_write_command(0x80);
	LCD_write_string((uint8 *)"GAS: ");
	LCD_write_number(gas_data);
	LCD_write_command(0x88);
	LCD_write_string((uint8 *)"Flame: ");
	LCD_write_number(flame_data);
	LCD_write_command(0xc0);
	LCD_write_string((uint8 *)"TEMP:     ");
	LCD_write_command(0xc7);
	LCD_write_number(temp_data);
}

void DISPLAY1(void){
	LCD_write_command(0x80);
	LCD_write_string((uint8 *)"GAS: ");
	LCD_write_string("-");
	LCD_write_command(0x88);
	LCD_write_string((uint8 *)"Flame: ");
	LCD_write_string("-");
	LCD_write_command(0xc0);
	LCD_write_string((uint8 *)"TEMP:     ");
	LCD_write_command(0xc7);
	LCD_write_string("--");
}

/* SLAVE */
int main(void)
{
	
	/* INITIALIZATIONS */
	LCD_init();
	SPI_slave_init();
	
	// I2C EEPROM
	SETBIT(DDRC, 0); SETBIT(DDRC, 1);
	SETBIT(PORTC, 0); SETBIT(PORTC, 1);
	
	if(eeprom_read(19) == 'D'){
		temp_data  = eeprom_read(20);
		gas_data   = eeprom_read(21);
		flame_data = eeprom_read(22);
		
		DISPLAY();
	}
	else{
		eeprom_write(19, 'D');
		eeprom_write(20, 0);
		eeprom_write(21, 0);
		eeprom_write(22, 0);
		DISPLAY1();
		
	}
	
	

	while(1){
		SPI_recieve(&temp_data);
		SPI_recieve(&gas_data);
		SPI_recieve(&flame_data);
		
		eeprom_write(20, temp_data);
		eeprom_write(21, gas_data);
		eeprom_write(22, flame_data);
				
		DISPLAY();
		
	}
}

