/*
 * ADC_lab4.c
 *
 * Created: 13/09/2026 6:29:48 pm
 * Author : GGPC
 */ 
#include <stdio.h>
#include "common.h"
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "adc.h"


static FILE usart_stdout = FDEV_SETUP_STREAM(uart_printf, NULL, _FDEV_SETUP_WRITE);


int main(void){
	
	stdout = &usart_stdout;
	uint16_t adc_value; 
	uint32_t voltage_value_mv; 
	
	uart_init(9600);
	adc_init();
		
	while(1){
		
		 adc_value = adc_read(2);
		 voltage_value_mv = adc_convert_mv(adc_value);	
		printf("Voltage: %d mV\n\r", (uint16_t)voltage_value_mv); 

	_delay_ms(1);
		}
}

