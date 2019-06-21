/*
 * segment.c
 *
 * Created: 2019-06-22 오전 1:00:22
 *  Author: yeong
 */ 

 #include "segment.h"

 uint8_t digit[12] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x00, 0x40};
 uint8_t fnd_sel[4] = {0x0E, 0x0D, 0x0B, 0x07};
 uint8_t fnd_num[4];

 void fnd_init(void)
 {
	DDRC = 0xff;
	DDRG |= 0x0f;
 }

void display_fnd(uint16_t value) 
{
	int value_int, value_deci, num[4], i;
	if((value & 0x8000) != 0x8000) {
		num[3] = 10;
	}
	else {
		num[3] = 11;		
		value = (~value)+1;	
	}

	value_int = (char)((value & 0x7f00) >> 8);
	value_deci = (char)(value & 0x00ff);
	num[2] = (value_int / 10) % 10;
	num[1] = (value_int / 1) % 10;
	num[0] = ((value_deci & 0x80) == 0x80) ? 5 : 0;
	for(i=0; i<4; i++)
	{
		PORTC = digit[num[i]];
		PORTG = fnd_sel[i];
		if(i == 1) PORTC |= 0x80;
		_delay_ms(2.5);
	}
}