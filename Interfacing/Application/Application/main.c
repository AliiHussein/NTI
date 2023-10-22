/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 

#include "std_macros.h"
#include "HAL/LED/LED.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/Button/Button.h"
#include "HAL/LCD/LCD.h"
#include "HAL/SevenSeg/SevenSeg.h"
#include "HAL/KEYPAD/KEYPAD.h"

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

