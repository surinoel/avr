/*
 * rval_rand_seed.c
 *
 * Created: 2019-05-22 오후 6:46:48
 * Author : yeong
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "adc.h"
#include "uart.h"

int main(void)
{
	adc_init(0x00);
	uart0_init();
	srand(adc_read());
    
	while (1) 
    {
		for(;;) {
			printf("%d\r\n", rand()%40+1);
		}
    }
}

