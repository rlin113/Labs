/*
 * GccApplication2.cpp
 *
 * Created: 28/09/2026 7:34:40 pm
 * Author : GGPC
 */ 

#include <avr/io.h>
#include "display.h"
#include "timer0.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint16_t counter = 0; 

ISR(TIMER0_COMPA_vect) {
	send_next_character_to_display(); 
}
int main(void)
{
	init_display();
	timer0_init();
	sei();
	
    while (1) 
    {
		seperate_and_load_characters(counter, 0);
		_delay_ms(400);
		counter++;
		
		if (counter > 9999) {
			counter = 0;
		}
		
}
}

