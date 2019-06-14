/*
 * icp.c
 *
 * Created: 2019-06-14 오후 8:45:36
 * Author : yeong
 */ 

#include <avr/io.h>
#include "timer.h"

int main(void)
{
	uart0_init();
	icp_timer1_init();

    while (1) 
    {
    }
}

