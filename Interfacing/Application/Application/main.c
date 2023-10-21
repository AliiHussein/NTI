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

int main(void)
{
	LCD_init();
	LCD_write_command(0x80);
	LCD_write_string("Naseef Mohamed");
	
	while(1){
		
	}
    
}

