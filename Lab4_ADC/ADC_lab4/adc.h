/*
 * adc.h
 *
 * Created: 13/09/2026 6:33:03 pm
 *  Author: GGPC
 */ 


#ifndef _ADC_H
#define _ADC_H

#include <stdint.h> 
void adc_init();
uint16_t adc_read(uint8_t chan);
uint32_t adc_convert_mv(uint16_t value);

#endif