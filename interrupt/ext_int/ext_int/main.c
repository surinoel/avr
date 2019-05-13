/*
 * ext_int.c
 *
 * Created: 2019-05-11 오전 2:09:13
 * Author : yeong
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void port_init(void);
void ext_int_init(void);

ISR(INT4_vect) {
/*
	PORTA ^= 0xff;
	_delay_ms(20);
	while((PINE & (1<<4)) == 0);
	_delay_ms(20);
	EIFR |= (1<<4);
	sei();
*/
}

ISR(INT5_vect) {
	
}

int main(void)
{
	port_init();
	ext_int_init();

    while (1) 
    {
    }
}

void port_init(void) {
	DDRA = 0xff;
	DDRE &= ~((1<<4) | (1<<5));
	PORTE |= ((1<<4) | (1<<5));
}

void ext_int_init(void) {
	EIMSK |= ((1<<4) | (1<<5));
	EICRB |= ((0<<ISC40) | (1<<ISC41));
	sei();
}