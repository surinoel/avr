/*
 * spi.c
 *
 * Created: 2019-07-14 오전 4:16:00
 *  Author: yeong
 */ 

 #include "spi.h"

/**@brief: initializes the SPI peripheral
 *         sets the MOSI, SCLK and SS Pins as outputs
 *         enables the SPI in master mode, f/16 clk
 */

void spi_init(void)
{
    DDRB = ((1<<SPI_MOSI_PIN)|(1<<SPI_SCLK_PIN)|(1<<SPI_SS_PIN)); //spi pins on port b MOSI SCK,SS outputs
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
			
}

/** @brief: spi transmit function
 *          sends and receives a byte at the same time
 */

uint8_t spi_transmit(uint8_t tx_byte)
{
   SPDR = tx_byte;
   while(!(SPSR & (1<<SPIF)));
   return SPDR;
}