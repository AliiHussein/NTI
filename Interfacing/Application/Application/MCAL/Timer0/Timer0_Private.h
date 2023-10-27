/*
 * Timer0_Private.h
 *
 * Created: 10/24/2023 3:11:25 PM
 *  Author: Ali
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0 *((volatile uint8 *)0x53)
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

#define TCNT0 *((volatile uint8 *)0x52)

#define TIMSK *((volatile uint8 *)0x59)
#define OCIE2  7
#define TOIE2  6 
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2
#define OCIE0  1
#define TOIE0  0

#define TIFR *((volatile uint8 *)0x58)
#define OCF2  7
#define TOV2  6
#define ICF1  5
#define OCF1A 4
#define OCF1B 3
#define TOV1  2
#define OCF0  1
#define TOV0  0

#define OCR0 *((volatile uint8 *)0x5C)



#endif /* TIMER0_PRIVATE_H_ */