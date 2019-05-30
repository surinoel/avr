/*
 * adc_interrupt.c
 *
 * Created: 2019-05-27 오후 2:51:56
 * Author : yeong
 */ 

#include <avr/io.h>
#include "adc.h"
#include "uart.h"

int main(void)
{
    uart0_init();
	adc_init(0x01);
	adc_interrupt_init();

    while (1) 
    {
		
    }
}

