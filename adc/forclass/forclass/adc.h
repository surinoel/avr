﻿/*
 * adc.h
 *
 * Created: 2019-05-19 오후 3:15:52
 *  Author: yeong
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"

void init_adc(unsigned char ch);
void adc_change_channel(unsigned char ch);
int read_adc(void);
void print_adc_value(int adc_value);

#endif /* ADC_H_ */