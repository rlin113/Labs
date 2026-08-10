/*
 * GccApplication1.c
 *
 * Created: 3/08/2026 10:30:09 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h.>
#include <stdint.h>

void usart_init(uint16_t ubrr) {
	
	UCSR0A = 0b00000000;
	UCSR0B = 0b00001000;
	UCSR0C = 0b00000110; 
	UBRR0 = ubrr;
}

void usart_transmit(char character) {
	while ((UCSR0A & 0b00100000) == 0) {
;
}
UDR0 = character; 
}


int main(void)  
{
	usart_init(12);
   
    while (1) 
    {
		uint16_t number = 345;
		
		uint8_t digit1 = number % 10;
		number = number / 10;
		
		uint8_t digit2 = number % 10;
		number = number / 10;
		
		uint8_t digit3 = number % 10;

		usart_transmit(digit3 + 48);
		usart_transmit(digit2 + 48);
		usart_transmit(digit1 + 48);

		_delay_ms(500);
     }
}

