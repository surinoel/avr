/*
 * cds.c
 *
 * Created: 2019-05-22 오전 9:23:09
 * Author : yeong
 */ 

#include <avr/io.h>
#include "led.h"
#include "adc.h"
#include "uart.h"

int main(void)
{
	led_init();
	adc_init(0x00);
	uart0_init();

    while (1) 
    {
		cds_led_on(adc_read());
    }
}

