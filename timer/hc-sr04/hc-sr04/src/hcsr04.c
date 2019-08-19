/*
 * hcsr04.c
 *
 * Created: 2019-08-19 오전 12:28:52
 *  Author: yeong
 */ 

 #include "hcsr04.h"

 volatile int toggle;
 volatile int distance;
 uint8_t buf[128];

 ISR(INT4_vect) 
 {
	if(toggle == 0) {
		toggle = 1;
		distance = 0;
		TCNT1 = 0;
		TCCR1B |= (1<<CS10);
	}
	else {
		toggle = 0;
		TCCR1B &= ~(1<<CS10);
		sprintf(buf, "dist: %dcm", distance);
		i2c_lcd_string(0, 0, buf);
	}
 }

 ISR(TIMER1_COMPA_vect) {
	distance += 1;
 }

 void hcsr04_init(void)
 {
	DDRD |= (1<<4);
	EICRB |= (1<<ISC40);
	EIMSK |= (1<<4);
	TCCR1B |= (1<<WGM13) | (1<<WGM12);
	TIMSK |= (1<<OCIE1A);
	ICR1 = 927;
	toggle = 0;
	distance = 0;
	i2c_lcd_init();
	sei();
 }

 void trg_pulse(void)
 {
	PORTD |= (1<<4);
	_delay_us(10);
	PORTD &= ~(1<<4);
 }