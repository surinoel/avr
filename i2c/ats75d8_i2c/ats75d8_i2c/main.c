/*
 * ats75d8_i2c.c
 *
 * Created: 2019-06-30 오후 1:53:31
 * Author : yeong
 */ 

#define	F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "i2c_master.h"
#include "uart.h"

#define DEVADDR 0x98

int main(void)
{
	uart0_init();
	DDRD &= ~((1<<PORTD0) | (1<<PORTD1));
	PORTD |= ((1<<PORTD0) | (1<<PORTD1));
	SFIOR &= ~(1<<PUD);

	i2c_init();
	uint8_t data = 0x00;
	while(i2c_writeReg(DEVADDR, 0x01, &data, 1));
	while (1) 
    {
		uint8_t tempdata[2];
		while(i2c_readReg(DEVADDR, 0x00, &tempdata, 2));
		printf("%d, %d\r\n", tempdata[0], tempdata[1]);
		_delay_ms(300);
    }
}

