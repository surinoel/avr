/*
 * led.c
 *
 * Created: 2019-06-09 오후 2:53:35
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