/*
 * uart0.c
 *
 * Created: 2019-05-12 오후 4:31:32
 *  Author: yeong
 */ 

 #include "uart0.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(uart0_receive, NULL, _FDEV_SETUP_READ);

 void uart0_init(void) {
	 UBRR0H = 0x00;
	 UBRR0L = 207;
	 
	 UCSR0A |= (1<<U2X0);
	 UCSR0C |= 0x06;

	 UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
 }

 void uart0_trasnmit(char data) {
	 while(!(UCSR0A & (1 << UDRE0)));
	 UDR0 = data;
 }

 unsigned char uart0_receive(void) {
	 while(!(UCSR0A & (1 << RXC0)));
	 return UDR0;
 }