/*
 * testboard.c
 *
 * Created: 2019-05-04 오전 11:59:53
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

char pattern[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

int main(void)
{
	DDRE &= ~((1<<4) | (1<<5));
	DDRA = 0xff;

	int idx = 0;
	PORTA = 0x01;

	while(1) {
		if (!(PINE & (1<<4))) {
			_delay_ms(100);
			if(++idx == 8) idx = 0;
			PORTA = pattern[idx];
			while(!(PINE & (1<<4)));
		}
		else if (!(PINE & (1<<5))) {
			_delay_ms(100);
			if(--idx == -1) idx = 7;
			PORTA = pattern[idx];
			while(!(PINE & (1<<4)));
		}
	}		
}

