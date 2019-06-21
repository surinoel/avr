/*
 * ATS75D8.c
 *
 * Created: 2019-06-16 오후 4:31:43
 * Author : yeong
 */ 

#include <avr/io.h>
#include "i2c.h"
#include "uart.h"
#include "segment.h"

int main(void)
{
	fnd_init();
	uart0_init();
	i2c_init();
	uint8_t ht, lt;
	uint16_t temp;
	while (1) 
	{
		while(i2c_readReg(0x98, 0x00, &ht, &lt) == 0) {
			temp = (ht<<8) | lt;
			printf("temp:%d\r\n",temp);
		}
	}
}

