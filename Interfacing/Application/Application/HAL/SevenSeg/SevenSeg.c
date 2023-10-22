/*
 * SevenSeg.c
 *
 * Created: 10/21/2023 9:54:51 AM
 *  Author: Ali
 */ 

#include "SevenSeg.h"

void sevenseg_init(){
	SEVEN_SEG_INIT_PORTS();
	
}

void sevenseg_write(uint8 value, uint8 ss_num){
	
	EN1_DIS();EN2_DIS();EN3_DIS();EN4_DIS();
	
	switch(ss_num){
		case 1: EN1_EN(); break;
		case 2: EN2_EN(); break;
		case 3: EN3_EN(); break;
		case 4: EN4_EN(); break;
	}
	
	switch(value){
		case 0: CLRBIT(PORTB, 4); CLRBIT(PORTB, 2); CLRBIT(PORTB, 1); CLRBIT(PORTB, 0); break;
		case 1: CLRBIT(PORTB, 4); CLRBIT(PORTB, 2); CLRBIT(PORTB, 1); SETBIT(PORTB, 0); break;
		case 2: CLRBIT(PORTB, 4); CLRBIT(PORTB, 2); SETBIT(PORTB, 1); CLRBIT(PORTB, 0); break;
		case 3: CLRBIT(PORTB, 4); CLRBIT(PORTB, 2); SETBIT(PORTB, 1); SETBIT(PORTB, 0); break;
		case 4: CLRBIT(PORTB, 4); SETBIT(PORTB, 2); CLRBIT(PORTB, 1); CLRBIT(PORTB, 0); break;
		case 5: CLRBIT(PORTB, 4); SETBIT(PORTB, 2); CLRBIT(PORTB, 1); SETBIT(PORTB, 0); break;
		case 6: CLRBIT(PORTB, 4); SETBIT(PORTB, 2); SETBIT(PORTB, 1); CLRBIT(PORTB, 0); break;
		case 7: CLRBIT(PORTB, 4); SETBIT(PORTB, 2); SETBIT(PORTB, 1); SETBIT(PORTB, 0); break;
		case 8: SETBIT(PORTB, 4); CLRBIT(PORTB, 2); CLRBIT(PORTB, 1); CLRBIT(PORTB, 0); break;
		case 9: SETBIT(PORTB, 4); CLRBIT(PORTB, 2); CLRBIT(PORTB, 1); SETBIT(PORTB, 0); break;
	}	
	_delay_ms(1);
}

void sevenseg_write_four(uint8 value, uint8 ss_num){
	
}