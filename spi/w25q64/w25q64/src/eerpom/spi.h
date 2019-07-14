/*
 * spi.h
 *
 * Created: 2019-07-14 오전 4:18:00
 *  Author: yeong
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define SPI_CONTROL_PORT    PORTB
#define SPI_CONTROL_PIN     PINB
#define SPI_CONTROL_DDR     DDRB

#define SPI_SS_PIN          0   
#define SPI_MOSI_PIN        2   
#define SPI_MISO_PIN        3   
#define SPI_SCLK_PIN        1  

/** Begin Function Prototypes **/

/** @brief: initializes the SPI peripheral
 */
void spi_init(void);

/** @brief: uninitializes the SPI peripheral
 */
void spi_uninit(void);

/** @brief: spi transmit function
 *          sends and receives one byte simultaneously
 */

char spi_transmit(char tx_byte);

/** End Function Prototypes **/

#endif /* SPI_H_ */