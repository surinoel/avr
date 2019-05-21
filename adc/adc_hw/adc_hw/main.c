/*
 * adc_hw.c
 *
 * Created: 2019-05-21 오후 2:15:35
 * Author : yeong
 */ 

#include <avr/io.h>
#include "adc.h"
#include "uart.h"

extern unsigned char pattern[8];
unsigned char adc_led_pattern[1024];

int main(void)
{
	led_init();
	uart0_init();
	adc_init(0x01);
	int adc_read_val;
	
	for(int i=0; i<1024; i++) {
		adc_led_pattern[i] = pattern[i/(1024/8)];	
	}

    while (1) 
    {
		adc_read_val = adc_read();
		led_on(adc_led_pattern[adc_read_val]);
		_delay_ms(1);
    }
}

