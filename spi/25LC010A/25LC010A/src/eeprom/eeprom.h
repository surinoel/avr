/*
 * eeprom.h
 *
 * Created: 2019-07-13 오후 8:59:34
 *  Author: yeong
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

uint8_t EEPROM_readByte(uint8_t address);
void EEPROM_changeByte(uint8_t byte);
void EEPROM_sendAddress(uint8_t address);
void EEPROM_writeEnable(void);
void EEPROM_writeByte(uint8_t address, uint8_t data);
uint8_t EEPROM_readStatus(void);

#endif /* EEPROM_H_ */