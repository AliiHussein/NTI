/*
 * Application.c
 *
 * Created: 10/20/2023 10:56:41 AM
 * Author : Ali
 */ 


#include "std_macros.h"

#include "HAL/LCD/LCD.h"
#include "HAL/Button/Button.h"
#include "HAL/BUZZER/Buzzer_interface.h"
#include "HAL/H_Bridge/H-Bridge.h"
#include "HAL/GAS_SENSOR/GAS_Interface.h"
#include "HAL/LED/LED.h"

#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/EXT/EXT_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/UART/UART_Interface.h"


uint8 temp_data;
uint8 gas_data;
uint8 flame_data;

void Light_control(void){
	uint8 uart_val;
	Uart_Receive(&uart_val);

	switch(uart_val){
		case '1': led_toggle(portC, 2); break;
		case '2': led_toggle(portC, 3); break;
		case '3': led_toggle(portC, 4); break;
	}
}

void autotrigger(void){
	uint16 volt;
	uint16 value;
	
	ADC_read(A1, &value);
	
	
	volt = (value * 5000UL)/ 1024;
	temp_data = volt/10;
	
	
	flame_data = 1;
	
}

void SEND_DATA(void){
	SPI_send(temp_data);
	SPI_send(gas_data);
	SPI_send(flame_data);
}

void DISPLAY(void){
	LCD_write_command(0x80);
	LCD_write_string((uint8 *)"GAS: ");
	LCD_write_number(gas_data);
	LCD_write_command(0x88);
	LCD_write_string((uint8 *)"Flame: ");
	LCD_write_number(flame_data);
	LCD_write_command(0xc0);
	LCD_write_string((uint8 *)"TEMP: ");
	LCD_write_number(temp_data);
}

/* MASTER */
int main(void)
{
	
	/* INITIALIZATIONS */
	LCD_init();
	SPI_master_init();
	ADC_init();
	button_init(portD, 3); // SEND Button	
	button_init(portD, 2); // Flame Button
	button_init(portD, 4); // GAS Button
	Buzzer_init();
	Motor_Init();
	Uart_init();
	UART_RX_Interrupt_Enable();
	UART_RX_callback(Light_control);
	led_init(portC, 2);
	led_init(portC, 3);
	led_init(portC, 4);
	
	/* EXT0 for FLAME init */
	GIE_Disable();
	EXT_init(EXT0, FALLING);
	EXT_callback(autotrigger, EXT0);
	/* EXT1 for Button init */
	EXT_init(EXT1, FALLING);
	EXT_callback(SEND_DATA, EXT1);
	GIE_Enable();
	
	while(1){
		
		
		
		if(!button_read(portD, 2)){
			flame_data = 1;
		}
		else{
			flame_data = 0;
		}
		
		
		/* BUZZER CONTROL */
		if(temp_data > 27){
			Buzzer_on();
		}
		else{
			Buzzer_off();
		}
		
		/* MOTOR CONTROL */
		if(!READ_gas_sensor()){
			Rotate_Forward(55);    /*  MOTOR ON */
			gas_data = 1;
		}
		else{
			Motor_Stop();         /*  MOTOR OFF */
			gas_data = 0;
		}
		DISPLAY();
		_delay_ms(500);
	}

}





