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

uint8 up_flag = 1;

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
	uint32 temp;
	
	while(1){
		temp = count;
		
		sevenseg_write(temp%10, 1);
		temp/=10;
		sevenseg_write(temp%10, 2);
		temp/=10;
		sevenseg_write(temp%10, 3);
		temp/=10;
		sevenseg_write(temp%10, 4);
		
		if(up_flag){
			count++;
		}
		else{
			count--;
		}
				
	}
    
}



