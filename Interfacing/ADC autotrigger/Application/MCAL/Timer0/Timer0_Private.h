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


#endif /* TIMER0_PRIVATE_H_ */