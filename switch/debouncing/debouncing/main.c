/*
 * debouncing.c
 *
 * Created: 2019-05-12 오전 1:52:18
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRA = 0xff;
    DDRB &= ~(1<<4);
	PORTB |= (1<<4);

	while (1) 
    {
		if(!(PINB & (1<<4))) {
			PORTA ^= 0xff;
		}
		_delay_ms(10);
    }
}

