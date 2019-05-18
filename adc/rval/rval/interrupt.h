/*
 * interrupt.h
 *
 * Created: 2019-05-18 오후 11:09:10
 *  Author: yeong
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "adc.h"

void int_init(void);

#endif /* INTERRUPT_H_ */