/*
 * timer.c
 *
 * Created: 2019-06-09 오후 3:28:47
 *  Author: yeong
 */ 

 #include "timer.h"

 enum scale {
	EOS = -1, 
	DO, RE, MI, FA, SOL, RA, SI, DDO
 };

 volatile int state, tone;
 uint16_t f_table[8] = {15926, 13628, 12139, 11461, 10210, 9090, 8101, 7644};
 int song[] = {SOL, MI, MI, SOL, MI, DO, RE, MI, RE, DO, MI, SOL, DDO, SOL, DDO, SOL, DDO, SOL, MI, SOL, RE, FA, MI, RE, DO, EOS};
 
 void buzzer_downVOL_init(void) {
	DDRE |= (1<<3);
	TCCR3A |= (1<<COM3A1) | (1<<WGM31);
	TCCR3B |= (1<<WGM33) | (1<<WGM32) | (1<<CS10);

	for(int i=0; song[i] != EOS; i++) {
		ICR3 = f_table[song[i]];
		OCR3A = f_table[song[i]] * 0.7;
		_delay_ms(500);
	}
 }