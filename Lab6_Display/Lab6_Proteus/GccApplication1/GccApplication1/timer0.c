/*
 * timer0.c
 *
 * Created: 28/09/2026 4:20:31 pm
 *  Author: GGPC
 */ 

#include "timer0.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


void timer0_init() {

	TCCR0A = (1 << WGM01); // Set CTC mode
	TCCR0B = (1 << CS02); // Set prescaler to 256
	TIMSK0 = (1 << OCIE0A ); // enable interrupt for compare match A
    OCR0A = 77; // Count value = 10ms delay
	TCNT0 = 0;
}
	
