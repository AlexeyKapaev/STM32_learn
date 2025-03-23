#include "spi.h"
#include "driverS.h"


uint8_t SPI_WaitResolutionSlave(SPI_TypeDef* spi, uint8_t count)
{
//  if( spi->SR & SPI_SR_FRE ) 
//  {
//    return 1;
//  }
  
  while((spi->SR & SPI_SR_BSY) && count > 0)
  {
    count--;
  }
    
  if(count > 0) return 0;
  else return 1;   
}


uint8_t SPI_Receive(SPI_TypeDef* spi, uint8_t* RxBuffer)
{
  uint8_t* RxPtr = RxBuffer; 
  *RxPtr++ = spi->DR;  
  
  return 0;
}