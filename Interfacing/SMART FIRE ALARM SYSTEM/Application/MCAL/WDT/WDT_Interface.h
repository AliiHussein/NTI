/*
 * WDT_Interface.h
 *
 * Created: 10/29/2023 10:11:56 AM
 *  Author: Ali
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

void wdt_enable(uint8 Time);
void wdt_disable(void);
typedef enum{T16_3_ms, T32_5ms, T65_ms, T0_13_s, T0_26_s, T0_52_s, T1_s, T2_1_s}WDT_TIME;




#endif /* WDT_INTERFACE_H_ */