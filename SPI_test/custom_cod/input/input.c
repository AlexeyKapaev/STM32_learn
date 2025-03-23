#include "stdint.h"
#include "input.h"
#include "gpio.h"

bool buttonCheck(void){
  return GPIOC->IDR & LL_GPIO_PIN_14;
}