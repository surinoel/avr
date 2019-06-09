/*
 * led.c
 *
 * Created: 2019-06-07 오후 6:54:19
 *  Author: yeong
 */ 

 #include "led.h"

 void led_init(void)
 {
	DDRA = 0xff;
 }

 void led_blink(int mstime)
 {
	PORTA ^= 0xff;
	delay_ms(mstime);
 }