/*
 * timer.c
 *
 * Created: 2019-06-09 오후 2:53:22
 *  Author: yeong
 */ 

#include "timer.h"

volatile unsigned long millis;

ISR(TIMER0_OVF_vect) {
	TCNT0 = 5;
	millis += 1;
}

void delay_ms(int mstime)
{
	TCCR0 |= (1<<CS02);
	TIMSK |= (1<<TOIE0);
	TCNT0 = 5;
	millis = 0;
	sei();
	
	while(mstime != millis);

	cli(); 
}