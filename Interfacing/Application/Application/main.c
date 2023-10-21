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

int main(void)
{
	sevenseg_init();
	uint16 value = 1260;
	uint16 temp;
	while(1){
		temp = value;
		sevenseg_write(temp%10, 1);
		temp /= 10;
		sevenseg_write(temp%10, 2);
		temp /= 10;
		sevenseg_write(temp%10, 3);
		temp /= 10;
		sevenseg_write(temp%10, 4);
	}
    
}

