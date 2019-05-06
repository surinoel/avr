/*
* queue.c
*
* Created: 2019-05-07 오전 1:11:54
*  Author: yeong
*/ 

#include "queue.h"

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