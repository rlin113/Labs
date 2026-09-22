/*
 * GccApplication4.c
 *
 * Created: 21/09/2026 10:56:02 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>


//This special function call enables the use of interrupts
	
	int main(void)
	{
		//TODO: set direction of LED port to OUTPUT
		timer0_init();
			DDRB = 0xFF;

		sei();
		while (1) { }
	}