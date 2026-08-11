/*
 * uart.h
 *
 * Created: 11/08/2026 1:26:28 pm
 *  Author: GGPC
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void usart_init(uint16_t ubrr); 
void usart_transmit(char character);
void usart_transmit_number(uint16_t number); 
	
#endif /* UART_H_ */