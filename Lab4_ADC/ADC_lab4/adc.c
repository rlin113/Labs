/*
 * adc.c
 *
 * Created: 13/09/2026 6:32:54 pm
 *  Author: GGPC
 */ 

#include "common.h"
#include "adc.h"
#include <avr/io.h> 

void adc_init() {
	ADMUX = 0x42; 
	ADCSRA |= (1<<ADEN) | (4<<ADPS0);
	ADCSRB = 0x00; 
}

uint16_t adc_read(uint8_t chan) {
	ADMUX &= 0xF0;
	ADMUX |= chan;
	ADCSRA |= (1<<ADIF);
	ADCSRA |= (1 << ADSC);
	
	while ((ADCSRA &  ( 1 << ADIF)) == 0) {
		;
	}
	return ADC;
}

uint32_t adc_convert_mv(uint16_t value) {
	return (uint32_t)value * 5000 / 1024;
}

