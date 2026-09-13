/*
 * ADC_lab4.c
 *
 * Created: 13/09/2026 6:29:48 pm
 * Author : GGPC
 */ 
#include "common.h"
#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

int main(void){
	adc_init();
	


	
	while(1){
		
		 adc_read(2);
		_delay_ms(1);		
		}
}

