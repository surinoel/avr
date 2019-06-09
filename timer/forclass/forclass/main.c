/*
 * forclass.c
 *
 * Created: 2019-06-02 오후 2:38:24
 * Author : yeong
 */ 

#include <avr/io.h>
#include "timer.h"
#include "uart.h"

extern volatile int flag;

int main(void)
{
	DDRA = 0xff;
	uart0_init();
	timer0_comp_ctc_init();

    while (1) 
    {
		/*
		if(flag) {
			printf("hello world\r\n");
			flag = 0;	
		}
		*/
    }
}

