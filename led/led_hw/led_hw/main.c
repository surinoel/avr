/*
 * led_hw.c
 *
 * Created: 2019-04-29 오후 7:02:26
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "uart.h"

char buf[256];

FILE OUTPUT
= FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT
= FDEV_SETUP_STREAM(NULL, uart0_receive, _FDEV_SETUP_READ);

int main(void)
{
	uart0_init();
	stdout = &OUTPUT;
	stdin = &INPUT;
	DDRA = 0xff;

    while (1) 
    {
		// 1번
		/*
 		for(int i=1; i<4; i++) {
			PORTA = (1<<(3-i)) | (1<<(4+i));
			_delay_ms(1000);
		}

		for(int i=1; i<4; i++) {
			PORTA = (1<<i) | (1<<(7-i));
			_delay_ms(1000);  
		}
		*/		
		// 2번
		/*
		PORTA = 0x00;
		for(int i=0; i<8; i++) {
			uint8_t prev = PORTA;
			for(int j=0; j<8-i; j++) {
				uint8_t tmp = (1<<j);
				PORTA = prev | tmp;
				_delay_ms(200);
			}
		}
		*/
		// 3번
		/*
		PORTA = 0x00;
		for(int i=0; i<8; i++) {
			uint8_t prev = PORTA;
			for(int j=7; j>=i; j--) {
				uint8_t tmp = (1<<j);
				PORTA = prev | tmp;
				_delay_ms(200);
			}
		}
		*/		
		// 4번
		
		PORTA = 0x00;
		scanf("%s", buf);
		if(!strcmp(buf, "right")) {
			for(int i=0; i<8; i++) {
				uint8_t prev = PORTA;
				for(int j=0; j<8-i; j++) {
					uint8_t tmp = (1<<j);
					PORTA = prev | tmp;
					_delay_ms(200);
				}
			}
		}
		else if(!strcmp(buf, "left")) {
			for(int i=0; i<8; i++) {
				uint8_t prev = PORTA;
				for(int j=7; j>=i; j--) {
					uint8_t tmp = (1<<j);
					PORTA = prev | tmp;
					_delay_ms(200);
				}
			}
		}
    }
}

