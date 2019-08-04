/*
 * w25q64.c
 *
 * Created: 2019-07-14 오전 4:16:22
 *  Author: yeong
 */ 

 #include "w25q64.h"

/** @brief: initialize the ss pin
 */
void w25q_ss_pin_init(void)
{
    W25Q_CONTROL_DDR |= (1<<W25Q_SS_PIN);   // Set as output
}

/** @brief: drives the ss pin
 */
void w25q_ss_pin_drive(uint8_t high)
{
    if(high)
    {
        W25Q_CONTROL_PORT |= (1<<W25Q_SS_PIN);
    }
    else
    {
        W25Q_CONTROL_PORT &= ~(1<<W25Q_SS_PIN);
    }
}

/** @brief: return the manufacturer ID
 */
char w25q_read_manufacturer_id(void)
{
    w25q_ss_pin_drive(LOGIC_LOW);
    spi_transmit(0x90);
    spi_transmit(0x00);
    spi_transmit(0x00);
    spi_transmit(0x00);
    uint8_t man_id = spi_transmit(0x00);
    spi_transmit(0x00);
    w25q_ss_pin_drive(LOGIC_HIGH);
    return man_id;
}

/** @brief: return the device ID
 */
char w25q_read_device_id(void)
{
    w25q_ss_pin_drive(LOGIC_LOW);
    spi_transmit(0x90);
    spi_transmit(0x00);
    spi_transmit(0x00);
    spi_transmit(0x00);
    spi_transmit(0x00);
    uint8_t dev_id = spi_transmit(0x00);
    w25q_ss_pin_drive(LOGIC_HIGH);
    return dev_id;
}

void write_enable(void)
{
	w25q_ss_pin_drive(LOGIC_LOW);
	spi_transmit(0x06);
	w25q_ss_pin_drive(LOGIC_HIGH);
}

void erase_block(uint32_t addr)
{
	uint8_t cmd[3];
	cmd[0] = (addr >> 16) & 0xFF;
	cmd[1] = (addr >> 8) & 0xFF;
	cmd[2] = addr & 0xFF; 

	_delay_ms(5);
	write_enable();
	w25q_ss_pin_drive(LOGIC_LOW);
	_delay_ms(5);
	spi_transmit(0x20);
	spi_transmit(cmd[0]);
	spi_transmit(cmd[1]);
	spi_transmit(cmd[2]);
	w25q_ss_pin_drive(LOGIC_HIGH);
}

void w25q_page_write(uint32_t addr, uint8_t *data, uint32_t size)
{
	uint8_t cmd[3];
	cmd[0] = (addr >> 16) & 0xFF;
	cmd[1] = (addr >> 8) & 0xFF;
	cmd[2] = addr & 0xFF;

	_delay_ms(5);
	write_enable();
	_delay_ms(5);
	w25q_ss_pin_drive(LOGIC_LOW);
	spi_transmit(0x02);
	spi_transmit(cmd[0]);
	spi_transmit(cmd[1]);
	spi_transmit(cmd[2]);
	for(int i=0; i<size; i++) {
		spi_transmit(data[i]);
	}
	w25q_ss_pin_drive(LOGIC_HIGH);
	while(get_status());
}

uint8_t w25q_read(uint32_t addr)
{
	uint8_t ret;
	uint8_t cmd[3];
	cmd[0] = (addr >> 16) & 0xFF;
	cmd[1] = (addr >> 8) & 0xFF;
	cmd[2] = addr & 0xFF;

	w25q_ss_pin_drive(LOGIC_LOW);
	spi_transmit(0x03);
	spi_transmit(cmd[0]);
	spi_transmit(cmd[1]);
	spi_transmit(cmd[2]);
	ret = spi_transmit(0x00);
	w25q_ss_pin_drive(LOGIC_HIGH);
	return ret;	
}

uint8_t *arr;

void w25q_fast_read(uint32_t addr, uint32_t size)
{
	int ret;
	arr = (uint8_t *)malloc(sizeof(uint8_t)*size);
	uint8_t cmd[3];
	cmd[0] = (addr >> 16) & 0xFF;
	cmd[1] = (addr >> 8) & 0xFF;
	cmd[2] = addr & 0xFF;

	w25q_ss_pin_drive(LOGIC_LOW);
	spi_transmit(0x0B);
	spi_transmit(cmd[0]);
	spi_transmit(cmd[1]);
	spi_transmit(cmd[2]);
	ret = spi_transmit(0x00);
	for(int i=0; i<size; i++) {
		arr[i] = spi_transmit(0x00);
	}
	w25q_ss_pin_drive(LOGIC_HIGH);
	while(get_status());
}

uint8_t get_status(void)
{
	uint8_t ret;
	w25q_ss_pin_drive(LOGIC_LOW);
	spi_transmit(0x05);
	ret = spi_transmit(0x00);
	w25q_ss_pin_drive(LOGIC_HIGH);
	return (ret & 0x01);
}