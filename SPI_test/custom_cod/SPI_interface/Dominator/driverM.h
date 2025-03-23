#ifndef __DRIVERM_H
#define __DRIVERM_H

#include "spi.h"

typedef enum
{
  SPI_OK = 0,
  SPI_WaitResolution_Timeout = 1,
  SPI_STOP_ERR = 2
}spi_status_enum;

spi_status_enum SPI_WaitResolution(SPI_TypeDef* spi, uint8_t count);
spi_status_enum SPI_Exchange(SPI_TypeDef* spi, uint8_t* TxBuffer, uint8_t* RxBuffer, uint8_t length);
void SPI_Start();
spi_status_enum SPI_Stop();

#endif /* __DRIVERM_H */