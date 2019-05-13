/*
 * interrupt.c
 *
 * Created: 2019-05-11 오전 1:26:13
 * Author : yeong
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRA = 0xff;

    while (1) 
    {
		volatile int i, j;
		PORTA = 0xff;
		for(i=0; i<1000; i++) for(j=0; j<1000; j++) {}
		PORTA = 0x00;
		for(i=0; i<1000; i++) for(j=0; j<1000; j++) {}
    }
}

