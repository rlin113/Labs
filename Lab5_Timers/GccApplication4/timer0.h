/*
 * timer0.h
 *
 * Created: 21/09/2026 11:15:15 pm
 *  Author: GGPC
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include <stdbool.h>

//Initialize timer0 as per Part 1
void timer0_init();

//Using polling check if timer0 has reached comparison value
//if so, it will clear the compare flag and return 1
//otherwise, it returns 0
uint8_t timer0_check_clear_compare();

#endif