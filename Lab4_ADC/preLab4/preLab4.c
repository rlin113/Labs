/*
 * preLab4.c
 *
 * Created: 13/09/2026 1:03:28 pm
 * Author : GGPC
 */ 


#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

#define DELAY_TIME 500

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<5); 
		_delay_ms(DELAY_TIME);
		 
		 PORTB &= ~(1<<5);
		 _delay_ms(DELAY_TIME);

    }
}

