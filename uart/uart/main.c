/*
 * uart.c
 *
 * Created: 2019-04-19 오전 1:49:12
 * Author : 유영재
 */ 
#define F_CPU 16000000UL
#include <avr/io.h> 
#include <util/delay.h>
#include <stdio.h>

void uart0_init(void);
void uart0_trasnmit(char data);
unsigned char uart0_receive(void);

FILE OUTPUT 
		= FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT
		= FDEV_SETUP_STREAM(NULL, uart0_receive, _FDEV_SETUP_READ);

int main(void)
{
	uart0_init();
	stdout = &OUTPUT;
	stdin = &INPUT;

	while (1) {
		_delay_ms(100);		
		printf("hello world\r\n");
	}
}

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
