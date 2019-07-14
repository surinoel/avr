/*
 * irremote.h
 *
 * Created: 2019-07-14 오후 2:42:01
 *  Author: yeong
 */ 


#ifndef IRREMOTE_H_
#define IRREMOTE_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void exit2_init(void);
void print_receive_data(int repeat);


#endif /* IRREMOTE_H_ */