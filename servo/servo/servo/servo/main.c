/*
 * servo.c
 *
 * Created: 2019-06-30 오후 3:41:18
 * Author : yeong
 */ 

#include <avr/io.h>
#include "timer3.h"
#include "switch.h"

int main(void)
{
	
	// 서보를 돌린다
	// 돌리기 위해선 PWM 3번 타이머, 14번 고속 PWM(TOP ICR3, OCR3A => OC3A)
	// ICR3 => 20ms 파형을 맞추고, OCR3A = ICR3 * 1/10 => -90, ICR3 * 3/20 => 0, ICR3 * 1/5 => 90
	
	timer3_pwm_init();
	switch_exti_init();

	while (1) 
	{

	}
}
