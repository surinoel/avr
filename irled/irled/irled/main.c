/*
 * irled.c
 *
 * Created: 2019-07-07 오전 10:41:52
 * Author : user
 */ 

#include <avr/io.h>
#include "uart.h"
#include "exti.h"

extern volatile int bcnt;

int main(void)
{
    uart0_init();
	TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02);
	exti_init();
	bcnt = 32;
    while (1) 
    {
    }
}

