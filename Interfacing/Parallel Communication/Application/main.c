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
	
	LCD_init();	
	DIO_voidSetPortDirection(portC, OUTPUT);	
	button_init(portD, 7);
	
	uint8 count = 0;
	PORTC = count;
		
	LCD_write_string("SEND: ");
	
	while (1)
	{	
		LCD_write_command(0x86);
		LCD_write_number(PORTC);
		if(button_read(portD, 7) == 0){
			count++;
			_delay_ms(200);
		}
		PORTC = count;
	
		
	}
}





