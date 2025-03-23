#ifndef __DRIVERS_H
#define __DRIVERS_H

#include "spi.h"

uint8_t SPI_WaitResolutionSlave(SPI_TypeDef* spi, uint8_t count);
uint8_t SPI_Receive(SPI_TypeDef* spi, uint8_t* RxBuffer);
//void SPI_Start();
//void SPI_Stop();

#endif /* __DRIVERS_H */