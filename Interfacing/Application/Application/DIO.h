/*
 * DIO.h
 *
 * Created: 10/20/2023 10:57:36 AM
 *  Author: Ali
 */ 


#ifndef DIO_H_
#define DIO_H_

#define PORTA *((volatile uint8 *)0x3B)
#define PORTB *((volatile uint8 *)0x38)
#define PORTC *((volatile uint8 *)0x35)
#define PORTD *((volatile uint8 *)0x32)

#define DDRA *((volatile uint8 *)0x3A)
#define DDRB *((volatile uint8 *)0x37)
#define DDRC *((volatile uint8 *)0x34)
#define DDRD *((volatile uint8 *)0x31)

#define PINA *((volatile uint8 *)0x39)
#define PINB *((volatile uint8 *)0x36)
#define PINC *((volatile uint8 *)0x33)
#define PIND *((volatile uint8 *)0x30)




#endif /* DIO_H_ */