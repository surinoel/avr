/*
 * timer.c
 *
 * Created: 2019-06-15 오후 2:47:03
 *  Author: yeong
 */ 
 #include "timer.h"

 void timer3_pwm_init(void) 
 {
	DDRE |= (1<<PORTE3) | (1<<PORTE4) | (1<<PORTE5);
	TCCR3A |= (1<<COM3A1) | (1<<WGM31);
	TCCR3B |= (1<<WGM33) | (1<<WGM32) | (1<<CS12) | (1<<CS10);

	ICR3 = 1000;
 }