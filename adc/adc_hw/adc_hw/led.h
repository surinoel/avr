/*
 * led.h
 *
 * Created: 2019-05-18 오후 11:15:25
 *  Author: yeong
 */ 

#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void led_init(void);
void led_on(unsigned char led);
void led_blink(unsigned char led);

#endif /* LED_H_ */