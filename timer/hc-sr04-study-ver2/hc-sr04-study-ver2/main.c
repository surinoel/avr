/*
 * hc-sr04-study-ver2.c
 *
 * Created: 2019-08-24 오후 2:21:10
 * Author : yeong
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "clcd.h"
#include "uart.h"
#include "hcsr04.h"

uint8_t buf[128];

int main(void)
{
	uart0_init();
	i2c_lcd_init();
	hcsr04_init();

	while(1)
	{
		if(flag) {
			flag = 0;
			sprintf(buf, "dist:%4dcm     ", dist);
			i2c_lcd_string(0, 0, buf);
		}
	}
}

