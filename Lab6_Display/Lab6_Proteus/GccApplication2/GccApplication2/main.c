/*
 * GccApplication2.cpp
 *
 * Created: 28/09/2026 7:34:40 pm
 * Author : GGPC
 */ 

#include <avr/io.h>
#include "part2.h"

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
	0x87,
	0x7F,
	0x6F
};

int main(void)
{
	
	init_display(); 
	uint8_t pattern = segments[7]; 
	
	
    while (1) 
    {
		send_next_character_to_display(pattern);
		
}
}

