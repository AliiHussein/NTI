/*
 * Timer0_Interface.h
 *
 * Created: 10/24/2023 3:11:06 PM
 *  Author: Ali
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

// init -> normal mode
// Call back function to use ISR
// Enable interrupt

void timer0_init(void);
void timer0_callback(void (*PTR)(void));
void timer0_int_enable(void);
void timer0_delay_us(uint32);
void timer0_delay_ms(uint32);
void timer0_delay_s(uint32);
void timer0_disable(void);

#endif /* TIMER0_INTERFACE_H_ */