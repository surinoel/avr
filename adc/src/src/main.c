/*
 * src.c
 *
 * Created: 2019-05-26 오후 11:10:44
 * Author : yeong
 */ 

// #include <avr/io.h>
#include "avr/io.h"
#include "adc.h"
#include "uart.h"

int main(void)
{
	uart_init();
	adc_init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

