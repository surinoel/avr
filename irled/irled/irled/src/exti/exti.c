/*
 * exti.c
 *
 * Created: 2019-07-07 오전 10:56:40
 *  Author: user
 */ 

#include "exti.h"

volatile int bcnt;
volatile unsigned long receiveData;

ISR(INT0_vect)
{
	int tcnt = TCNT0;
	int isOVF = TIFR & (1<<TOV0);
	
	// if(isOVF == 1) goto end;
	
	if(bcnt == 32) {
		if((tcnt > 201) && (tcnt < 221) && (isOVF == 0)) {
			receiveData = 0;
			bcnt = 0;
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
			}
			
			bcnt += 1;
		}
	}
	
	TCNT0 = 0;
	TIFR |= (1<<TOV0);	
}

void exti_init(void)
{
	EIMSK |= (1<<INT0);
	EICRA |= (1<<ISC01);
	sei();
}

void print_receive_data(int repeat)
{
	if(repeat == 1) {
		printf("Repeat... \r\n");
	}
	else {
		printf("0x%lX\r\n", receiveData);
	}
}