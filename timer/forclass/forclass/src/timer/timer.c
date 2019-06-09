/*
 * timer.c
 *
 * Created: 2019-06-02 오후 2:39:40
 *  Author: yeong
 */ 

 #include "timer.h"

 volatile int cnt = 0;
 volatile int flag = 0;

 /*
 ISR(TIMER0_OVF_vect) {
	if(++cnt == 61) {
		flag = 1;
		cnt = 0;		
	}
 }
 */

 ISR(TIMER0_COMP_vect) {
	if(++cnt == 61) {
		PORTA ^= 0xff;
		cnt = 0;
	}
 }
 
 void timer0_ovf_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<TOIE0);
	sei();
 }

 void timer0_comp_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<OCIE0);
	OCR0 = 128;
	sei();
 }

 void timer0_comp_ctc_init(void) {
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	TCCR0 |= (1<<WGM01);
	TIMSK |= (1<<OCIE0);
	OCR0 = 128;
	sei();
 }

