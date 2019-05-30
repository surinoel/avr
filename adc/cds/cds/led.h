/*
 * led.h
 *
 * Created: 2019-05-22 오전 10:12:03
 *  Author: yeong
 */ 

#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include "adc.h"
#include "uart.h"

void led_init(void);
void cds_led_on(int adc_read_val);

#endif /* LED_H_ */