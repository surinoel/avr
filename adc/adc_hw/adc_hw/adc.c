/*
 * adc.c
 *
 * Created: 2019-05-19 오후 3:15:45
 *  Author: yeong
 */ 
#include "adc.h"

int cur_ch;

void adc_init(unsigned char ch) {
	ADMUX |= ch | (1<<REFS0);
	ADCSRA |= ((1 << ADEN) | (1 << ADSC) | (1 << ADFR) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
	cur_ch = ch;
}

int adc_read(void) {
	while(!(ADCSRA & (1<<ADIF)));
	// return (ADCH << 8) | ADCL;
	return ADC;
}

void print_adc_value(int adc_value) {
	printf("adc_value : %d\r\n", adc_value);
	_delay_ms(500);
}

void adc_change_channel(unsigned char ch) {
	ADMUX = ch | (1<<REFS0);
	_delay_ms(1);
}