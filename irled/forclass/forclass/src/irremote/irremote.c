/*
 * irremote.c
 *
 * Created: 2019-07-14 오후 2:41:52
 *  Author: yeong
 */ 

#include "irremote.h"
#include "uart.h"

volatile int bcnt;
volatile unsigned long receiveData;

ISR(INT2_vect)
{
	int tcnt = TCNT0;
	int isOVF = TIFR & (1<<TOV0);

	if(bcnt == 32) {
		if((tcnt > 201) && (tcnt < 221) && (isOVF == 0)) {
			bcnt = 0;
			receiveData = 0;
		}
		else if((tcnt > 166) && (tcnt < 186) && (isOVF == 0)) {
			print_receive_data(1);
		}
		else {
			bcnt = 32;
		}
	}
	else {
		if(tcnt > 40 || (isOVF != 0)) {
			bcnt = 32;
		}
		else {
			if(tcnt > 26) { 
				receiveData = (receiveData << 1) + 1;
			}
			else {
				receiveData = (receiveData << 1);
			}

			if(bcnt == 31) {
				print_receive_data(0);
				_delay_ms(50);
				EIFR |= (1<<INTF2);		
			}

			bcnt += 1;
		}
	}

	TIFR |= (1<<TOV0);
	TCNT0 = 0;
}

void exit2_init(void)
{
	EIMSK |= (1<<INT2);
	EICRA |= (1<<ISC21);
	sei();
}

void print_receive_data(int repeat)
{
	if(repeat) {
		printf("repeat...\r\n");
	}
	else {
		printf("0x%lX\r\n", receiveData);
	}
}