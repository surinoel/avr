/*
 * tinyRTC.c
 *
 * Created: 2019-08-11 오후 4:23:38
 *  Author: yeong
 */ 

#include "tinyRTC.h"

#define SLAVE_ADDR	0x68

uint8_t setup_data[7];

uint8_t decimal_to_bcd(uint8_t decimal)
{
	return (((decimal/10) << 4) | (decimal%10));
}

uint8_t bcd_to_decimal(uint8_t bcd)
{
	return (bcd>>4) * 10 + (bcd & 0x0F);
}

void tinyRTC_init(void)
{
	i2c_init();
	DDRD |= (1<<0) | (1<<1);
}

void tinyRTC_setup(int sec, int min, int hour, int day, int date, int month, int year)
{
	setup_data[0] = decimal_to_bcd(sec);
	setup_data[1] = decimal_to_bcd(min);
	setup_data[2] = decimal_to_bcd(hour);
	setup_data[3] = decimal_to_bcd(day);
	setup_data[4] = decimal_to_bcd(date);
	setup_data[5] = decimal_to_bcd(month);
	setup_data[6] = decimal_to_bcd(year);
}

void tinyRTC_set_date(void) 
{
	while(i2c_writeReg((SLAVE_ADDR << 1), 0x00, setup_data, 7));
}

void tinyRTC_read_date(void)
{
	uint8_t data[7];
	memset(data, 0, sizeof(data));
	while(i2c_readReg((SLAVE_ADDR << 1), 0x00, data, 7));

	printf("20%d,%d,%d (%s) %d:%d:%d\r\n", bcd_to_decimal(data[6]),
											bcd_to_decimal(data[5]),
											bcd_to_decimal(data[4]),
											change_day(bcd_to_decimal(data[3])),
											bcd_to_decimal(data[2]),
											bcd_to_decimal(data[1]),
											bcd_to_decimal(data[0]));
}

char *change_day(uint8_t day)
{
	if (day == 1) return "sun";
	else if (day == 2) return "mon";
	else if (day == 3) return "tue";
	else if (day == 4) return "wed";
	else if (day == 5) return "thu";
	else if (day == 6) return "fri";
	else if (day == 7) return "sat";
}