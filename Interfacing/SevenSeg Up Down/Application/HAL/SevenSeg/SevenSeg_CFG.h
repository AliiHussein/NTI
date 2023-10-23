/*
 * SevenSeg_CFG.h
 *
 * Created: 10/21/2023 10:19:45 AM
 *  Author: Ali
 */ 


#ifndef SEVENSEG_CFG_H_
#define SEVENSEG_CFG_H_

/*
	Decoder
	1. PB0 -> output
	2. PB1 -> output
	3. PB2 -> output
	4. PB4 -> output
	
	Enables (VCC)
	1. PA3 -> output
	2. PA2 -> output
	3. PB5 -> output
	4. PB6 -> output
*/

#define SEVEN_SEG_INIT_PORTS() DDRB = 0xff; PORTB = 0xff; SETBIT(DDRA,2); SETBIT(DDRA,3);

#define EN4_EN() CLRBIT(PORTB,6);
#define EN4_DIS()  SETBIT(PORTB,6);
#define EN3_EN() CLRBIT(PORTB,5);
#define EN3_DIS()  SETBIT(PORTB,5);
#define EN2_EN() CLRBIT(PORTA,2);
#define EN2_DIS()  SETBIT(PORTA,2);
#define EN1_EN() CLRBIT(PORTA,3);
#define EN1_DIS()  SETBIT(PORTA,3);


#endif /* SEVENSEG_CFG_H_ */