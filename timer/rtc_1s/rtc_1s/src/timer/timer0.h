/*
 * timer0.h
 *
 * Created: 2019-05-28 오후 4:48:04
 *  Author: yeong
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include "uart.h"

void timer0_ovf_init(void);
void timer0_comp_init(void);
void rtc_init(void);

#endif /* TIMER0_H_ */