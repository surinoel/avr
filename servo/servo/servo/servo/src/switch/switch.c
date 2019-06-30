/*
 * switch.c
 *
 * Created: 2019-06-30 오후 3:45:41
 *  Author: yeong
 */ 

 #include "switch.h"

 #define OCR_MAX 150
 #define OCR_MIN 35

 ISR(INT4_vect)
 {
	_delay_ms(10);
	while(!(PINE & (1<<4)));
	_delay_ms(10);
	if(OCR3A - 5 >= OCR_MIN) {
		OCR3A -= 5;
	} 
	EIFR |= (1<<4);
 }

 ISR(INT5_vect) 
 {
	_delay_ms(10);
	while(!(PINE & (1<<5)));
	_delay_ms(10);
	if(OCR3A + 5 <= OCR_MAX) {
		OCR3A += 5;
	}
	EIFR |= (1<<5);
 }

 void switch_exti_init(void) 
 {
	EICRB |= (1<<ISC41) | (1<<ISC51);
	EIMSK |= (1<<INT4) | (1<<INT5);
	sei();
 }