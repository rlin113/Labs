/*
 * PrintDigit1.c
 *
 * Created: 28/09/2026 1:10:39 am
 *  Author: GGPC
 */ 


void printDigit (uint8_t digit) {
	
	PORTC = segments[counter] & 0x3F; // Sends bits of counter number to PORTC.
	
	if (segments[counter] & (1<<6)) {
		
		PORTB |= (1<<4); // Send bits of counter number to PORTB.
		
		}	else {
		PORTB &= ~(1<<4);
	}

	