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

void timer0_init(uint8 mode, uint8 prescaler, uint8 iSInterrupt, uint8 Compare_mode){
	// reset TCNT0
	TCNT0 = 0;
	// Select Mode
	switch(mode){
		case NORMAL:   CLRBIT(TCCR0, WGM01); CLRBIT(TCCR0, WGM00); break;
		case PWM_PC:   CLRBIT(TCCR0, WGM01); SETBIT(TCCR0, WGM00); break;
		case CTC:      SETBIT(TCCR0, WGM01); CLRBIT(TCCR0, WGM00); break;
		case PWM_FAST: SETBIT(TCCR0, WGM01); SETBIT(TCCR0, WGM00); break;
	}
	// Choose Inverted or Non-inverted
	if(mode == PWM_FAST || mode == PWM_PC){
		SETBIT(DDRB,3);    // OC0 output
		switch(Compare_mode){
			case NON_INVERTED: SETBIT(TCCR0, COM01); CLRBIT(TCCR0, COM00); break;
			case INVERTED:     SETBIT(TCCR0, COM01); SETBIT(TCCR0, COM00); break;
		}
	}
	
	// Select Prescaler
	switch(prescaler){
		case P1:    CLRBIT(TCCR0, CS02); CLRBIT(TCCR0, CS01); SETBIT(TCCR0, CS00); break;
		case P8:    CLRBIT(TCCR0, CS02); SETBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00); break;
		case P64:   CLRBIT(TCCR0, CS02); SETBIT(TCCR0, CS01); SETBIT(TCCR0, CS00); break;
		case P256:  SETBIT(TCCR0, CS02); CLRBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00); break;
		case P1024: SETBIT(TCCR0, CS02); CLRBIT(TCCR0, CS01); SETBIT(TCCR0, CS00); break;
	}
	
	// Enable Interrupt
	if(iSInterrupt == INTERUPT_ON){
		switch(mode){
			case NORMAL: SETBIT(TIMSK, TOIE0); break;
			case CTC:    SETBIT(TIMSK, OCIE0); break;
		}
		
	}	
	
}

void PWM0_OC0_duty(uint8 duty_cycle){
	if(duty_cycle > 100){
		duty_cycle = 100;
	}
	
	if(duty_cycle < 0){
		duty_cycle = 0;
	}
	
	OCR0 = duty_cycle * 2.55;
}

void timer0_setOCR(uint8 Value){
	// OCR0 Value
	OCR0 = Value;	
}

void timer0_setTCNT0(uint8 Value){
	// OCR0 Value
	TCNT0 = Value;
}

void timer0_callback(void (*PTR)(void)){
	ptr_t0 = PTR;
}

void timer0_disable(void){
	CLRBIT(TCCR0, CS02); CLRBIT(TCCR0, CS01); CLRBIT(TCCR0, CS00);	
}


void timer0_delay_us(uint32 microseconds){
	timer0_init(NORMAL, P8, INTERUPT_OFF, COMPARE_MODE_OFF);
	
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
	timer0_init(NORMAL, P8, INTERUPT_OFF, COMPARE_MODE_OFF);
	
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
	timer0_init(NORMAL, P8, INTERUPT_OFF, COMPARE_MODE_OFF);
	
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