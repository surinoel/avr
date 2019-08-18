/*
 * tinyRTC.h
 *
 * Created: 2019-08-18 오후 4:13:27
 *  Author: yeong
 */ 

#ifndef TINYRTC_H_
#define TINYRTC_H_

#include <avr/io.h>
#include "uart.h"
#include "i2c_master.h"

void tinyRTC_init(void);
uint8_t decimal_to_bcd(uint8_t decimal);
uint8_t bcd_to_decimal(uint8_t bcd);
void tinyRTC_setup(int sec, int min, int hour, int day, int date, int month, int year);
void tinyRTC_read(void);
char *change_day(uint8_t day);

#endif /* TINYRTC_H_ */