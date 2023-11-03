/*
 * KEYPAD_cfg.h
 *
 * Created: 3/7/2023 3:13:46 PM
 *  Author: Ali
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "std_macros.h"

#define INIT_KEYPAD_PINS() SETBIT(DDRC, 5); SETBIT(DDRC, 4); SETBIT(DDRC, 3); SETBIT(DDRC, 2); CLRBIT(DDRD, 7); CLRBIT(DDRD, 6); CLRBIT(DDRD, 5); CLRBIT(DDRD, 3)

#define COL1() READBIT(PIND, 7)
#define COL2() READBIT(PIND, 6)
#define COL3() READBIT(PIND, 5)
#define COL4() READBIT(PIND, 3)
#define ROW1(x) if(x == 1) SETBIT(PORTC, 5); else CLRBIT(PORTC, 5)
#define ROW2(x) if(x == 1) SETBIT(PORTC, 4); else CLRBIT(PORTC, 4)
#define ROW3(x) if(x == 1) SETBIT(PORTC, 3); else CLRBIT(PORTC, 3)
#define ROW4(x) if(x == 1) SETBIT(PORTC, 2); else CLRBIT(PORTC, 2)


#endif /* KEYPAD_CFG_H_ */