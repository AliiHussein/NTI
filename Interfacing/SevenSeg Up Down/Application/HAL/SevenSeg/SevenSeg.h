/*
 * SevenSeg.h
 *
 * Created: 10/21/2023 9:55:01 AM
 *  Author: Ali
 */ 


#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#include "std_macros.h"
#include "SevenSeg_CFG.h"

void sevenseg_init(void);
void sevenseg_write(uint8 value, uint8 ss_num);


#endif /* SEVENSEG_H_ */