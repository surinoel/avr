/*
 * interrupt.c
 *
 * Created: 2019-05-18 오후 11:08:17
 *  Author: yeong
 */ 

#include "interrupt.h"

int flag;

ISR(INT4_vect) {
	_delay_ms(10);
	flag = 1;
	while(!(PINE & (1<<4)));
	_delay_ms(10);
	EIFR |= (1<<4);
}

ISR(INT5_vect) {
	_delay_ms(10);
	while(!(PINE & (1<<5)));
	_delay_ms(10);
	EIFR |= (1<<5);
}

void int_init(void) {
	PORTE |= ((1<<4) | (1<<5));
	EIMSK |= ((1<<4) | (1<<5));
	EICRB |= ((1<<ISC41) | (1<<ISC51));

	sei();
}