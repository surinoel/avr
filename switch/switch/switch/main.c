/*
 * switch.c
 *
 * Created: 2019-05-01 오전 12:04:56
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

char pattern[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

int main(void)
{
	DDRA = 0xff;
	DDRE &= ~((1<<4) | (1<<5));
	
	int idx = 0;
    
	while (1) 
    {	
		/*
		if((PINE & (1<<4)) == 0x00) {
			PORTA = 0xff;	
		}
		else {
			PORTA = 0x00;
		}
		*/
		/*
		if((PINE & (1<<4)) == 0x00) {
			_delay_ms(20);
			if(++idx==8) idx = 0;
			PORTA = pattern[idx];
			while((PINE & (1<<4)) == 0x00);	
		}
		else if((PINE & (1<<5)) == 0x00) {
			_delay_ms(20);
			if(--idx==-1) idx = 7;
			PORTA = pattern[idx];
			while((PINE & (1<<5)) == 0x00);
		}
		*/
    }
}

