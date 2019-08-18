/*
 * tinyRTC_study.c
 *
 * Created: 2019-08-18 오후 4:12:22
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "tinyRTC.h"
#include "uart.h"

int main(void)
{
	uart0_init();
	tinyRTC_init();
	// tinyRTC_setup(0, 26, 17, 1, 18, 8, 19);
 
	while (1) 
    {
		tinyRTC_read();
    }
}

