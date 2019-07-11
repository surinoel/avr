/*
 * clcd.h
 *
 * Created: 2019-07-07 오후 2:15:48
 *  Author: yeong
 */ 


#ifndef CLCD_H_
#define CLCD_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>

#include "uart.h"
#include "i2c_master.h"

void i2c_lcd_init(void);
void i2c_lcd_command(uint8_t command);
void i2c_lcd_data(uint8_t data);
void i2c_lcd_goto_XY(uint8_t row, uint8_t col);
void i2c_lcd_string(uint8_t row, uint8_t col, char buf[]);

#endif /* CLCD_H_ */