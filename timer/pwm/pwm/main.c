/*
 * pwm.c
 *
 * Created: 2019-06-09 오후 3:27:09
 * Author : yeong
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "timer.h"

int main(void)
{
    // timer1_pwm_init();
	buzzer_init();
    while (1) 
    {
		/*
		for(int i=0; i<=5000; i++) {
			OCR1A = i;
			_delay_us(500);
		}
		*/
    }
}

