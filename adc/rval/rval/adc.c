/*
 * adc.c
 *
 * Created: 2019-05-18 오후 10:14:50
 *  Author: yeong
 */ 
#include "adc.h"

extern FILE OUTPUT;
extern FILE INPUT;

void adc_init(unsigned char ch) {
	ADMUX |= (1<<REFS0);
	ADMUX = ((ADMUX & 0xE0) | ch);

	ADCSRA |= 0x07;
	ADCSRA |= (1<<ADEN) | (1<<ADFR) | (1<<ADSC);
}

void adc_change_channel(unsigned char ch) {
	ADMUX = ((ADMUX & 0xE0) | ch);
	_delay_us(50);
}

int adc_read(void) {
	while(!(ADCSRA & (1<<ADIF)));
	return ADC;
}