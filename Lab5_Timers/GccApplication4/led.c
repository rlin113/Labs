/*
 * led.c
 *
 * Created: 22/09/2026 12:48:12 am
 *  Author: GGPC
 */ 


#include "led.h"

#include <avr/io.h>

void led_toggle(){
	//TODO: LED toggle code
			PORTB ^= (1<<5); 
		}
		
	
