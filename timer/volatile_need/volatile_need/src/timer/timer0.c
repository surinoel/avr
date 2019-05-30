/*
 * timer0.c
 *
 * Created: 2019-05-28 오후 4:47:53
 *  Author: yeong
 */ 

#include "timer0.h"

int state = 0;
int count = 0;

ISR(TIMER0_OVF_vect) {
	if(count++ == 64) {
		state = !state;
		count = 0;
		if(state) {
			printf("state number 1\r\n");
		}
		else {
			printf("state number 0\r\n");
		}
	}
}

ISR(TIMER0_COMP_vect) {

}

void timer0_ovf_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<TOIE0);
	sei();
}

void timer0_comp_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<OCIE0);
	sei();	
}