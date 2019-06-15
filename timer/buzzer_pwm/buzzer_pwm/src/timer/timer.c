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
	TCCR0 = (1<<CS01) | (1<<CS00);
	TIMSK = (1<<TOIE0);

	sei();
	for(int i=0; song[i] != EOS; i++) {
		tone = song[i];
		_delay_ms(300);
	}
	cli();
 }

 void buzzer_downVOL_init(void) {
	DDRB |= (1<<4);
	TCCR0 = (1<<CS02);
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01);

	for(int i=0; song[i] != EOS; i++) {
		OCR0 = (256 - f_table[song[i]]) * 0.3 + f_table[song[i]];
		_delay_ms(300);
	}
 }