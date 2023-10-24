/*
 * ADC.c
 *
 * Created: 10/23/2023 12:11:25 PM
 *  Author: Ali
 */ 

#include "Bit_math.h"
#include "std_types.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_CFG.h"

void ADC_init(void){
	// 1. Disable peripherals before config
	CLRBIT(ADCSRA, ADEN);
	// 2. AVCC -> 5V :: REFS1, REFS0 = 0, 1
	SETBIT(ADMUX, REFS0); 
	CLRBIT(ADMUX, REFS1); 
	// 3. Right adjustment +
	CLRBIT(ADMUX, ADLAR);
	// 4. Prescaler -> 128
	ADCSRA |= 0b111;
	// 5. Disable interrupt +
	CLRBIT(ADCSRA, ADIE);
	// 6. Clear ADC flag by setting it +
	SETBIT(ADCSRA, ADIF);
	// 7. Enable ADC
	SETBIT(ADCSRA, ADEN);
	
}

void ADC_read(uint8 channel, uint16 *Value){
	/*
	// 1. Select channel
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	// Start conversion
	SETBIT(ADCSRA, ADSC);
	// Wait for flag
	while(READBIT(ADCSRA, ADSC));
	// return data
	*Value = ADC;
	*/
	
	// 1. Select channel
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	// 2. Start conversion
	SETBIT(ADCSRA, ADSC);
	// 2. Wait for flag
	while(!READBIT(ADCSRA, ADIF));
	// 3. Clear Flag
	SETBIT(ADCSRA, ADIF);
	// 4. return data
	*Value = ADC;
	
}

void ADC_AutoTrigger_init(void){
	// 1. Disable peripherals before config
	CLRBIT(ADCSRA, ADEN);
	// 2. AVCC -> 5V :: REFS1, REFS0 = 0, 1
	CLRBIT(ADMUX, REFS1); SETBIT(ADMUX, REFS0);
	// 3. Right adjustment +
	CLRBIT(ADMUX, ADLAR);
	// 4. Prescaler -> 128
	ADCSRA |= 0b111;
	// 6. Enable  Auto Trigger
	SETBIT(ADCSRA, ADATE);
	// 7. Clear ADC flag by setting it +
	SETBIT(ADCSRA, ADIF);
	// 8. ADC Auto Trigger Source ADTS2 = 0, ADTS1 = 1, ADTS0 = 0
	CLRBIT(SFIOR, ADTS2); SETBIT(SFIOR, ADTS1); CLRBIT(SFIOR, ADTS0);
	// 9. Enable ADC
	SETBIT(ADCSRA, ADEN);
}

void ADC_AutoTrigger_read(uint8 channel, uint16 *Value){
	// 1. Select channel
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	// 2. Wait for flag
	while(!READBIT(ADCSRA, ADIF));
	// 3. Clear Flag
	SETBIT(ADCSRA, ADIF);
	// 4. return data
	*Value = ADC;
}
