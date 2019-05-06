/*
 * solution.h
 *
 * Created: 2019-05-07 오전 1:10:29
 *  Author: yeong
 */ 

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "uart.h"
#include "queue.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void solve1(void);
void solve2(void);
void solve3(void);

extern int ans[50];
extern int from[50];
extern int queue[50];
extern int idx;
extern int head;
extern int tail;

#endif /* SOLUTION_H_ */