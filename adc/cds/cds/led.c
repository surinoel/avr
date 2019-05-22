/*
 * led.c
 *
 * Created: 2019-05-22 오전 10:11:57
 *  Author: yeong
 */ 

 #include "led.h"

 void led_init(void) {
	DDRA = 0xff;
 }

 void cds_led_on(unsigned char adc_read_val) {
	int val = adc_read_val;
	if(val <= 93) {
		PORTA = 0xff;
	}
	else if(val > 93 && val <= 819) {
		PORTA = 0x1f;
	}
	else if(val > 819 && val <= 1000) {
		PORTA = 0x07;
	}
	else {
		PORTA = 0x01;
	}
	printf("cds_value : %d\r\n", val);
 }
