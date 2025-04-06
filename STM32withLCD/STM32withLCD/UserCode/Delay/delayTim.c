#include "delayTim.h"

//void delay_ms(uint32_t ms)
//{
//  __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
//  /* Add this code to indicate that local variable is not used */
//  ((void)tmp);
//  
//  uint32_t currrentTime = SysTick->VAL;
//  //uint32_t targetTime = currrentTime + (uint32_t) ms;
//  uint32_t targetTicks = (ms * SYSTICK_PER_SEC_MS) - SYSTICK_CODE_RUN_DELAY;  
//    
//  while((uint32_t)(currrentTime - SysTick->VAL) < targetTicks);
//}

//void delay_us(uint32_t us)
//{
//  __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
//  /* Add this code to indicate that local variable is not used */
//  ((void)tmp);
//  
//  uint32_t currrentTime = SysTick->VAL;
//  uint32_t targetTicks = (us * SYSTICK_PER_SEC_US) - SYSTICK_CODE_RUN_DELAY;  
//    
//  while((uint32_t)(currrentTime - SysTick->VAL) < targetTicks);
//}

void delay_us(uint32_t us)
{
  
  SysTick->LOAD  = (uint32_t)(SYSTICK_PER_SEC_US - 1UL);  /* set reload register */
  SysTick->VAL   = 0UL;                                       /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;                   /* Enable the Systick Timer */
  
   __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
  /* Add this code to indicate that local variable is not used */
  ((void)tmp);

  while (us)
  {
    if((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      us--;
    }
  }
}

void delay_ms(uint32_t ms)
{
  SysTick->LOAD  = (uint32_t)(SYSTICK_PER_SEC_MS - 1UL);  /* set reload register */
  SysTick->VAL   = 0UL;                                       /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;                   /* Enable the Systick Timer */
  
   __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
  /* Add this code to indicate that local variable is not used */
  ((void)tmp);

  while (ms)
  {
    if((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      ms--;
    }
  }
}

