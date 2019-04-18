/*
 * uart.c
 *
 * Created: 2019-04-19 오전 1:49:12
 * Author : 유영재
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;
    while (1) 
    {
		for(int i=0; i<(1<<8); i++) {
			PORTA = i;
			_delay_ms(500);
		}
    }
}

