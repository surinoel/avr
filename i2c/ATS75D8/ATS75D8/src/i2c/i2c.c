/*
 * i2c.c
 *
 * Created: 2019-06-16 오후 4:32:01
 *  Author: yeong
 */ 

 void init_twi_port(void) {
	DDRD = 0x00; PORTD = 3;
	SFIOR &= ~(1<<PUD);
	TWBR = (F_CPU/F_SCK - 16)/ 2;
	TWSR = TWSR & 0xfc;
 }

 void write_twi_1byte(char reg, char data)
 {


 }