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

int main(void){
	//TODO: set direction of LED port to OUTPUT
	DDRB = 0xFF;
	
	timer0_init();
	
	while(1){
		if(timer0_check_clear_compare()) {
			led_toggle();
		}
	}
}