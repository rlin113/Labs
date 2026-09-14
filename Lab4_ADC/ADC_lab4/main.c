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

	
	uint16_t adc0_values[40];
	uint16_t adc1_values[40];

	uart_init(9600);
	adc_init();
	
	uint8_t i;
	
	for (i = 0; i < 40; i++) {
		adc0_values[i] = adc_read(0);
		_delay_ms(1);
		
		adc1_values[i] = adc_read(1);
		_delay_ms(1);
		
	}
	
	printf("ADC0,ADC1\r\n");
	
		for (i = 0; i < 40; i++)
		{
		 printf( "%u,%u\r\n", adc0_values[i], adc1_values[i]);
		}
	
			

	
	while(1){}
}

