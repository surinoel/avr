/*
 * SHARP_2Y0A21.c
 *
 * Created: 2019-08-04 오후 12:28:29
 * Author : yeong
 */ 

#include <avr/io.h>
#include "uart.h"
#include "adc.h"

float calc_distance(float volt)
{
	float val = 0.04 * volt;
	return (1/val);
}

int main(void)
{
	float volt, dist;
	uart0_init();
	adc_init(0x01);
	/* Replace with your application code */
	while (1) 
	{
		volt = 5.0*adc_read()/1024;
		// printf("voltage:%f\r\n", 5.0*adc_read()/1024);
		dist = calc_distance(volt);
		if(dist>=10 && dist<=80) {
			printf("dist:%f\r\n", dist);
		}
	}
}
