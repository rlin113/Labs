	/*
 * GccApplication1.c
 *
 * Created: 27/09/2026 8:17:01 pm
 * Author : GGPC
 */ 


#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer0.h"

// Digit values from 0 - 9:
uint8_t segments[10] =
{
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F
};

volatile uint8_t counter = 0;
volatile uint8_t digit = 0;



void printDigit (uint8_t digit) {
	
	PORTC = segments[digit] & 0x3F; // Sends bits of counter number to PORTC.
	
	if (segments[digit] & (1<<6)) {
		
		PORTB |= (1<<4); // Send bits of counter number to PORTB.
		
		}	else {
		PORTB &= ~(1<<4);
	}
}

	ISR(TIMER0_COMPA_vect) {
		
		// Determine digit (digit 1 = 0 or digit 2 = 1)
		if (digit == 0) {
			digit = 1;
		}
		else {
			digit = 0;
		}
		
		uint8_t number;
		
		// Splits counter value into Ds1 and Ds2
		if (digit == 0) {
			number = counter / 10;
			
			} else {
				number = counter % 10;
			}
			
			// Disable both digits
			PORTB |= ( 1 << 0);
			PORTB |= ( 1 << 1);
			
			// Set segment pins
			printDigit(number);
			
			// Enable chosen digit
			
			if (digit == 0) {
				PORTB &= ~(1 << 0);
			}
			else {
				PORTB &= ~(1 << 1);
			}
		}
			
int main(void) {

// Set ports:
DDRB = 0x33;
DDRC = 0x3F;
DDRD = 0x00; 

timer0_init();
sei(); 

    /* Replace with your application code */
    while (1) {

_delay_ms(1000); 
counter++;
		
			// Counter resets when it reaches 99.
			if (counter > 99) {
				counter = 0;
			}
		
}
	}
	

