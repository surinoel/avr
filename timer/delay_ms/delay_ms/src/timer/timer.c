/*
 * timer.c
 *
 * Created: 2019-06-02 오후 2:39:40
 *  Author: yeong
 */ 

 #include "timer.h"

 volatile unsigned long timer0_millis = 0;
 
 ISR(TIMER0_OVF_vect) {
	timer0_millis += 1;	
 }

 void timer0_ovf_init(void) {
	TCCR0 |= (1<<CS02);
	TIMSK |= (1<<TOIE0);
	sei();
 }

 void delay_ms(int mstime) {
	timer0_ovf_init();
	timer0_millis = 0;
	TCNT0 = 5;
	
	while(mstime - timer0_millis > 0);

	cli();
}