/*
 * main.c
 *
 * Created: 11/17/2023 3:05:06 PM
 *  Author: Ali
 */ 

#include "std_macros.h"
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"

#include "MCAL/TWI/TWI_int.h"

#include "HAL/LED/LED.h"
#include "HAL/SevenSeg/SevenSeg.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/LCD/LCD.h"

/* Macros */
#define LEFT_MOTOR  5
#define RIGHT_MOTOR 6
#define MAIN_MOTOR  7

#define UP_DIRECTION       1
#define DOWNE_DIRECTION    4
#define LEFT_DIRECTION     3
#define RIGHT_DIRECTION    2

#define MAIN_MOTOR_ON   0
#define OFF_MAIN_MOTOR  1


/* GLOBAL Variables */
uint8 Direction = 0;
uint8 State = 0;
uint8 Message = 0;
uint8 volatile SENSOR_PUSH_BUTTON = 0;



void Task_Keypad(void){
	KEYPAD_init();
	LCD_init();
	
	uint8 temp;
	
	while (1)
	{
		
		temp = get_input_from_user();
		SENSOR_PUSH_BUTTON = temp;
		LCD_write_command(0xc0);
		LCD_write_string("      ");
		LCD_write_command(0xc0);
		switch(temp){
			case 1: Direction = temp; LCD_write_string("Up"); break;
			case 2: Direction = temp; LCD_write_string("LL"); break;
			case 3: Direction = temp; LCD_write_string("RR"); break;
			case 4: Direction = temp; LCD_write_string("down"); break;
			case 5: State = temp; LCD_write_string("Left"); break;
			case 6: State = temp; LCD_write_string("Right"); break;
			case 7: State = temp; LCD_write_string("Main"); break;

		}
		
		vTaskDelay(1);
	}
}

/*
void Task_App(void)
{
	
	while(1){
		switch (State)
		{
			case LEFT_MOTOR:
			switch (Direction)
			{
				case UP_DIRECTION:
				Message=4;
				break;
				case DOWNE_DIRECTION:
				Message=3;
				break;
				case LEFT_DIRECTION:
				Message=2;
				break;
				case RIGHT_DIRECTION:
				Message=5;
				break;
			} break;
			
			case RIGHT_MOTOR:
			switch (Direction)
			{
				case UP_DIRECTION:
				Message=8;
				break;
				case DOWNE_DIRECTION:
				Message=7;
				break;
				case LEFT_DIRECTION:
				Message=6;
				break;
				case RIGHT_DIRECTION:
				Message=9;
				break;
			} break;
			
// 			case MAIN_MOTOR:
// 			switch (Direction)
// 			{
// 				case UP_DIRECTION:
// 				Message=0;
// 				break;
// 				case DOWNE_DIRECTION:
// 				Message=1;
// 				break;
// 				
// 			} break;
			
		}
		
		vTaskDelay(10);
	}
	
}


void Task_Communication(void)
{
	M_TWI_void_Init();
	
	while (1)
	{
		M_TWI_u8_StartCondition();
		M_TWI_u8_SendSlaveAddressWrite(0x00);
		M_TWI_u8_SendByte(0x77);
		M_TWI_u8_RepeatedStart();
		M_TWI_u8_SendByte(Message);
		M_TWI_void_StopCondition();
		
		vTaskDelay(1);
	}
}
*/
void Task_Measure(void){
	static uint8 flag = 0;
	led_init(portA, 5);

	while (1)
	{
		if (SENSOR_PUSH_BUTTON == 7)
		{
			if(flag==0)
			{
				Message= MAIN_MOTOR_ON;
				flag=1;
				led_on(portA, 5);
			}
			else
			{
				Message= 1;
				flag=0;
				led_off(portA, 5);
			}

		}

		vTaskDelay(1000);
	}

}

int main(void){
	
	/* Task creation and scheduling*/
	xTaskCreate(Task_Keypad, "Keypad"		, 150, NULL, 1, NULL);
// 	xTaskCreate(Task_Communication, "Send"	, 100, NULL, 2, NULL);
	xTaskCreate(Task_Measure, "Measure"		, 100, NULL, 1, NULL);
// 	xTaskCreate(Task_App, "Background"		, 100, NULL, 1, NULL);
	vTaskStartScheduler();
	
}