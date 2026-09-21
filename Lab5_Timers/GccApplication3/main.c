/*
 * GccApplication3.c
 *
 * Created: 21/09/2026 8:32:41 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
DDRB = 0xFF;
DDRC= 0x00;
DDRD = 0x00;

    /* Replace with your application code */
    while (1)
    {
		PORTB |= (1<<5);
		_delay_ms (37.5);
		
		PORTB &= ~(1<<5);
		_delay_ms (12.5);
    }
}

