/*
 * timer.c
 *
 * Created: 2019-06-14 오후 8:46:45
 *  Author: yeong
 */ 

 #include "timer.h"

 ISR(TIMER1_CAPT_vect) {
	int capt1 = TCNT1;
	int capt2 = ICR1;

	printf("Input Capture : %u\r\n", capt2);
	printf("Timer/Counter : %u\r\n\r\n", capt1);
 }

 void icp_timer1_init(void) {
	TCCR1B |= (1<<CS12) | (1<<CS10);
	TIMSK |= (1<<TICIE1);
	sei();
 }