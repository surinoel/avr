/*
 * timer3.h
 *
 * Created: 2019-06-30 오후 3:45:34
 *  Author: yeong
 */ 


#ifndef TIMER3_H_
#define TIMER3_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

 void timer3_pwm_init(void);

#endif /* TIMER3_H_ */