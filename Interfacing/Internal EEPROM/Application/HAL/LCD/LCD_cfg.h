/*
 * LCD_cfg.h
 *
 * Created: 3/7/2023 3:12:17 PM
 *  Author: Ali
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "std_macros.h"

/*
D7--D4 --> B4--B0
EN --> A2
RS --> A3
PORTA(2--7) connected to LCD
*/
#define INIT_LCD_PINS() SETBIT(DDRA, 3); SETBIT(DDRA, 2); SETBIT(DDRB, 0); SETBIT(DDRB, 1); SETBIT(DDRB, 2); SETBIT(DDRB, 4);

#define LCD_RS(x) if(x == 1) SETBIT(PORTA, 3); else CLRBIT(PORTA, 3);
#define LCD_EN(x) if(x == 1) SETBIT(PORTA, 2); else CLRBIT(PORTA, 2);
#define LCD_D4(x) if(x == 1) SETBIT(PORTB, 0); else CLRBIT(PORTB, 0);
#define LCD_D5(x) if(x == 1) SETBIT(PORTB, 1); else CLRBIT(PORTB, 1);
#define LCD_D6(x) if(x == 1) SETBIT(PORTB, 2); else CLRBIT(PORTB, 2);
#define LCD_D7(x) if(x == 1) SETBIT(PORTB, 4); else CLRBIT(PORTB, 4);

#endif /* LCD_CFG_H_ */