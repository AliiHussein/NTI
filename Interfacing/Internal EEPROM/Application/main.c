/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 


#include "std_macros.h"
#include "HAL/LCD/LCD.h"
#include "HAL/ULTRASONIC/Ultrasonic.h"


#include "MCAL/DIO/DIO.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/Timer1/TIMER1_Interface.h"



/* MASTER */
int main(void)
{
	
	LCD_init();
	Ultrasonic_init();
	
	
	timer0_init(PWM_FAST, P8, INTERUPT_OFF, NON_INVERTED);
	PWM0_OC0_duty(20, PWM_FAST, NON_INVERTED);
	
	Timer1_Init();
	
	
	
	
	LCD_write_string("Hello Nassif!");
	
	uint16 d;
	
	
	while(1){
		Ultrasonic_Read_Distance(&d);
		LCD_write_command(0xc0);
		LCD_write_number(d);
		
		//print the reading;
		_delay_ms(500);
		
	}
}





