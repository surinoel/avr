/*
 * adc_hw_2.c
 * 연습문제 2
 * Created: 2019-05-21 오후 2:34:31
 * Author : yeong
 */ 

#include <avr/io.h>
#include "adc.h"
#include "uart.h"
#include "interrupt.h"

extern int cur_ch;

int main(void)
{
	int cnt = 0;
	int4_init();
	uart0_init();
	adc_init(0x01);
	
    while (1) 
    {
		print_both_adc_value(cur_ch, adc_read());
		_delay_ms(30);
		if(++cnt == 50) {
			cur_ch = 1 ? cur_ch == 0 : cur_ch == 1;
			adc_change_channel(cur_ch);
			cnt = 0;
		}
    }
}

