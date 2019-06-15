/*
 * time.h
 *
 * Created: 2019-06-09 오후 3:28:53
 *  Author: yeong
 */ 


#ifndef TIME_H_
#define TIME_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void timer1_pwm_init(void);
void buzzer_init(void);
void buzzer_downVOL_init(void);

#endif /* TIME_H_ */