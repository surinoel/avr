/*
 * jmodbt_uart.c
 *
 * Created: 2019-08-24 오후 12:53:19
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

int main(void)
{
	uart1_init();
    /* Replace with your application code */
    while (1) 
    {
		printf("hello ble!\r\n");
		_delay_ms(300);
    }
}