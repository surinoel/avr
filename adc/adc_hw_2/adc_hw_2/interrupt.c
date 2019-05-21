/*
 * interrupt.c
 *
 * Created: 2019-05-19 오후 4:33:05
 *  Author: yeong
 */ 

#include "interrupt.h"

volatile int flag;

ISR(INT4_vect) {
	_delay_ms(20);
	flag = 1;
	while(!(PINE & (1<<4)));
	_delay_ms(20);
	EIFR |= (1<<4);
}

void int4_init(void) {
	PORTE |= (1<<4);
	EIMSK |= (1<<INT4);
	EICRB |= (1<<ISC41);
	sei();
}