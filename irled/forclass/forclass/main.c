/*
 * forclass.c
 *
 * Created: 2019-07-14 오후 2:40:25
 * Author : yeong
 */ 

#include <avr/io.h>
#include "uart.h"

extern volatile int bcnt;

int main(void)
{
	uart0_init();
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	exit2_init();
	bcnt = 32;

	while (1) 
    {
    }
}

