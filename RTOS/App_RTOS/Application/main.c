/*
 * main.c
 *
 * Created: 11/17/2023 3:05:06 PM
 *  Author: Ali
 */ 

#include "std_macros.h"
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"

#include "HAL/LED/LED.h"
#include "HAL/SevenSeg/SevenSeg.h"


void task1(void){
	led_init(portA,5);
	while (1)
	{
		led_toggle(portA,5);
		vTaskDelay(1000);
	}
}

void task2(void){
	led_init(portA, 6);
	while (1)
	{
		led_toggle(portA,6);
		vTaskDelay(5000);
	}
}

void task3(void){
	sevenseg_init();
	uint8 count = 0;
	while(1)
	{
		sevenseg_write_four(count);
		count++;
		if(count == 100){
			count = 0;
		}
		vTaskDelay(1000);
		
	}
}



int main(void){
	
	/* Task creation and scheduling*/
	xTaskCreate(task1, "T1", 100, NULL, 1, NULL);
	xTaskCreate(task2, "T2", 100, NULL, 1, NULL);
	xTaskCreate(task3, "T3", 100, NULL, 2, NULL);
	vTaskStartScheduler();
	
}