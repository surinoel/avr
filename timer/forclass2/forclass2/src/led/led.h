/*
 * led.h
 *
 * Created: 2019-06-09 오후 2:53:42
 *  Author: yeong
 */ 

#ifndef LED_H_
#define LED_H_

#include "timer.h"

void led_init(void);
void led_blink(int mstime);

#endif /* LED_H_ */