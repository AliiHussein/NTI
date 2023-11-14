/*
 * TIMER1.c
 *
 * Created: 11/14/2023 4:20:16 PM
 *  Author: Mahmoud Nassef
 */ 

#include "std_macros.h"

#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "MCAL/DIO/DIO.h"

void Timer1_Init(void)
{
	TCCR1A = 0;
	TCNT1=0;
	TIFR = (1<<ICF1);
	TCCR1B = 0x41;  
	DIO_voidSetPinDirection(portD,6,INPUT);
}


void Timer1_ICU_Read_ONTIME(uint16* t)
{
	uint16 a,b;
	
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	
	TCCR1B = 0x01; // 0b0000 0001
	
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	
	TCCR1B = 0x41; // 0b0010 0001 
	
	*t = (b-a)/8.0; 
}
