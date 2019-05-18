/*
 * uart0.h
 *
 * Created: 2019-05-12 오후 4:31:44
 *  Author: yeong
 */ 

#ifndef UART0_H_
#define UART0_H_

#include <avr/interrupt.h>
#include <string.h>
#include <avr/io.h>
#include <stdio.h>

void uart0_init(void);
void uart0_trasnmit(char data);
unsigned char uart0_receive(void);

#endif /* UART0_H_ */