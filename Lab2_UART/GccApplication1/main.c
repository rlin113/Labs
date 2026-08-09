/*
 * GccApplication1.c
 *
 * Created: 3/08/2026 10:30:09 pm
 * Author : GGPC
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

bool check_prime(uint16_t chk_no); // Function prototype

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
	
    while (1) 
    {
    }
}

bool check_prime(uint16_t chk_no) {
	for (uint16_t cnt1=2; cnt1 < chk_no; cnt1++) {
	if ((chk_no % cnt1) == 0){
		return false; 
	}
	}
	return true; 
}

