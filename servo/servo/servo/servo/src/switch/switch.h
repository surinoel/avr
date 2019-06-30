/*
 * switch.h
 *
 * Created: 2019-06-30 오후 3:45:51
 *  Author: yeong
 */ 

#ifndef SWITCH_H_
#define SWITCH_H_

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

void switch_exti_init(void);

#endif /* SWITCH_H_ */