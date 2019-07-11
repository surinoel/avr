
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "twi.h"
#include <avr/io.h>
#define true 1
#define false 0
#define F_CPU 16000000UL
#define BUFFER_LENGTH 32

uint8_t rxBuffer[BUFFER_LENGTH];
uint8_t rxBufferIndex = 0;
uint8_t rxBufferLength = 0;

uint8_t txAddress = 0;
uint8_t txBuffer[BUFFER_LENGTH];
uint8_t txBufferIndex = 0;
uint8_t txBufferLength = 0;

uint8_t transmitting = 0;
void (*user_onRequest)(void);
void (*user_onReceive)(int);

 


void onRequestService(void);
void onReceiveService(uint8_t* inBytes, int numBytes);


void Wire_begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;

  twi_init();
}

void Wire_begin_slave(uint8_t address)
{
  twi_setAddress(address);
  twi_attachSlaveTxEvent(onRequestService);
  twi_attachSlaveRxEvent(onReceiveService);
  Wire_begin();
}

void Wire_setClock(uint32_t frequency)
{
  TWBR = ((F_CPU / frequency) - 16) / 2;
}

static uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
  // clamp to buffer length
  if(quantity > BUFFER_LENGTH){
    quantity = BUFFER_LENGTH;
  }
  // perform blocking read into buffer
  uint8_t read = twi_readFrom(address, rxBuffer, quantity, sendStop);
  // set rx buffer iterator vars
  rxBufferIndex = 0;
  rxBufferLength = read;

  return read;
}

uint8_t Wire_requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

void Wire_beginTransmission(uint8_t address)
{
  // indicate that we are transmitting
  transmitting = 1;
  // set address of targeted slave
  txAddress = address;
  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;
}

uint8_t Wire_endTransmission(uint8_t sendStop)
{
  // transmit buffer (blocking)
  int8_t ret = twi_writeTo(txAddress, txBuffer, txBufferLength, 1, sendStop);
  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;
  // indicate that we are done transmitting
  transmitting = 0;
  return ret;
}

int write_error;

void setWriteError(int err) 
{ 
  write_error = err; 
}
size_t Wire_write(uint8_t data)
{
  if(transmitting){
  // in master transmitter mode
    // don't bother if buffer is full
    if(txBufferLength >= BUFFER_LENGTH){
      setWriteError(1);
      return 0;
    }
    // put byte in tx buffer
    txBuffer[txBufferIndex] = data;
    ++txBufferIndex;
    // update amount in buffer
    txBufferLength = txBufferIndex;
  }else{
  // in slave send mode
    // reply to master
    twi_transmit(&data, 1);
  }
  return 1;
}

size_t Wire_write_len(const uint8_t *data, size_t quantity)
{
  size_t i;
  if(transmitting){
  // in master transmitter mode
    for(i = 0; i < quantity; ++i){
      Wire_write(data[i]);
    }
  }else{
  // in slave send mode
    // reply to master
    twi_transmit(data, quantity);
  }
  return quantity;
}

int Wire_available(void)
{
  return rxBufferLength - rxBufferIndex;
}

int Wire_read(void)
{
  int value = -1;

  // get each successive byte on each call
  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
    ++rxBufferIndex;
  }

  return value;
}

int Wire_peek(void)
{
  int value = -1;

  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
  }

  return value;
}


// behind the scenes function that is called when data is received
void onReceiveService(uint8_t* inBytes, int numBytes)
{
uint8_t i;
  // don't bother if user hasn't registered a callback
  if(!user_onReceive){
    return;
  }
  // don't bother if rx buffer is in use by a master requestFrom() op
  // i know this drops data, but it allows for slight stupidity
  // meaning, they may not have read all the master requestFrom() data yet
  if(rxBufferIndex < rxBufferLength){
    return;
  }
  // copy twi rx buffer into local read buffer
  // this enables new reads to happen in parallel
  for( i = 0; i < numBytes; ++i){
    rxBuffer[i] = inBytes[i];
  }
  // set rx iterator vars
  rxBufferIndex = 0;
  rxBufferLength = numBytes;
  // alert user program
  user_onReceive(numBytes);
}


void onRequestService(void)
{
  // don't bother if user hasn't registered a callback
  if(!user_onRequest){
    return;
  }
  // reset tx buffer iterator vars
  // !!! this will kill any pending pre-master sendTo() activity
  txBufferIndex = 0;
  txBufferLength = 0;
  // alert user program
  user_onRequest();
}

// sets function called on slave write
void onReceive( void (*function)(int) )
{
  user_onReceive = function;
}

// sets function called on slave read
void onRequest( void (*function)(void) )
{
  user_onRequest = function;
}

