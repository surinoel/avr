/*
 * tinyRTC.h
 *
 * Created: 2019-08-11 오후 4:23:47
 *  Author: yeong
 */ 

#ifndef TINYRTC_H_
#define TINYRTC_H_

#include "i2c_master.h"
#include "uart.h"

#include <avr/io.h>
#include <string.h>

void tinyRTC_init(void);
void tinyRTC_setup(int sec, int min, int hour, int date, int day, int month, int year);
void tinyRTC_set_date(void);
void tinyRTC_read_date(void);
char *change_day(uint8_t day);
uint8_t decimal_to_bcd(uint8_t decimal);
uint8_t bcd_to_decimal(uint8_t bcd);

#endif /* TINYRTC_H_ */