/*
 * hcsr04.h
 *
 * Created: 2019-08-19 오전 12:29:01
 *  Author: yeong
 */ 


#ifndef HCSR04_H_
#define HCSR04_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "clcd.h"

void hcsr04_init(void);
void trg_pulse(void);

#endif /* HCSR04_H_ */