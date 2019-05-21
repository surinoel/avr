/*
 * keypad.c
 *
 * Created: 2019-05-19 오전 10:28:41
 *  Author: yeong
 */ 

 #include "keypad.h"

extern FILE OUTPUT;
extern FILE INPUT;

 void keypad_init(void) {
	DDRF &= ~((1<<4) | (1<<5) | (1<<6) | (1<<7));
	PORTF |= ((1<<4) | (1<<5) | (1<<6) | (1<<7));

	DDRD |= ((1<<4) | (1<<5) | (1<<6) | (1<<7));
	PORTD |= ((1<<4) | (1<<5) | (1<<6) | (1<<7));
 }

 unsigned char keypad_scan(void) {
	unsigned char key_value = 'A';

	for(int i=0; i<4; i++) {
		PORTD &= ~(1<<(4+i));
		_delay_ms(20);

		switch(PINF & 0xF0) {
			case 0xE0: 
				key_value = 4*0 + i;
			break;
			case 0xD0:
				key_value = 4*1 + i;
			break;
			case 0xB0:
				key_value = 4*2 + i;
			break;
			case 0x70:
				key_value = 4*3 + i;
			break;
		}

		_delay_ms(20);
		PORTD |= (1<<(4+i));
	}	

	return key_value;
 }

void print_keyvalue(unsigned char value) {
	if(value != 'A') {
		printf("%c\r\n", 'a' + value);
	}
}


 unsigned char keypad_trans(void) {
	
 }

 int keypad_check_push_time(unsigned char port, unsigned char port_num) {

 }
