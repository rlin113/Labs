/*
 * timer0.c
 *
 * Created: 21/09/2026 11:14:50 pm
 *  Author: GGPC
 */ 
#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


void timer0_init() {

//This ISR function is called when timer0 reaches
//compare value, compare flag is automatically cleared
//TODO: initialise and configure timer0 to interrupt every 10ms

	TCCR0A = 0x00; 
	TCCR0B = 0x00; 
	TCNT0 = 0; 

uint8_t timer0_check_clear_compare(){
	
	 
	if (( TIFR0 & (1 << OCF0A )) != 0){ //TODO: check compare flag
		//TODO: clear compare flag.
		TIFR0 |= (1<<OCF0A);

		//Note: in datasheet this is done by writing 1 to the compare flag
		
		return 1;
	}
	return 0;
}
}