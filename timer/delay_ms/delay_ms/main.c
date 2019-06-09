/*
 * delay_ms.c
 *
 * Created: 2019-06-07 오후 6:53:30
 * Author : yeong
 */ 

#include <avr/io.h>
#include "led.h"

int main(void)
{
	led_init();	
    while (1) 
    {
		led_blink(1000);
    }
}

