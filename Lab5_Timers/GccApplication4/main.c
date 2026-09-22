/*
 * GccApplication4.c
 *
 * Created: 21/09/2026 10:56:02 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"
#include "uart.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>



//This special function call enables the use of interrupts
	

	int main(void)
	{
		//TODO: set direction of LED port to OUTPUT
		timer0_init();
		uart_init(9600);
			DDRB &= ~(1 << 2);

		while (1) {
			while (!(PIND & 1 << 2)) {} // Runs when rising edge's been found 
				
				TCNT0 = 0; // Count from zero
				TCCR0B = 0x04; // Set presacle 256
				
				while (PIND & (1<<2)) {}
					TCCR0B = 0x00; // Stop measuring 
					
					uint8_t counts = TCNT0; 
					
					// Calculations
					float high = counts * 0.000128;
					float period = 2 * high; // 50% duty cycle
					float frequency = 1 / period; 
					
					uart_transmit_string("Frequency is: ");
					uart_transmit_value(frequency, 1);
					uart_transmit_string(" Hz\r\n"); 
					
				
				
				
	}
	}