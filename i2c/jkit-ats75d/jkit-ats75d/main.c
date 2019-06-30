/*
 * jkit-ats75d.c
 *
 * Created: 2019-06-30 오후 7:29:34
 * Author : yeong
 */ 

#define F_CPU 	16000000UL
#define F_SCK	40000UL		
#include <avr/io.h>
#include <util/delay.h>
#define ATS75_ADDR	0x98	
#define ATS75_CONFIG_REG		1
#define ATS75_TEMP_REG			0

void init_twi_port();
void write_twi_1byte_nopreset(char reg, char data);
int read_twi_2byte_nopreset(char reg);

int main(void)
{
	uint16_t temperature;
	uart0_init();
	init_twi_port();
	write_twi_1byte_nopreset(ATS75_CONFIG_REG, 0x00); 

	while (1) 
    {
		temperature = read_twi_2byte_nopreset(ATS75_TEMP_REG);
		printf("%d, %d\r\n", (temperature & 0xFF00) >> 8, temperature & 0x00FF);
		_delay_ms(500);
    }
}

void init_twi_port()
{
	DDRC = 0xff; DDRG = 0xff;
	DDRD = 0x00;; PORTD = 3;	
	SFIOR &= ~(1<<PUD); 	
	TWBR = (F_CPU/F_SCK - 16) / 2;
	TWSR = TWSR & 0xfc;	
}

void write_twi_1byte_nopreset(char reg, char data)
{
	TWCR = (1 << TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x08) ;		
	TWDR = ATS75_ADDR | 0;	
	TWCR = (1 << TWINT) | (1 << TWEN);	
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x18) ;
	TWDR = reg;	
	TWCR = (1 << TWINT) | (1 << TWEN);	
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x28) ;
	TWDR = data;			
	TWCR = (1 << TWINT) | (1 << TWEN);	
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x28) ;
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);	
	while ((TWCR & (1 << TWSTO))) ;	
}

int read_twi_2byte_nopreset(char reg)
{
	char high_byte, low_byte;
	TWCR = (1 << TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x08) ;		
	TWDR = ATS75_ADDR | 0;		
	TWCR = (1 << TWINT) | (1 << TWEN);		
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x18) ;
	TWDR = reg;				
	TWCR = (1 << TWINT) | (1 << TWEN);		
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x28) ;

	TWCR = (1 << TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x10) ;		
	TWDR = ATS75_ADDR | 1;			
	TWCR = (1 << TWINT) | (1 << TWEN);		
	while (((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x40) ;
	TWCR = (1 << TWINT) | (1 << TWEN | 1 << TWEA);
	while(((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x50);
	high_byte = TWDR;			
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(((TWCR & (1 << TWINT)) == 0x00) || (TWSR & 0xf8) != 0x58);
	low_byte = TWDR;			
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);	
	while ((TWCR & (1 << TWSTO))) ;		 
	return((high_byte<<8) | low_byte);		
}