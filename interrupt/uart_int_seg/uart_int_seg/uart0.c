/*
 * uart0.c
 *
 * Created: 2019-05-12 오후 4:31:32
 *  Author: yeong
 */ 

#include "uart0.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(uart0_receive, NULL, _FDEV_SETUP_READ);

/*
volatile char rxdata[4];
volatile char tmpdata[4];
volatile int idx;
volatile int flag;

ISR(USART0_RX_vect) {
	char tmp = UDR0;
	if(tmp >= '0' && tmp <= '9') {
		if(idx == 4) idx = 0;
		if(flag == 1) {
			tmpdata[idx++] = tmp - '0'; 
		}
		else {
			tmpdata[idx++] = tmp - '0';
			flag = 1;	
		}
	}
	else if(tmp == '\r'){
		idx = 0;
		flag = 0;
		memcpy(rxdata, tmpdata, sizeof(rxdata));
		memset(tmpdata, 0, sizeof(tmpdata));
	}
}
*/

volatile int rxdata;
volatile int tmpdata;
volatile int flag;

ISR(USART0_RX_vect) {
	char tmp = UDR0;
	if(tmp >= '0' && tmp <= '9') {
		if(flag == 1) {
			tmpdata = ((tmpdata * 10) % 10000 + (tmp - '0') % 10000) % 10000;
		}
		else {
			tmpdata = tmp - '0';
			flag = 1;
		}
	}
	else if(tmp == '\r'){
		flag = 0;
		rxdata = tmpdata;
	}
}

void uart0_init(void) {
	UBRR0H = 0x00;
	UBRR0L = 16;
	
	UCSR0A |= (1<<U2X0);
	UCSR0C |= 0x06;

	UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
}

void uart0_trasnmit(char data) {
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char uart0_receive(void) {
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}