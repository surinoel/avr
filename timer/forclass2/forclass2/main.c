/*
 * forclass2.c
 *
 * Created: 2019-06-09 오후 2:52:47
 * Author : yeong
 */ 

#include <avr/io.h>
#include "led.h"

int main(void)
{
	led_init();	
    while (1) 
    {
		led_blink(500);
    }
}

