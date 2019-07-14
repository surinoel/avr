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