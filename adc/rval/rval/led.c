/*
 * led.c
 *
 * Created: 2019-05-18 오후 11:15:15
 *  Author: yeong
 */ 

#include "led.h"

void led_init(void) {
	DDRA = 0xff;
}

void led_blink(unsigned char led) {
	PORTA = led;
	_delay_ms(500);
}