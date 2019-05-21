/*
 * led.c
 *
 * Created: 2019-05-18 오후 11:15:15
 *  Author: yeong
 */ 

#include "led.h"

unsigned char pattern[8] = {0x01, 0x02, 0x04, 0x80, 0x10, 0x20, 0x40, 0x80};

void led_init(void) {
	DDRA = 0xff;
}

void led_on(unsigned char led) {
	PORTA = led;
}

void led_blink(unsigned char led) {
	PORTA = led;
	_delay_ms(500);
}