/*
 * hc-sr04.c
 *
 * Created: 2019-08-18 오후 2:42:40
 * Author : yeong
 */ 

#include <avr/io.h>
#include "uart.h"
#include "hcsr04.h"

int main(void)
{
	uart0_init();
	hcsr04_init();

    while (1) 
    {
		trg_pulse();
		_delay_ms(60);	
    }
}