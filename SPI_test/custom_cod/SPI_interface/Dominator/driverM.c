#include "spi.h"
#include "driverM.h"


spi_status_enum SPI_WaitResolution(SPI_TypeDef* spi, uint8_t count)
{
//  if( spi->SR | SPI_SR_FRE ) 
//  {
//    return 1;
//  }
  
  
  while(  (!(spi->SR & SPI_SR_TXE) || (spi->SR & SPI_SR_BSY)) && count > 0)
  {
    count--;
  }
    
  if(count > 0) return SPI_OK;
  else return SPI_WaitResolution_Timeout;   
}

spi_status_enum SPI_Exchange(SPI_TypeDef* spi, uint8_t* TxBuffer, uint8_t* RxBuffer, uint8_t length)
{
  uint8_t* TxPtr = TxBuffer;
  uint8_t* RxPtr = RxBuffer;
  
  while (length > 0 && !(spi->SR & SPI_SR_BSY))
  {
    if(SPI_WaitResolution(spi, 0x50) != 0)
    {
      return SPI_WaitResolution_Timeout;
    }
    spi->DR = *TxPtr++;
    
    while(!(spi->SR & SPI_SR_RXNE)) {}
    *RxPtr++ = spi->DR;
    
    length--;
  }
  
  return SPI_OK;
}

void SPI_Start(SPI_TypeDef* spi)
{ 
  spi->CR1 |= SPI_CR1_SPE;
}

spi_status_enum SPI_Stop(SPI_TypeDef* spi)
{
  if (SPI_WaitResolution(spi, 0x00) == SPI_OK)
  {
    spi->CR1 &= ~SPI_CR1_SPE;
    return SPI_OK;
  }
  else return SPI_STOP_ERR;
}