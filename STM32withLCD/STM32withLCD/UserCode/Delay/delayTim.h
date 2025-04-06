#ifndef __DELEYTIM_H
#define __DELEYTIM_H

#include "stdint.h"
//#include "core_cm4.h"
#include "stm32f4xx.h"

#define SYSTICK_PER_SEC_US (SystemCoreClock/1000000U)
#define SYSTICK_PER_SEC_MS (SystemCoreClock/1000U)      
//#define SYSTICK_CODE_RUN_DELAY (SYSTICK_PER_SEC_US >> 1) // time to execution code (conditionaly)

void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#endif