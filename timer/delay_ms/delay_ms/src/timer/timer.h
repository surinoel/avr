/*
 * timer.h
 *
 * Created: 2019-06-02 오후 2:39:52
 *  Author: yeong
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include "uart.h"

void timer0_ovf_init(void);
void delay_ms(int mstime);

#endif /* TIMER_H_ */