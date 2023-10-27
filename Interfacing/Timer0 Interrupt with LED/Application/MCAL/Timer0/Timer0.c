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

// Prescaler = 8, 64
// Toggle led for 1 second
void (*ptr_t0)(void) = NULL;

void timer0_init(void){
	// reset TCNT0
	//TCNT0 = 0;
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

void timer0_callback(void (*PTR)(void)){
	ptr_t0 = PTR;
}

void enable_timer0_int(void){
	// Enable timer from TIMSK
	SETBIT(TIMSK, TOIE0);
}
void __vector_11() __attribute__((signal));

void __vector_11(){
	ptr_t0();
}

/*
Toggle led for 1 second
Freq = 16Mhz
Tick time = Prescaler / Freq = 8 / 16Mhz = 1 / 2Mhz
Time ovf = Tick Time * 256 = 0.000128
Overflows count = 7812.5
0.5 * 256 = 128 (Start TCNT0 from 128)
 
*/