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

// Global Variable
uint8 up_flag = 1;

// Call Back function
void reverse_count(void){
	if(up_flag == 1){
		up_flag = 0;
	}
	else{
		up_flag = 1;
	}
}

int main(void)
{	
	
	// 7 Segment Initialization
	sevenseg_init();
	
	// EXT interrupt Initialization	
	EXT_init(EXT1, FALLING);
	EXT_callback(reverse_count, EXT1);

	// Global Interrupt Enabled
	GIE_Enable();
	
	uint32 count = 0;
	
	while(1){
		
		for(uint32 i = 0; i < 100; i++)
		{
			sevenseg_write_four(count);
			_delay_ms(1);
		}
		
		
		if(up_flag){
			count++;
		}
		else{
			count--;
		}
		
				
	}
    
}



