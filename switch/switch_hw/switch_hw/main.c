/*
 * switch_hw.c
 *
 * Created: 2019-05-05 오후 8:05:31
 * Author : yeong
 */ 

#include "uart.h"
#include "solution.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(uart0_receive, NULL, _FDEV_SETUP_READ);

void init(void);

int main(void)
{
	init();
    while (1) 
    {
		// solve1();
		solve2();
		// solve3();
    }
}

void init(void) {
	srand(time(NULL));
	uart0_init();
	stdin = &INPUT;
	stdout = &OUTPUT;

	DDRA = 0xff;
	DDRB &= ~((1<<4) | (1<<5));
	PORTB |= ((1<<4) | (1<<5));
}
