/*
 * ADC_Interface.h
 *
 * Created: 10/23/2023 12:16:30 PM
 *  Author: Ali
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Private.h"

void ADC_init(void);
void ADC_read(uint8 channel, uint16 *Value);

void ADC_AutoTrigger_init(void);
void ADC_AutoTrigger_read(uint8 channel, uint16 *Value);

typedef enum{A0, A1, A2, A3, A4, A5, A6, A7}Channels;

#endif /* ADC_INTERFACE_H_ */