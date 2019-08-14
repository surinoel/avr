/*
 * 1602clcd_CGRAM.c
 *
 * Created: 2019-08-15 오전 1:35:33
 * Author : yeong
 */ 

#include <avr/io.h>
#include "uart.h"
#include "clcd.h"

uint8_t data1[8] = {0x02, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t data2[8] = {0x00, 0x0A, 0x00, 0x00, 0x11, 0x11, 0x0E, 0x00};

int main(void)
{
	uart0_init();
	i2c_lcd_init();
	i2c_set_CGRAM(0x00, data1);
	i2c_set_CGRAM(0x01, data2);

	i2c_lcd_goto_XY(0, 0);
	i2c_lcd_data(0);
	i2c_lcd_data(1);

    while (1) 
    {
		
    }
}

