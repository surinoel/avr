/*
 * rgbLED.c
 *
 * Created: 2019-06-15 오후 2:44:20
 * Author : yeong
 */ 

#include "timer.h"
#include <string.h>
#include <stdbool.h>

#define F_CPU 16000000UL
#include <util/delay.h>

bool check[3];

int main(void)
{
	timer3_pwm_init();
	while (1) 
	{
		for(int i=1; i<(1<<3); i++) {
			memset(check, 0, sizeof(check));
			for(int j=0; j<3; j++) {
				if(i & (1<<j)) {
					check[j] = true;			
				}
			}
			for(int j=0; j<=1000; j++) {
				for(int k=0; k<3; k++) {
					if(check[k]) {
						if(k==0) OCR3A = j;
						else if(k==1) OCR3B = j;
						else OCR3C = j;
					}	
				}
				_delay_ms(1);
			}	
		}
	}
}
