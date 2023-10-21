/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED.h"
#include "MCAL/DIO.h"
#include "HAL/Button.h"
#include "HAL/LCD.h"
#include "HAL/SevenSeg.h"
#include "HAL/KEYPAD.h"

uint8 get_input_from_user(void);

int main(void)
{
	LCD_init();
	KEYPAD_init();
	LCD_write_command(0x80);
	
	
	while(1){
		get_input_from_user();
		_delay_ms(100);
		
	}
    
}

uint8 get_input_from_user(){
	int8 key;
	
	do{
		key = KEYPAD_read();
	}while(key == -1);
	
	LCD_write_char(key);
	_delay_ms(70);
		
	return key;
}

