/*
 * solution.c
 *
 * Created: 2019-05-07 오전 1:10:19
 *  Author: yeong
 */ 
 
#include "solution.h"

void solve1(void) {
	PORTA = 0x00;
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

void solve2(void) {
	PORTA = 0x00;
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

char pattern[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

void solve3(void) {
	int idx = 0;
	while(1) {
		PORTA = pattern[idx];
		if(!(PINB & (1<<4))) {
			_delay_ms(200);
			if(++idx == 8) idx = 0;
			while(!(PINB & (1<<4))) {
				if(!(PINB & (1<<5))) {
					idx = 0;
				}
			}
		}
		else if(!(PINB & (1<<5))) {
			_delay_ms(200);
			if(--idx == -1) idx = 7;
			while(!(PINB & (1<<5))) {
				if(!(PINB & (1<<4))) {
					printf("shift END\r\n");
					for(int i=0; i<3; i++) {
						PORTA = 0xff;
						_delay_ms(500);
						PORTA = 0x00;
						_delay_ms(500);
					}
					exit(0);
				}
			}
		}
	}
}