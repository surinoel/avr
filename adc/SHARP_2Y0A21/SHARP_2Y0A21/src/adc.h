/*
 * adc.h
 *
 * Created: 2019-05-18 오후 10:15:03
 *  Author: yeong
 */ 

#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

void adc_init(unsigned char ch);
void adc_change_channel(unsigned char ch);
int adc_read(void);

#endif /* ADC_H_ */