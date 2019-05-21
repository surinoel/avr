/*
 * solution.c
 *
 * Created: 2019-05-14 오전 3:10:22
 *  Author: yeong
 */ 

#include "solution.h"

uint8_t pattern[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
uint8_t num[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
int fnd_sel[4] = {0x0E, 0x0D, 0x0B, 0x07};
int fnd_num[4];

// extern char rxdata[4];
extern int rxdata;

volatile int prev_state;
volatile int dir = 1;
int idx = 0;

ISR(INT4_vect) {
	_delay_ms(10);
	if(prev_state == 2) {
		dir = 1;		
	}
	prev_state = 1;
	while(!(PINE & (1<<4)));
	_delay_ms(10);
	EIFR |= (1<<4);
}

ISR(INT5_vect) {
	_delay_ms(10);
	if(prev_state == 1) {
		dir = -1;
	}
	prev_state = 2;
	while(!(PINE & (1<<5)));
	_delay_ms(10);
	EIFR |= (1<<5);
}

 void solution1(void) {
	int n = 1234;

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
 /*
 void solution2(void) {
	for(int n=0; n<=9999; n++) {
		fnd_num[3] = (n/1000)%10;
		fnd_num[2] = (n/100)%10;
		fnd_num[1] = (n/10)%10;
		fnd_num[0] = (n/1)%10;

		for(int i=0; i<4; i++) {
			PORTG = fnd_sel[i];
			PORTC = num[fnd_num[i]];
			_delay_ms(2);
			if(i%2) _delay_ms(1);
			// _delay_ms(2.5);
		}
	}
 }
 */
 /*
void solution3(void) {
	fnd_num[3] = rxdata[0];
	fnd_num[2] = rxdata[1];
	fnd_num[1] = rxdata[2];
	fnd_num[0] = rxdata[3];

	for(int i=0; i<4; i++) {
		PORTG = fnd_sel[i];
		PORTC = num[fnd_num[i]];
		_delay_ms(2);
	}
}
*/
void solution4(void) {
	fnd_num[3] = (rxdata/1000)%10;
	fnd_num[2] = (rxdata/100)%10;
	fnd_num[1] = (rxdata/10)%10;
	fnd_num[0] = (rxdata/1)%10;

	for(int i=0; i<4; i++) {
		PORTG = fnd_sel[i];
		PORTC = num[fnd_num[i]];
		_delay_ms(2);
	}
}

void solution5(void) {
	if(dir == 1) {
		if(++idx == 8) idx = 0;
		PORTA = pattern[idx];
		_delay_ms(500);
	}
	else {
		if(--idx == -1) idx = 7;
		PORTA = pattern[idx];
		_delay_ms(500);
	}	
}