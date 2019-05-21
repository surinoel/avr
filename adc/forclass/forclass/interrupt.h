/*
 * interrupt.h
 *
 * Created: 2019-05-19 오후 4:33:19
 *  Author: yeong
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h> 
#include <avr/interrupt.h>

void int4_init(void);

#endif /* INTERRUPT_H_ */