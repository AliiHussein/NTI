/*
 * Timer0.c
 *
 * Created: 10/24/2023 3:10:21 PM
 *  Author: Ali
 */ 

#include "Bit_math.h"
#include "std_types.h"
#include "std_macros.h"

#include "Timer0_CFG.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "HAL/LCD/LCD.h"

void (*ptr_t0)(void) = NULL;

void timer0_init(void){
	// reset TCNT0
	TCNT0 = 0;
	// FOC0 = 1
	//SETBIT(TCCR0, FOC0);
	// Normal Mode
	CLRBIT(TCCR0, WGM01); CLRBIT(TCCR0, WGM00);
	/* 
	Prescaler = CLK/8 =>  CS02 = 0, CS01 = 1, CS00 = 0 (Chosen)
	Prescaler = CLK/16 =>  CS02 = 0, CS01 = 1, CS00 = 1
	*/
	CLRBIT(TCCR0, CS02); SETBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00);	
	
}

void timer0_CTC_init(uint8 Value){
	// reset TCNT0
	TCNT0 = 0;
	// FOC0 = 1
	//SETBIT(TCCR0, FOC0);
	// CTC Mode
	SETBIT(TCCR0, WGM01); CLRBIT(TCCR0, WGM00);
	// OCR0 Value
	OCR0 = Value;
	/* 
	Prescaler = CLK/8 =>  CS02 = 0, CS01 = 1, CS00 = 0 (Chosen)
	Prescaler = CLK/16 =>  CS02 = 0, CS01 = 1, CS00 = 1
	*/
	CLRBIT(TCCR0, CS02); SETBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00);	
}

void timer0_callback(void (*PTR)(void)){
	ptr_t0 = PTR;
}

void timer0_int_enable(void){
	// Enable timer from TIMSK
	SETBIT(TIMSK, TOIE0);
}

void timer0_int_CTC_enable(void){
	// Enable CTC timer from TIMSK
	SETBIT(TIMSK, OCIE0);
}

void timer0_disable(void){
	CLRBIT(TCCR0, CS02); CLRBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00);	
}


void timer0_delay_us(uint32 microseconds){
	timer0_init();
	
	uint32 freq = 16000000;
	uint32 Prescaler = 8*2000000;
	uint32 TickTime = Prescaler/ freq;
	float64 TimeOVF = (TickTime * 256.0)/2000000.0; 
	float32 OVF_counts = microseconds / (TimeOVF * 1000000.0);
	
	uint32 counts = OVF_counts;
	
	LCD_write_command(0xc0);
	LCD_write_float(OVF_counts);
	
	
	for(int i = 0; i < counts;){
		while(READBIT(TIFR,TOV0) == 0);
		i++;
		SETBIT(TIFR,TOV0);
	}
	
	timer0_disable();
}
void timer0_delay_ms(uint32 milliseconds){
	timer0_init();
	
	uint32 freq = 16000000;
	uint32 Prescaler = 8*2000000;
	uint32 TickTime = Prescaler/ freq;
	float64 TimeOVF = (TickTime * 256.0)/2000000.0;
	float32 OVF_counts = milliseconds / (TimeOVF * 1000.0);
	
	uint32 counts = OVF_counts;
	
	LCD_write_command(0xc0);
	LCD_write_float(OVF_counts);
	
	
	for(int i = 0; i < counts;){
		while(READBIT(TIFR,TOV0) == 0);
		i++;
		SETBIT(TIFR,TOV0);
	}
	
	timer0_disable();
}
void timer0_delay_s(uint32 seconds){
	timer0_init();
	
	uint32 freq = 16000000;
	uint32 Prescaler = 8*2000000;
	uint32 TickTime = Prescaler/ freq;
	float64 TimeOVF = (TickTime * 256.0)/2000000.0;
	float32 OVF_counts = seconds / (TimeOVF * 1.0);
	
	uint32 counts = OVF_counts;
	
	LCD_write_command(0xc0);
	LCD_write_float(OVF_counts);
	
	
	for(int i = 0; i < counts;){
		while(READBIT(TIFR,TOV0) == 0);
		i++;
		SETBIT(TIFR,TOV0);
		
	}
	
	timer0_disable();
}

void __vector_11() __attribute__((signal));

void __vector_11(){
	ptr_t0();
}

void __vector_10() __attribute__((signal));

void __vector_10(){
	ptr_t0();
}

/*

Q: Toggle led for 1 second
1. Freq = 16Mhz
2. Tick time = Prescaler / Freq = 8 / 16Mhz = 1 / 2Mhz
3. Time ovf = Tick Time * 256 = 0.000128
4. Overflows count = RequiredTime/Time OVF =  7812.5
5. To get the decimal: 0.5 * 256 = 128 (Start TCNT0 from 128)
 
*/