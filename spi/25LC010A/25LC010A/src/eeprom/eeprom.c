/*
 * eeprom.c
 *
 * Created: 2019-07-13 오후 8:59:22
 *  Author: yeong
 */ 

 #include "eeprom.h"

 #define SPI_SS		PB0
 #define SPI_MOSI	PB2
 #define SPI_MISO	PB3
 #define SPI_SCK		PB1

 #define EEPROM_Select()		PORTB &= ~(1<<SPI_SS)
 #define EEPROM_DeSelect()		PORTB |= (1<<SPI_SS)
 #define EERPOM_READ			0b00000011
 #define EERPOM_WRITE			0b00000010
 #define EEPROM_WREN			0b00000110
 #define EEPROM_RDSR			0b00000101

 #define EEPROM_PAGE_SIZE		16
 #define EEPROM_TOTAL_BYTE		128

 uint8_t EEPROM_readByte(uint8_t address)
 {
	EEPROM_Select();
	EEPROM_changeByte(EERPOM_READ);
	EEPROM_sendAddress(address);
	EEPROM_changeByte(0);
	EEPROM_DeSelect();

	return SPDR;
 }

 void EEPROM_changeByte(uint8_t byte)
 {
	SPDR = byte;
	while(!(SPSR & (1<<SPIF)));
 }

 void EEPROM_sendAddress(uint8_t address)
 {
	EEPROM_changeByte(address);
 }

 void EEPROM_writeEnable(void)
 {
	EEPROM_Select();
	EEPROM_changeByte(EEPROM_WREN);
	EEPROM_DeSelect();
 }

 void EEPROM_writeByte(uint8_t address, uint8_t data)
 {
	EEPROM_writeEnable();

	EEPROM_Select();
	EEPROM_changeByte(EERPOM_WRITE);
	EEPROM_sendAddress(address);
	EEPROM_changeByte(data);
	EEPROM_DeSelect();

	while(EEPROM_readStatus() & _BV(0));
 }

 uint8_t EEPROM_readStatus(void)
 {
	EEPROM_Select();
	EEPROM_changeByte(EEPROM_RDSR);
	EEPROM_changeByte(0);
	EEPROM_DeSelect();

	return SPDR;
 }

 void EEPROM_eraseALL(void)
 {
	uint8_t i;
	uint16_t pageAddress = 0;

	while(pageAddress < EEPROM_TOTAL_BYTE) {
		EEPROM_writeEnable();
		EEPROM_Select();
		EEPROM_changeByte(EERPOM_WRITE);
		EEPROM_sendAddress(pageAddress);
		for(i=0; i<EEPROM_PAGE_SIZE; i++) {
			EEPROM_changeByte(0);
		}
		EEPROM_DeSelect();

		pageAddress += EEPROM_PAGE_SIZE;
		while(EEPROM_readStatus() & _BV(0));
	}
 }

 void SPI_Init(void)
 {
	DDRB |= (1<<SPI_SS);
	PORTB |= (1<<SPI_SS);

	DDRB |= (1<<SPI_MOSI);
	DDRB &= ~(1<<SPI_MISO);
	DDRB |= (1<<SPI_SCK);

	SPCR |= (1<<MSTR);
	SPCR |= (1<<SPE);
 }