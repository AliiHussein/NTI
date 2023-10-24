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

uint16 value;

void autotrigger(void){
	uint16 volt;
	uint16 temp;
	
	ADC_AutoTrigger_init();	
	ADC_AutoTrigger_read(A1, &value);
	
	// Disable AutoTrigger
	CLRBIT(ADCSRA, ADATE);
	CLRBIT(SFIOR, ADTS2); CLRBIT(SFIOR, ADTS1); CLRBIT(SFIOR, ADTS0);
	
	volt = (value * 5000UL)/ 1024;
	temp = volt/10;
	
	LCD_write_command(0x86);
	LCD_write_string("     ");
	LCD_write_command(0x86);
	LCD_write_number(temp);
}

uint16 interpolation(uint16 Y_max,uint16 Y_min,uint16 X_max,uint16 X_min,uint16 ADC_Read)
{
	uint16 val,y,x;
	y=Y_max-Y_min;
	x=X_max-X_min;
	
	val=((y*(uint32)(ADC_Read-X_min))/x)+Y_min;
	
	return val;
}

int main(void)
{
	LCD_init();
	ADC_init();
	
	EXT_init(EXT0, FALLING);
	EXT_callback(autotrigger, EXT0);
	GIE_Enable();	
	
	LCD_write_command(0x80);
	LCD_write_string("Temp= ");
	LCD_write_command(0xc0);
	LCD_write_string("LDR= ");
	
	uint16 LDR;
	uint16 volt2;
	uint16 percentage;
	

	while(1){
		ADC_read(A0, &LDR);
		
		volt2 = (LDR * 5000UL)/ 1024;
		
		/*
		
		0    -> 100%
		4700 -> 100
		
		*/
		
		percentage = interpolation(100, 0, 100, 4700, volt2);
		
		LCD_write_command(0xc6);
		LCD_write_string("     ");
		LCD_write_command(0xc6);
		LCD_write_number(percentage);
		_delay_ms(500);
	}
	
}



