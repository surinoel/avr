#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;
	int i;
	int n = 8;
    while (1) 
    {
		for(i=0; i<(1<<n); i++) {
			PORTA = i;
			_delay_ms(300);				
		}
    }
}

