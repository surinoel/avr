/*
 * w25q64.h
 *
 * Created: 2019-07-14 오전 4:16:35
 *  Author: yeong
 */ 


#ifndef W25Q64_H_
#define W25Q64_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>
#include "spi.h"
#include "uart.h"

#define W25Q_SS_PIN 0   

#define W25Q_CONTROL_DDR    DDRB
#define W25Q_CONTROL_PORT   PORTB
#define W25Q_CONTROL_PIN    PINB

#define W25Q64_PAGE_SIZE	0x100     /* 32768 pages of 256 bytes */

#define LOGIC_LOW   0
#define LOGIC_HIGH  1

/** Begin Function Prototypes **/

/** @brief: initialize the ss pin
 */
void w25q_ss_pin_init(void);

/** @brief: drives the ss pin
 */
void w25q_ss_pin_drive(uint8_t high);

/** @brief: return the manufacturer ID
 */
char w25q_read_manufacturer_id(void);

/** @brief: return the device ID
 */
char w25q_read_device_id(void);

void w25q_write_enable(void);

void w25q_write_disable(void);

void w25q_page_write(uint32_t addr, uint8_t *data, uint32_t size);

uint8_t w25q_read(uint32_t addr);
void w25q_fast_read(uint32_t addr, uint32_t size);

uint8_t getstatus(void);

uint8_t is_write_enable(void);

void erase_block(uint32_t addr);
/** End Function Prototypes **/

#endif /* W25Q64_H_ */