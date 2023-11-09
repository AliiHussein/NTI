/*
 * WDT_Private.h
 *
 * Created: 10/29/2023 10:12:07 AM
 *  Author: Ali
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define MCUCSR *((volatile uint8 *)0x54)
#define JTRF  4
#define WDRF  3
#define BORF  2
#define EXTRF 1
#define PORF  0

#define WDTCR *((volatile uint8 *)0x41)
#define WDTOE 4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0


#endif /* WDT_PRIVATE_H_ */