/*
 * keypad.c
 *
 * Created: 2019-05-19 오전 1:35:13
 * Author : yeong
 */ 

#include <avr/io.h>

#include "keypad.h"

int main(void)
{	
	uart0_init();
	keypad_init();
    while (1) 
    {
		print_keyvalue(keypad_scan());	
    }
}

