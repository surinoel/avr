/*
 * timer.c
 *
 * Created: 2019-06-15 오후 2:47:03
 *  Author: yeong
 */ 
 #include "timer.h"

 void timer1_pwm_init(void) 
 {
	DDRB |= (1<<PORTB5) | (1<<PORTB6) | (1<<PORTB7);
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1C1) | (1<<WGM11);
	TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS11);

	ICR1 = 1000;
 }