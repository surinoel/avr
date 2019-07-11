/*
 * 1602clcdholic.c
 *
 * Created: 2019-07-08 오전 12:44:34
 * Author : yeong
 */ 

#define F_CPU	16000000UL
#include <util/delay.h>

#include "i2c_master.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int _addr = 0x20;
int _cols = 0, _rows = 0;
int _backlightval = 0x08;
int _displayfunction, _displaycontrol;

void LCD_I2C_init(int addr, int col, int row)
{
	_addr = addr;
	_cols = col;
	_rows = row;
	_backlightval = 0x08;
}

void LCD_I2C_begin(void)
{
	i2c_init();
	_displayfunction = 0x00;
	if(_rows > 1) {
		_displayfunction |= 0x08;
	}
	_delay_ms(50);

	write4bit(0x30);
	_delay_us(4500);
	write4bit(0x30);
	_delay_us(4500);
	write4bit(0x30);
	_delay_us(150);
	write4bit(0x20);
	
	command(0x20 | _displayfunction);
	_displaycontrol = 0x04;
	command(0x08 | _displaycontrol);
	command(0x01); _delay_ms(2);
	command(0x06);
	command(0x02); _delay_ms(2);
}

void send(uint8_t data, int mode)
{
	uint8_t highnib = data & 0xF0;
	uint8_t lownib = (data << 4) & 0xF0;
	write4bit((highnib) | mode);
	write4bit((lownib) | mode);
}

void command(uint8_t data)
{
	send(data, 0);
}

void write(uint8_t data)
{
	send(data, 0x01);
}

void write4bit(uint8_t data)
{
	i2c_transmit(_addr << 1, data | 0x04 | _backlightval, 1);
	_delay_us(1);
	i2c_transmit(_addr << 1, data | ~(0x04) | _backlightval, 1);
	_delay_us(50);
}

int main(void)
{
    char buf[40];
	char cnt = 0;
	sei();
	LCD_I2C_init(0x20, 16, 2);
    LCD_I2C_begin();
	
	command(0x80);
	write('c');

	while (1) 
    {
    }
}

