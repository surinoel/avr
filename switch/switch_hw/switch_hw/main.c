/*
 * switch_hw.c
 *
 * Created: 2019-05-05 오후 8:05:31
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>
#include "uart.h"

FILE OUTPUT = FDEV_SETUP_STREAM(uart0_trasnmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(uart0_receive, NULL, _FDEV_SETUP_READ);

void solve1(void) {
	int x = rand()%40 + 10;
	printf("goal = %d\r\n", x);

	int num = 0;
	while(1) {
		if(num > x) {
			printf("fail\r\n");
			break;
		}
		else if(num == x) {
			PORTA = 0xff;
			printf("success\r\n");
			_delay_ms(5000);
			break;
		}

		if(!(PINB & (1<<4))) {
			_delay_ms(200);
			num += 1;
			printf("num = %d\r\n", num);
			while(!(PINB & (1<<4)));
		}
		else if(!(PINB & (1<<5))) {
			_delay_ms(200);
			num += 2;
			printf("num = %d\r\n", num);
			while(!(PINB & (1<<5)));
		}
	}
}

#define N 50

int ans[50];
int from[50];
int queue[50];
int idx;
int head, tail;

int is_empty() {
	return head == tail;
}

int is_full() {
	return (head == ((tail == N - 1) ? 0 : (tail + 1)));
}

int enqueue(int data) {
	if(is_full()) {
		printf("queue overflow\r\n");
		return -1;
	}
	queue[tail] = data;
	if(++tail == N) tail = 0;
	return 0;
}

int dequeue(void) {
	if(is_empty()) {
		printf("queue underflow\r\n");
		return -1;
	}
	int data = queue[head];
	queue[head] = 0;
	if(++head == N) head = 0;
	return data;
}

void go(int k) {
	if(k==-1) {
		return;
	}
	go(from[k]);
	ans[idx++] = k;
}

void solve2(void) {
	int goal = rand()%40 + 10;
	printf("goal = %d\r\n", goal);
	int x = 0;
	head = tail = 0;
	memset(queue, 0, sizeof(queue));
	memset(from, -1, sizeof(from));
	enqueue(x + 1);
	enqueue(x + 2);
	from[x+1] = x;
	from[x+2] = x;
	
	while(!is_empty()) {
		int t = dequeue();
		
		if(t==goal) {
			break;
		}

		if(from[t+1] == -1) {
			from[t+1] = t;
			enqueue(t+1);
		}
		if(from[t+2] == -1) {
			from[t+2] = t;
			enqueue(t+2);
		}
	}

	memset(ans, 0, sizeof(ans));
	idx = 0;
	go(goal);
	for(int i=0; i<idx; i++) {
		printf("%d ", ans[i]);
	}
	printf("\r\n");

	int nidx = 0;
	int num = 0;
	bool ok = true;
	while(1) {
		if(num > goal || nidx > idx || !ok) {
			printf("fail\r\n");
			break;
		}
		else if(num == goal) {
			PORTA = 0xff;
			printf("success\r\n");
			_delay_ms(5000);
			break;
		}

		if(!(PINB & (1<<4))) {
			_delay_ms(200);
			num += 1;
			if(ans[++nidx] != num) {
				ok = false;
			}
			else {
				printf("num = %d\r\n", num);
			}
			while(!(PINB & (1<<4)));
		}
		else if(!(PINB & (1<<5))) {
			_delay_ms(200);
			num += 2;
			if(ans[++nidx] != num) {
				ok = false;
			}
			else {
				printf("num = %d\r\n", num);
			}
			while(!(PINB & (1<<5)));
		}
	}
}

int main(void)
{
	srand(time(NULL));
	uart0_init();
	stdin = &INPUT;
	stdout = &OUTPUT;

	DDRA = 0xff;
	DDRB &= ~((1<<4) | (1<<5));
	PORTB |= ((1<<4) | (1<<5));

    while (1) 
    {
		PORTA = 0x00;
		solve2();
    }
}

