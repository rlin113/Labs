/*
 * part2.c
  *
  * Created: 28/09/2026 7:46:29 pm
  *  Author: GGPC
  */ 
 
//  #include "part2.h"
 //   //  #include <avr/io.h>
 //   //  
 //   //  

//  void send_next_character_to_display(uint8_t pattern) {
 // 	 // Turn on Ds4
 // 	 PORTD &= ~(1<<7);
 // 	 
 // 	 // Turn off Ds3, Ds2 and Ds1
 // 	 PORTD |= (1<<6);
 // 	 PORTD |= (1<<5);
 // 	 PORTD |= (1<<4);
 // 	 
 // 	 // Turn off SH_CP and SH_ST
 // 	 PORTC &= ~(1<<3);
 // 	 PORTC &= ~(1<<5);
 // 	 
 // 	 // Extract 8 bits
 // 	 for (int8_t i = 7; i >= 0; i--) {
 // 		 if (pattern & (1<<i)) {
 // 			 PORTC |= (1<<4);
 // 		 }
 // 		 else { PORTC &= ~(1<<4);
 // 		 }
 // 		 
 // 		 // Create clock pulse
 // 		 PORTC |= (1<<3);
 // 		 PORTC &= ~(1<<3);
 // 	 }
 // 	 
 // 	 // Transfer byte
 // 	 PORTC |= (1<<5);
 // 	 PORTC &= ~(1<<5);
 // 	 
 //  }
 // 
 //  