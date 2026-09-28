/*
 * display.h
 *
 * Created: 28/09/2026 9:43:59 pm
 *  Author: GGPC
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos); 
void init_display(void);
void send_next_character_to_display(void);





#endif /* DISPLAY_H_ */