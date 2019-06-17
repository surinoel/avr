/*
 * adc_rval_timer.c
 *
 * Created: 2019-06-16 오후 3:22:46
 * Author : yeong
 */ 

#include <avr/io.h>
#include "adc.h"

int main(void)
{
	uart0_init();
	adc_init(1);
		
    while (1) 
    {
		print_adc_value(adc_read());
    }
}

