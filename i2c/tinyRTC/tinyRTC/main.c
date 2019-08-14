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
<<<<<<< HEAD
    /* Replace with your application code */ 
	//tinyRTC_setup(00, 33, 18, 1, 11, 8, 19);
	//tinyRTC_set_date();
	//tinyRTC_read_date();
	//_delay_ms(2000);
	//tinyRTC_read_date();
    while (1) 
    {
		tinyRTC_read_date();
    }
=======

	tinyRTC_setup(00, 10, 17, 1, 11, 8, 19);
	tinyRTC_set_date();
	tinyRTC_read_date();
	_delay_ms(2000);
	tinyRTC_read_date();
	
	while (1) 
	{
		// tinyRTC_read_date();
	}
>>>>>>> b0873a3bb0c3d936a36b24aa992f76d70a4dae64
}
