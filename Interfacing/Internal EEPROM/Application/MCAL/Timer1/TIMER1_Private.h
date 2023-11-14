/*
 * TIMER1_Private.h
 *
 * Created: 11/14/2023 4:19:50 PM
 *  Author: Mahmoud Nassef
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A (*(( volatile uint8*)0x4F))
#define TCCR1B (*(( volatile uint8*)0x4E))

#define TCNT1H (*(( volatile uint8*)0x4D))
#define TCNT1L (*(( volatile uint8*)0x4C))
#define TCNT1 (*(( volatile uint8*)0x4C))

#define OCR1AH (*(( volatile uint8*)0x4B))
#define OCR1AL (*(( volatile uint8*)0x4A))

#define OCR1BH (*(( volatile uint8*)0x49))
#define OCR1BL (*(( volatile uint8*)0x48))

#define ICR1 (*(( volatile uint8*)0x46))
#define ICR1H (*(( volatile uint8*)0x47))
#define ICR1L (*(( volatile uint8*)0x46))

#define TIFR (*(( volatile uint8*)0x58))
#define ICF1 5 


 


#endif /* TIMER1_PRIVATE_H_ */