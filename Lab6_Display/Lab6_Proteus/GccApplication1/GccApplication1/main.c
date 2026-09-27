/*
 * GccApplication1.c
 *
 * Created: 27/09/2026 8:17:01 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

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
	
	void printDigit (uint8_t digit) {
		
		PORTC = segments[digit] & 0x3F; // Sends bits of counter number to PORTC.
		
		if (segments[digit] & (1<<6)) {
			
			PORTB |= (1<<4); // Send bits of counter number to PORTB.
			
			}	else {
			PORTB &= ~(1<<4);
		}
	}


int main(void) {

// Set ports:
DDRB = 0x33;
DDRC = 0x3F;
DDRD = 0x00; 

PORTB |= (1 << 0); // Set Ds1 to 1.
PORTB &= ~(1 << 1); // Set Ds2 to 0.

uint8_t counter = 0;


    /* Replace with your application code */
    while (1) {
		printDigit (counter);
		
	
	// Check if button is pushed. (10 times during 1 count).

		for (uint8_t i = 0; i < 10; i++) {
				if ((PINB & (1 << 7)) == 0) {
					counter = 0;
					printDigit(counter);
					
				}
				_delay_ms(100); 
		}
		

		counter++;
		
			// Counter resets when it reaches 9.
			if (counter > 9) {
				counter = 0;
			}
		
}
	}
	

