/*
 * adc.c
 *
 * Created: 2019-05-19 오후 3:15:45
 *  Author: yeong
 */ 
#include "adc.h"

void adc_init(unsigned int ch) {
	// ADMUX |= (1<<REFS0);
	ADMUX = ((ADMUX & 0xE0) | ch);

	ADCSRA |= 0x07;
	ADCSRA |= (1<<ADEN) | (1<<ADFR) | (1<<ADSC);
}

int adc_read(void) {
	while(!(ADCSRA & (1<<ADIF)));
	return ADC;
}

void print_adc_value(int adc_value) {
	printf("%d\n", *(&ADMUX));
	printf("adc_value : %d\r\n", adc_value);
	_delay_ms(500);
}

void adc_change_channel(unsigned char ch) {
	ADMUX = ch | (1<<REFS0);
	_delay_ms(1);
}