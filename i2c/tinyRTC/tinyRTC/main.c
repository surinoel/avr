/*
 * tinyRTC.c
 *
 * Created: 2019-08-11 오후 4:19:14
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "tinyRTC.h"

int main(void)
{
	uart0_init();
	tinyRTC_init();
    /* Replace with your application code */ 
	tinyRTC_setup(00, 10, 17, 1, 11, 8, 19);
	tinyRTC_set_date();
	tinyRTC_read_date();
	_delay_ms(2000);
	tinyRTC_read_date();
    while (1) 
    {
		// tinyRTC_read_date();
    }
}

