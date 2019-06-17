/*
 * rval.c
 *
 * Created: 2019-05-18 오후 10:06:00
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "interrupt.h"

extern FILE OUTPUT;
extern FILE INPUT;
extern int flag;
volatile int ch;

int main(void)
{
	stdin = &INPUT;
	stdout = &OUTPUT;
	int read = 0; 
	// int_init();
	// led_init();
	uart0_init();
	adc_init(ch); // can read ADC channel

    while (1) 
    {
		read = adc_read();
		printf("adc_value : %d\r\n", read);
		_delay_ms(1000);

		//if(flag) {
			//ch = (ch + 1) % 2;
			//adc_change_channel(ch);
			//flag = 0;
		//}
    }
}

