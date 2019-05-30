/*
 * rtc_1s.c
 *
 * Created: 2019-05-30 오후 4:21:46
 * Author : yeong
 */ 

#include <avr/io.h>
#include "timer0.h"
#include "uart.h"

int main(void)
{
	DDRA = 0xff;
	timer0_ovf_init();
	rtc_init();

    while (1) 
    {
    }
}

