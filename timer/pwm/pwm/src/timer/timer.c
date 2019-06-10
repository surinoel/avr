/*
 * timer.c
 *
 * Created: 2019-06-09 오후 3:28:47
 *  Author: yeong
 */ 

 #include "timer.h"

 enum scale {
	EOS = -1, 
	DO, RE, MI, FA, SOL, RA, SI, DDO
 };

 volatile int state, tone;
 char f_table[8] = {17, 43, 66, 77, 97, 114, 117, 137};
 int song[] = {SOL, MI, MI, SOL, MI, DO, RE, MI, RE, DO, MI, SOL, DDO, SOL, DDO, SOL, DDO, SOL, MI, SOL, RE, FA, MI, RE, DO, EOS};
 
 ISR(TIMER0_OVF_vect)
 {
	if(state == 0) {
		PORTB |= (1<<4);
		state = 1;
	}
	else {
		PORTB &= ~(1<<4);
		state = 0;
	}
	TCNT0 = f_table[tone];
 }

 void buzzer_init(void)
 {
	DDRB |= (1<<4);
	TCCR0 |= (1<<CS01) | (1<<CS00);
	TIMSK |= (1<<TOIE0);

	sei();
	for(int i=0; song[i] != EOS; i++) {
		tone = song[i];
		_delay_ms(500);
	}
	cli();
 }

/* 
 void timer1_pwm_init(void)
 {
	 TCCR1A |= (1<<WGM11) | (1<<COM1A1);
	 TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10);
	 DDRB |= (1<<5);
	 ICR1 = 5000;
 }
*/