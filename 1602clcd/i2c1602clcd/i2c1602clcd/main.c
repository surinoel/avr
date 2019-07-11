/*
 * i2c1602clcd.c
 *
 * Created: 2019-07-06 오후 12:42:43
 * Author : user
 */ 

#include <avr/io.h>
#include "clcd.h"
#include "uart.h"

int main(void)
{
	uart0_init();
	i2c_lcd_init();
	
	char str0[] = "PCF8574 I2C CLCD";
	char str1[] = "ATmega128";
	
	printf("Before string transfer....\r\n");
	i2c_lcd_string(0, 0, str0);
	i2c_lcd_string(1, 0, str1);
	printf("string transfer complete....\r\n");	
	
	while(1)
	{
	
	}
}