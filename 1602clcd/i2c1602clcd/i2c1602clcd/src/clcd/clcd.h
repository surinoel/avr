/*
 * clcd.h
 *
 * Created: 2019-07-06 오후 3:07:14
 *  Author: user
 */ 


#ifndef CLCD_H_
#define CLCD_H_

#ifndef  F_CPU
#define F_CPU 16000000UL
#endif

#include "i2c_master.h"
#include <util/delay.h>

#include <avr/io.h>
#include <stdint.h>

void twi_init(void);
void i2c_lcd_init(void);
void i2c_lcd_command(uint8_t command);
void i2c_lcd_command_8(uint8_t command);
void i2c_lcd_data(uint8_t data);
void i2c_lcd_goto_XY(uint8_t row, uint8_t col);
void i2c_lcd_string(uint8_t row, uint8_t col, char string[]);

#endif /* CLCD_H_ */