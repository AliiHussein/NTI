/*
 * WDT.c
 *
 * Created: 10/29/2023 10:11:42 AM
 *  Author: Ali
 */ 

#include "std_macros.h"

#include "WDT_CFG.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"

void wdt_enable(uint8 Time){
	// WDT PRescaler = 1sec
	switch(Time){
		case T16_3_ms: CLRBIT(WDTCR, WDP2); CLRBIT(WDTCR, WDP1); CLRBIT(WDTCR, WDP0); break;
		case T32_5ms:  CLRBIT(WDTCR, WDP2); CLRBIT(WDTCR, WDP1); SETBIT(WDTCR, WDP0); break;
		case T65_ms:   CLRBIT(WDTCR, WDP2); SETBIT(WDTCR, WDP1); CLRBIT(WDTCR, WDP0); break;
		case T0_13_s:  CLRBIT(WDTCR, WDP2); SETBIT(WDTCR, WDP1); SETBIT(WDTCR, WDP0); break;
		case T0_26_s:  SETBIT(WDTCR, WDP2); CLRBIT(WDTCR, WDP1); CLRBIT(WDTCR, WDP0); break;
		case T0_52_s:  SETBIT(WDTCR, WDP2); CLRBIT(WDTCR, WDP1); SETBIT(WDTCR, WDP0); break;
		case T1_s:     SETBIT(WDTCR, WDP2); SETBIT(WDTCR, WDP1); CLRBIT(WDTCR, WDP0); break;
		case T2_1_s:   SETBIT(WDTCR, WDP2); SETBIT(WDTCR, WDP1); SETBIT(WDTCR, WDP0); break;
	}
	
	// Enable WDT
	SETBIT(WDTCR, WDE);
}
void wdt_disable(void){
	// Writing logic one to WDTOE & WDE at the same time
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	// Writing zero to WDE
	WDTCR = 0;
}