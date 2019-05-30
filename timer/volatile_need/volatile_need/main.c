/*
 * volatile_need.c
 *
 * Created: 2019-05-28 오후 4:46:54
 * Author : yeong
 */ 

#include <avr/io.h>
#include "uart.h"
#include "timer0.h"

int main(void)
{
    timer0_ovf_init();
	uart0_init();

    while (1) 
    {

    }
}

