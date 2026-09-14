/*
 * uart.h
 *
 * Created: 12/08/2026 11:26:49 am
 * Author :
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef UART_H_
#define UART_H_

//Prototypes of functions used

/* UART initialisation */
void uart_init(uint16_t ubrr);

/* This function transmits a single byte via the UART */
void uart_transmit(char character);

/* Transmit a string */
void uart_transmit_string(char *string);

/* Converts a floating-point value to an integer representation based on requested decimal precision */
void uart_transmit_value(float value, uint8_t decimal);


int uart_printf(char var, FILE *stream);

#endif /* UART_H_ */