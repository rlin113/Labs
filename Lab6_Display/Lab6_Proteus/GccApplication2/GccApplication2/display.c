/*
 * display.c
 *
 * Created: 28/09/2026 9:43:47 pm
 *  Author: GGPC
 */ 

#include <avr/io.h>
#include "display.h"

//Array containing which segments to turn on to display a number between 0 to 9
//As an example seg_pattern[0] is populated with pattern to display number ‘0’
//TODO: Populate this array using your answer to QP.1
const uint8_t seg_pattern[10]={
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07, 
	0x7F,
	0x6F
}; 

//4 characters to be displayed on Ds1 to Ds 4
static volatile uint8_t disp_characters[4]={0,0,0,0};

//The current digit (e.g. the 1's, the 10's) of the 4-digit number we're displaying
static volatile uint8_t disp_position=0;

void init_display(void){
	DDRC |= (1<<3);
	DDRC |= (1<<4);
	DDRC |= (1<<5);
	
	DDRD |= (1<<4);
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
}

//Populate the array ‘disp_characters[]’ by separating the four digits of ‘number’
//and then looking up the segment pattern from ‘seg_pattern[]’
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	uint8_t thousands = number / 1000;
	uint8_t hundreds = (number / 100) % 10;
	uint8_t tens = (number / 10) % 10;
	uint8_t ones = number % 10;
	
	disp_characters[0] = seg_pattern[thousands];
		disp_characters[1] = seg_pattern[hundreds];
			disp_characters[2] = seg_pattern[tens];
				disp_characters[3] = seg_pattern[ones];
}

//Render a single digit from ‘disp_characters[]’ on the display at ‘disp_position’
void send_next_character_to_display(void){
	
	uint8_t pattern = disp_characters[disp_position];
	
	 // Extract 8 bits
	 for (int8_t i = 7; i >= 0; i--) {
		 if (pattern & (1<<i)) {
			 PORTC |= (1<<4);
		 }
		 else { PORTC &= ~(1<<4);
		 }
		 
		 // Create clock pulse
		 PORTC |= (1<<3);
		 PORTC &= ~(1<<3);
		 
	 }
	 
	 
	 // Disable all digits
	  PORTD |= (1<<6);
	  PORTD |= (1<<5);
	  PORTD |= (1<<4);
	  PORTD |= (1<<7);
	  
	  	 // Transfer byte
	  	 PORTC |= (1<<5);
	  	 PORTC &= ~(1<<5);
		   
		  if (disp_position == 0) {
			   PORTD &= ~(1<<4);
		  } else if (disp_position == 1){
			    PORTD &= ~(1<<5); 
		  }  else if (disp_position == 2){
			    PORTD &= ~(1<<6); }
				else {   PORTD &= ~(1<<7);
				}
				
				disp_position++;
				if (disp_position > 3) {
					disp_position = 0;}
					
	 
	 

	//4. Latch the output by toggling SH_ST pin as in Q2.2
	//5. Now, depending on the value of pos, enable the correct digit
	//   (i.e. set Ds1, Ds2, Ds3 and Ds4 appropriately)
	//6. Increment ‘disp_position’ so the next of the 4 digits will be displayed
	//   when function is called again from ISR (reset ‘disp_position’ after 3)
}

