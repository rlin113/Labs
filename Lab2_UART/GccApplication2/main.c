/*
 * GccApplication2.c
 *
 * Created: 3/08/2026 10:30:09 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL
#include <stdint.h>
#include <stdbool.h>
#include "uart.h"
#include <util/delay.h>

bool check_prime(uint16_t chk_no) {
	for (uint16_t cnt1=2; cnt1 < chk_no; cnt1++) {
		if ((chk_no % cnt1) == 0){
			return false;
		}
	}
	return true;
}


int main(void)  

{
	uint16_t prime_array[62];
	uint8_t prime_count = 0;
	
	// Generate all prime numbers up to 300
	for(uint16_t num = 2; num <= 300; num++) {
		if(check_prime(num)) {
			prime_array[prime_count] = num;
			prime_count++;
		}
	}
	
	usart_init(12);
   
    while (1) 
    {
		for (uint8_t i = 0; i < prime_count; i++)
		{
			usart_transmit_number(prime_array[i]);
			usart_transmit(',');
			usart_transmit(' ');
			
			_delay_ms(500);
		}
	}
}


