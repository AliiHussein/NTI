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

void timer0_init(uint8 mode, uint8 prescaler, uint8 iSInterrupt, uint8 Compare_mode);
void PWM0_OC0_duty(uint8 duty_cycle);
void timer0_setOCR(uint8 Value);
void timer0_setTCNT0(uint8 Value);
void timer0_callback(void (*PTR)(void));
void timer0_delay_us(uint32);
void timer0_delay_ms(uint32);
void timer0_delay_s(uint32);
void timer0_disable(void);

typedef enum{NORMAL, PWM_PC, CTC, PWM_FAST}MODES;
typedef enum{P1, P8, P64, P256, P1024}PRESCALER;
typedef enum{INTERUPT_OFF, INTERUPT_ON}INTERRUPT_ENABLE; 
typedef enum{NON_INVERTED, INVERTED, COMPARE_MODE_OFF}Compare_Output_Mode;
#endif /* TIMER0_INTERFACE_H_ */