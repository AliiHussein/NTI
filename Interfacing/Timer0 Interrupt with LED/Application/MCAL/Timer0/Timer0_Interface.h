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
void enable_timer0_int(void);

#endif /* TIMER0_INTERFACE_H_ */