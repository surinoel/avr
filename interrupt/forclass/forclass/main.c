/*
 * forclass.c
 *
 * Created: 2019-05-12 오후 2:09:15
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#include "uart0.h"

uint8_t num[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
int fnd_sel[4] = {0x01, 0x02, 0x04, 0x08};
int fnd_num[4];

extern FILE OUTPUT;
extern FILE INPUT;

int main(void) {	
	stdin = &INPUT;
	stdout = &OUTPUT;

	uart0_init();
	DDRC = 0xff;
	DDRG |= 0x0f;

	int n = 1234;
	while(1) {
		fnd_num[3] = (n/1000)%10;
		fnd_num[2] = (n/100)%10;
		fnd_num[1] = (n/10)%10;
		fnd_num[0] = (n/1)%10;

		for(int i=0; i<4; i++) {
			PORTG = fnd_sel[i];
			PORTC = num[fnd_num[i]];
			_delay_ms(2);
		}
	}
}
