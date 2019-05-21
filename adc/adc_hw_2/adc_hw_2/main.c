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

extern volatile int flag;
extern int cur_ch;

int main(void)
{
	int4_init();
	uart0_init();
	adc_init(0x01);
	
    while (1) 
    {
		print_adc_value(adc_read());
		if(flag) {
			cur_ch = 2 ? cur_ch == 1 : cur_ch == 2;
			adc_change_channel(cur_ch);
		}
    }
}

