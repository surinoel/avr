/*
 * w25q64_readwrite.c
 *
 * Created: 2019-07-28 오후 4:47:14
 * Author : yeong
 */ 
#define	F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "spi.h"
#include "w25q64.h"

uint8_t wData[0x100];
uint8_t rData[0x100];
extern uint8_t *arr;
int main(void)
{
	spi_init();
	uart0_init();

	// CS init
	w25q_ss_pin_init();

	for(int i=0; i<0x100; i++) {
		wData[i] = i;
	}
	
	erase_block(0);
	_delay_ms(500);
	w25q_page_write(0, wData, 0x100);
	_delay_ms(5);
	/*
	for(int i=0; i<0x100; i++) {
		rData[i] = w25q_read(i);
		printf("%02X:%d\r\n", i, rData[i]);
		_delay_ms(100);
	}
	*/
	
	w25q_fast_read(0x00, 0x100);
	for(int i=0; i<0x100; i++) {
		printf("%02X:%d\r\n", i, arr[i]);
		_delay_ms(100);		
	}
	
    while (1) 
    {
		
    }
}