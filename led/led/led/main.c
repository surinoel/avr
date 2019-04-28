/*
 * led.c
 *
 * Created: 2019-04-28 오후 3:45:23
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;
	
    while (1) 
    {
		/*
		// LED 순차적으로 켜기
		for(int i=0; i<8; i++) {
			PORTA = (1<<i);
			_delay_ms(1000);
		}
		*/				
		/*
		// 홀수 LED, 짝수 LED 번갈아가면서 키고 끄는 예제 일반화하기
		for(int i=0; i<2; i++) {
			for(int j=0; j<4; j++) {
				PORTA |= (1<<2*j+i);
			}
			_delay_ms(1000);
			for(int j=0; j<4; j++) {
				PORTA &= ~(1<<2*j+i);
			}
			_delay_ms(1000);
		}
		*/
	}
}

