/*
 * forclass.c
 *
 * Created: 2019-05-19 오후 2:35:19
 * Author : yeong
 */ 

#include <avr/io.h>
#include "adc.h"
#include "interrupt.h"

extern volatile int flag;
extern int cur_ch;

int main(void)
{
	init_adc(0x00);
	int4_init();
	uart0_init();
    while (1) 
    {
		print_adc_value(read_adc());
		if(flag) {
			// cur_ch = (cur_ch == 1) ? 2 : 1;
			cur_ch = (cur_ch + 1) % 2;
			adc_change_channel(cur_ch);
			flag = 0;
		}
    }
}

