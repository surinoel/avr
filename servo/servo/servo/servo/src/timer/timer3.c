/*
 * timer3.c
 *
 * Created: 2019-06-30 오후 3:45:21
 *  Author: yeong
 */ 
 
 #include "timer3.h"

 void timer3_pwm_init(void) 
 {
	DDRE |= (1<<3);
	TCCR3A |= (1<<COM3A1) | (1<<WGM31);
	TCCR3B |= (1<<WGM33) | (1<<WGM32) | (1<<CS32);
	ICR3 = 1250;
	OCR3A = 93;
 }

 void servo_control(void)
 {
	OCR3A = 35;
	_delay_ms(1000);
	OCR3A = 93;
	_delay_ms(1000);
	OCR3A = 150;
	_delay_ms(1000);
 }