/*
 * forclass.c
 *
 * Created: 2019-05-12 오후 2:09:15
 * Author : yeong
 */ 
#include "uart0.h"
#include "solution.h"

extern FILE OUTPUT;
extern FILE INPUT;

int main(void) {	
	stdin = &INPUT;
	stdout = &OUTPUT;
	uart0_init();

	DDRA = 0xff;
	DDRC = 0xff;
	DDRG |= 0x0f;
	PORTE |= ((1<<4) | (1<<5));
	EIMSK |= ((1<<4) | (1<<5));
	EICRB |= ((1<<ISC41) | (1<<ISC51));
	sei();

	while(1) {
		// solution1();
		// solution2();
		// solution3();
		 solution4();
		// solution5();
	}
}
