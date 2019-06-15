/*
 * buzzer_pwm.c
 *
 * Created: 2019-06-15 오후 7:13:58
 * Author : yeong
 */ 

#include "timer.h"

int main(void)
{
	while (1) 
    {
		buzzer_init();
		buzzer_downVOL_init();
    }
}

