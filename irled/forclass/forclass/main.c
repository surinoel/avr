/*
 * forclass.c
 *
 * Created: 2019-07-07 오후 4:37:26
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include <avr/interrupt.h>
#include <avr/io.h>

void exit_init(void);

volatile int bcnt = 32;
volatile unsigned long receiveData;

ISR(INT0_vect)
{
	int tcnt = TCNT0;
	int isOVF = TIFR & (1<<TOV0);

	if(isOVF > 0) goto end;
	
	if(bcnt == 32) {
		if(tcnt > 205 && tcnt < 215) {
			receiveData = 0;
			bcnt = 0;		
		}
		else if(tcnt > 175 && tcnt < 185) {
			print_receiveData(1);
		}
		else {
			goto end;
		}
	}
	else {
		if(tcnt > 12 && tcnt < 22) {
			receiveData = (receiveData << 1);
			bcnt += 1;
		} 
		else if(tcnt > 30 && tcnt < 40) {
			receiveData = (receiveData << 1) + 1;
			bcnt += 1;
		}
		else {
			bcnt = 32;
			goto end;
		}

		if(bcnt == 31) {
			print_receiveData(0);
		}
	}

end:
	TCNT0 = 0;
	TIFR |= (1<<TOV0);	 
}

void print_receiveData(int isrep) 
{
	if(isrep == 0) {
		printf("0x%lld\r\n", receiveData);
	}
	else {
		printf("repeat\r\n");
	}
}

int main(void)
{
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00);

    while (1) 
    {
    }
}

void exit_init(void)
{
	EICRA |= (1<<ISC01);
	EIMSK |= (1<<INT0);
	sei();
}
