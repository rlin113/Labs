/*
 * uart.c
 *
 * Created: 12/08/2026 11:50:49 am
 * Author :
 */
#include <stdio.h>
#include <avr/io.h> //Needed for using the macros for register addresses
#include <stdint.h>
#include <stdbool.h>
#include "uart.h"


void uart_init(uint16_t baud_rate){
	// Clear the UART Status Register A.
	UCSR0A = 0;
	// Enable the UART transmitter.
	// TXEN0 = 1 enables transmission
	UCSR0B = (1 << TXEN0);
	// 8 data bits, 1 stop bit, no parity 
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	// Set UBRR0 as per baud rate formula
	UBRR0 = 2000000 / (16UL * baud_rate) - 1;

}


void uart_transmit(char character)
{
	// Wait until the UART transmit buffer is empty.
	// UDRE0 is set when UDR0 is ready to receive new data.
	while ((UCSR0A & (1 << UDRE0)) == 0)
	{
		// Wait here until the data register is empty.
	}
	UDR0 = character;
}

void uart_transmit_string(char *string)
{
	// Continue transmitting characters until '\0' is reached.
	while (*string != '\0')
	{
		// Transmit the current character.
		uart_transmit(*string);
		// Move pointer to next Character
		string++;
	}
}

/* Helper function to transmit a fixed number of digits and place a '.' from the rightT */
static void uart_transmit_digits(uint16_t val, uint8_t decimal_pos)
{
	// Iniatialises Buffer large enough for uint16_t (max 65535)
	char digits[6]; 
	// Iniatialises the amount of digits stored in the array 
	uint8_t count = 0;
	
	// Handles 0 insuring the while loop doesn't skip it when val is 0 
	if (val == 0) {
		digits[count++] = '0';
	}

	// 1. Extract digits in reverse order
	while (val > 0) {
		digits[count++] = (val % 10) + '0'; // Convert numeric digit remainder to ASCII character
		val /= 10;                          // Remove the rightmost digit from val
	}

	// 2. Pad with leading zeroes if the number is smaller than the decimal position
	// (e.g., val = 5, decimal_pos = 2 becomes "005" so it prints as "0.05")
	while (count <= decimal_pos) {
		digits[count++] = '0';
	}

	// 3. Print the digits in correct order (from left to right)
	while (count > 0) {
		// Insert decimal point when we reach the decimal_pos index from the right
		if (count == decimal_pos) {
			uart_transmit('.');
		}
		
		// Move index down to point to current digit character
		count--;
		// Transmit character over UART
		uart_transmit(digits[count]);
	}
}

void uart_transmit_value(float value, uint8_t decimal)
{
	// Scale value based on decimal places dynamically
	for (uint8_t i = 0; i < decimal; i++)
	{
		value *= 10.0f;
	}

	uint16_t val = (uint16_t)value;

	// Transmit digits with proper decimal placement
	uart_transmit_digits(val, decimal);
}

int uart_printf(char var, FILE *stream) {
	 uart_transmit(var); //Using our original function to transmit UART data
	return 0;
}