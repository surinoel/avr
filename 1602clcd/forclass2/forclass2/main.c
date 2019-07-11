/*
 * forclass2.c
 *
 * Created: 2019-07-07 오후 2:14:50
 * Author : yeong
 */ 

#include <avr/io.h>
#include "clcd.h"
#include "uart.h"

int main(void)
{
    uart0_init();
	i2c_lcd_init();

	char str1[] = "Hello world";
	char str2[] = "ATmega128!";

	i2c_lcd_string(0, 0, str1);
	i2c_lcd_string(1, 0, str2);

	while (1) 
    {
    }
}

