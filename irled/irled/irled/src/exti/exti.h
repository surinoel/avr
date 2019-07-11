/*
 * exti.h
 *
 * Created: 2019-07-07 오전 10:56:54
 *  Author: user
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include "uart.h"

void exti_init(void);
void print_receive_data(int);

#endif /* EXTI_H_ */