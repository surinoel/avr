/*
 * uart_int_seg.c
 *
 * Created: 2019-05-19 오후 1:40:03
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

extern volatile int rxdata;

uint8_t num[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
int fnd_sel[4] = {0x0E, 0x0D, 0x0B, 0x07};
int fnd_num[4];

int main(void)
{
	DDRC = 0xff;
	DDRG = 0x0f;

	uart0_init();
	uart0_rx_int_init();

    while (1) 
    {
		fnd_num[3] = (rxdata/1000)%10;
		fnd_num[2] = (rxdata/100)%10;
		fnd_num[1] = (rxdata/10)%10;
		fnd_num[0] = (rxdata/1)%10;

		for(int i=0; i<4; i++) {
			PORTG = fnd_sel[i];
			PORTC = num[fnd_num[i]];
			_delay_ms(2);
		}
    }
}

