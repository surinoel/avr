/*
 * timer0.c
 *
 * Created: 2019-05-28 오후 4:47:53
 *  Author: yeong
 */ 

#include "timer0.h"

volatile int state;

ISR(TIMER0_OVF_vect) {
	state = !state;
	if(state) PORTA = 0xff;
	else PORTA = 0x00;	
}

ISR(TIMER0_COMP_vect) {

}

void timer0_ovf_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS00);
	TIMSK |= (1<<TOIE0);
	sei();
}

void timer0_comp_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<OCIE0);
	sei();	
}

void rtc_init(void) {
	ASSR |= (1<<AS0);
}