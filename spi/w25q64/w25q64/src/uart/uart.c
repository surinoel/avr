/*
 * uart.c
 *
 * Created: 2019-04-29 오후 7:27:25
 *  Author: yeong
 */ 
#include "uart.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, uart0_receive, _FDEV_SETUP_READ);

volatile int flag;
volatile int rxdata;

ISR(USART0_RX_vect) {
	unsigned char tmp = UDR0;
	if(tmp >= '0' && tmp <= '9') {
		if(flag) {
			rxdata = rxdata * 10 + tmp - '0';
		}
		else {
			rxdata = tmp - '0';
			flag = 1;
		}
	}
	else if(tmp == '\r') {
		flag = 0;
	}
}

 void uart0_init(void) {
	 UBRR0H = 0x00;
	 UBRR0L = 16;
	 
	 UCSR0A |= (1<<U2X0);
	 UCSR0C |= 0x06;

	 UCSR0B |= (1<<RXEN0) | (1<<TXEN0);

	 stdin = &INPUT;
	 stdout = &OUTPUT;
 }

 void uart0_trasnmit(char data) {
	 while(!(UCSR0A & (1 << UDRE0)));
	 UDR0 = data;
 }

 unsigned char uart0_receive(void) {
	 while(!(UCSR0A & (1 << RXC0)));
	 return UDR0;
 }

 void uart0_rx_int_init(void) {
	UCSR0B |= (1 << RXCIE0);
	sei();
 }