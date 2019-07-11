/*
 * clcd.c
 *
 * Created: 2019-07-07 오후 2:15:41
 *  Author: yeong
 */ 

 #include "clcd.h"

 uint8_t I2C_addr_PCF8574 = (0x20 << 1);

void i2c_lcd_init(void)
{
	printf("Before Connect... \r\n");
	i2c_init();
	while(!i2c_start(I2C_addr_PCF8574));
	i2c_stop();
	printf("Connect Ok\r\n");

	_delay_ms(50);
	i2c_lcd_command(0x08); _delay_ms(1000);


	printf("Before Initialize...\r\n");
	i2c_lcd_command(0x28); _delay_us(50);
	i2c_lcd_command(0x0C); _delay_us(50);
	i2c_lcd_command(0x06); _delay_us(50);
	i2c_lcd_command(0x01); _delay_ms(2);
	printf("Initialize Ok\r\n");
}

void i2c_lcd_command(uint8_t command)
{
	uint8_t c_buf[2];
	
	c_buf[0] = (command >> 4) | (0x10);
	c_buf[1] = c_buf[0] & 0xEF;

	i2c_transmit(I2C_addr_PCF8574, c_buf, 4);
}

void i2c_lcd_command(uint8_t command)
{
	uint8_t c_buf[4];
	
	c_buf[0] = (command >> 4) | (0x10);
	c_buf[1] = c_buf[0] & 0xEF;

	c_buf[2] = (command & 0x0F) | (0x10);
	c_buf[3] = c_buf[2] & 0xEF;

	i2c_transmit(I2C_addr_PCF8574, c_buf, 4);
}

void i2c_lcd_data(uint8_t data)
{
	uint8_t d_buf[4];
	
	d_buf[0] = (data >> 4) | (0x50);
	d_buf[1] = d_buf[0] & 0xEF;

	d_buf[2] = (data & 0x0F) | (0x50);
	d_buf[3] = d_buf[2] & 0xEF;

	i2c_transmit(I2C_addr_PCF8574, d_buf, 4);
}

void i2c_lcd_goto_XY(uint8_t row, uint8_t col)
{
	row %= 2;
	col %= 16;

	uint8_t address = (0x40 * row) + col;
	uint8_t command = 0x80 + address;

	i2c_lcd_command(command);
}

void i2c_lcd_string(uint8_t row, uint8_t col, char buf[]) 
{
	i2c_lcd_goto_XY(row, col);
	for(int i=0; buf[i] != '\0'; i++) {
		i2c_lcd_data(buf[i]);
	}
}