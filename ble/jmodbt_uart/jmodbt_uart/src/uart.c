/*
 * uart.c
 *
 * Created: 2019-04-29 오후 7:27:25
 *  Author: yeong
 */ 
#include "uart.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart1_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, uart1_receive, _FDEV_SETUP_READ);

volatile int flag;
volatile int rxdata;

ISR(USART1_RX_vect) {
	unsigned char tmp = UDR1;
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

 void uart1_init(void) {
	 UBRR1H = 0x00;
	 UBRR1L = 16;
	 
	 UCSR1A |= (1<<U2X1);
	 UCSR1C |= 0x06;

	 UCSR1B |= (1<<RXEN1) | (1<<TXEN1);

	 stdin = &INPUT;
	 stdout = &OUTPUT;
 }

 void uart1_trasnmit(char data) {
	 while(!(UCSR1A & (1 << UDRE1)));
	 UDR1 = data;
 }

 unsigned char uart1_receive(void) {
	 while(!(UCSR1A & (1 << RXC1)));
	 return UDR1;
 }

 void uart1_rx_int_init(void) {
	UCSR1B |= (1 << RXCIE1);
	sei();
 }