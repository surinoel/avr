/*
 * keypad.h
 *
 * Created: 2019-05-19 오전 10:28:49
 *  Author: yeong
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

void keypad_init(void);
unsigned char keypad_scan(void);
unsigned char keypad_trans(void);
void print_keyvalue(unsigned char value); 
int keypad_check_push_time(unsigned char port, unsigned char port_num);

#endif /* KEYPAD_H_ */