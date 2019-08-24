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

 volatile int start, end, dist;
 volatile int flag;

 ISR(INT4_vect) 
 {
	if(EICRB == 3) {
		start=TCNT1;
		EICRB = 2;
	}
	else {
		end = TCNT1;
		EICRB = 3;
		dist = (int)((float)(end-start)/14.5);
		flag = 1;
	}
 }

 void hcsr04_init(void)
 {
	DDRB |= (1<<5); // trigger PWM핀
	TCCR1A = 0x82;
	TCCR1B = 0x1B;
	OCR1A = 2;
	ICR1 = 12499;
	
	EICRB = 3;
	EIMSK = 0x10;
	EIFR = 0x10;
	flag = 0;
	sei();
 }