/*
 * i2c1602clcd.c
 *
 * Created: 2019-07-06 오후 12:42:43
 * Author : user
 */ 

#include <avr/io.h>
#include "clcd.h"
#include "uart.h"
#include "hcsr04.h"

int main(void)
{
	uart0_init();
	i2c_lcd_init();
	hcsr04_init();

	while(1)
	{
		trg_pulse();
		_delay_ms(60);
	}
}