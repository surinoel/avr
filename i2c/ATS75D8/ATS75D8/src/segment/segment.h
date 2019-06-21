/*
 * segment.h
 *
 * Created: 2019-06-22 오전 1:00:32
 *  Author: yeong
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void fnd_init(void);
void display_fnd(uint16_t value);

#endif /* SEGMENT_H_ */