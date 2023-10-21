/*
 * KEYPAD.c
 *
 * Created: 3/7/2023 3:09:19 PM
 *  Author: Ali
 */ 

#include "std_macros.h"
#include "KEYPAD.h"
#include "KEYPAD_cfg.h"

uint8 const keypad_matrix[] = {
	'7','8','9','/',
	'4','5','6','*',
	'1','2','3','-',
	'c','0','=','+'
};

/*****************************************************************************
* Function Name: KEYPAD_init
* Purpose      : initialize keypad 4x4
* Parameters   : void
* Return value : void
*****************************************************************************/
void KEYPAD_init(){
	INIT_KEYPAD_PINS();
}

/*****************************************************************************
* Function Name: KEYPAD_read
* Purpose      : Read pins of keypad
* Parameters   : void
* Return value : -1 if no press, value if pressed on of push buttons
*****************************************************************************/
int8 KEYPAD_read(){
	ROW1(0);ROW2(1);ROW3(1);ROW4(1);
	if(COL1() == 0) return keypad_matrix[0];
	if(COL2() == 0) return keypad_matrix[1];
	if(COL3() == 0) return keypad_matrix[2];
	if(COL4() == 0) return keypad_matrix[3];
	_delay_ms(5);
	
	ROW1(1);ROW2(0);ROW3(1);ROW4(1);
	if(COL1() == 0) return keypad_matrix[4];
	if(COL2() == 0) return keypad_matrix[5];
	if(COL3() == 0) return keypad_matrix[6];
	if(COL4() == 0) return keypad_matrix[7];
	_delay_ms(5);
	
	ROW1(1);ROW2(1);ROW3(0);ROW4(1);
	if(COL1() == 0) return keypad_matrix[8];
	if(COL2() == 0) return keypad_matrix[9];
	if(COL3() == 0) return keypad_matrix[10];
	if(COL4() == 0) return keypad_matrix[11];
	_delay_ms(5);
	
	ROW1(1);ROW2(1);ROW3(1);ROW4(0);
	if(COL1() == 0) return keypad_matrix[12];
	if(COL2() == 0) return keypad_matrix[13];
	if(COL3() == 0) return keypad_matrix[14];
	if(COL4() == 0) return keypad_matrix[15];
	_delay_ms(5);
	
	return -1;
}

