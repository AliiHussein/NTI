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
		
	DIO_voidSetPortDirection(portC, INPUT);
	LCD_write_string("REC: ");
	
	
	uint8 temp = 20;
	
	while (1)
	{
		temp = PINC;
		LCD_write_command(0x85);
		LCD_write_number(temp);
		
		
	
		
	}
}





