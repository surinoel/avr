/*
 * queue.h
 *
 * Created: 2019-05-07 오전 1:12:03
 *  Author: yeong
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include "uart.h"

int is_empty();
int is_full();
int enqueue(int data);
int dequeue(void);
void go(int k);

#endif /* QUEUE_H_ */