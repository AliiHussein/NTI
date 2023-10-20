/*
 * seven_seg_cfg.h
 *
 * Created: 3/9/2023 10:56:29 PM
 *  Author: Ali
 */ 


#ifndef SEVEN_SEG_CFG_H_
#define SEVEN_SEG_CFG_H_

#include "std_macros.h"

/*
PORTD
PD0 -- PD6 --> seven segment
PORTB
PB0 -- PB5-> EN1 -- EN6
*/

#define SS_ANODE
#define SEVEN_SEG_INIT_PORTS() DDRB |= 0b00010111; PORTB = 0b00010111; SETBIT(DDRA,3); SETBIT(DDRA,2); SETBIT(DDRB,5); SETBIT(DDRB,6);
#define SS_PORT PORTD

/*
#define DP_ON() CLRBIT(PORTB,6);
#define DP_OFF() SETBIT(PORTB,6);
*/

#ifdef SS_ANODE
#define EN1_DIS() CLRBIT(PORTA,3);
#define EN1_EN()  SETBIT(PORTA,3);
#define EN2_DIS() CLRBIT(PORTA,2);
#define EN2_EN()  SETBIT(PORTA,2);
#define EN3_DIS() CLRBIT(PORTB,5);
#define EN3_EN()  SETBIT(PORTB,5);
#define EN4_DIS() CLRBIT(PORTB,6);
#define EN4_EN()  SETBIT(PORTB,6);
/*
#define EN5_DIS() CLRBIT(PORTB,4);
#define EN5_EN()  SETBIT(PORTB,4);
#define EN6_DIS() CLRBIT(PORTB,5);
#define EN6_EN()  SETBIT(PORTB,5);
*/
#else
#define EN1_DIS() SETBIT(PORTA,3);
#define EN1_EN()  CLRBIT(PORTA,3);
#define EN2_DIS() SETBIT(PORTA,2);
#define EN2_EN()  CLRBIT(PORTA,2);
#define EN3_DIS() SETBIT(PORTB,5);
#define EN3_EN()  CLRBIT(PORTB,5);
#define EN4_DIS() SETBIT(PORTB,6);
#define EN4_EN()  CLRBIT(PORTB,6);
/*
#define EN5_DIS() SETBIT(PORTB,4);
#define EN5_EN()  CLRBIT(PORTB,4);
#define EN6_DIS() SETBIT(PORTB,5);
#define EN6_EN()  CLRBIT(PORTB,5);
*/
#endif


#endif /* SEVEN_SEG_CFG_H_ */