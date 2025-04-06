#include "driverLCD.h"
 
void LCD_Init_4bit() 
{ 
  delay_ms(4000); 
 
  // Function set
  LCD_sendCmd_0(0x02);
  LCD_sendCmd_0(0x02);
  LCD_sendCmd_0(0x08); // 0000 1000 to data line pins
//  LCD_sendCmd(0x02); // 0000 0010 to data line pins
//  LCD_sendCmd(0x28); // 0010 1000 to data line pins
  
  delay_us(50); 
 
  // Display on/off control
//  LCD_sendCmd(0x00);
//  LCD_sendCmd(0x0e); // 0000 1110 to data line pins
  LCD_displayControl();
  
  delay_us(50);
  
  // Display clear
//  LCD_sendCmd(0x00);
//  LCD_sendCmd(0x01);
  LCD_clear();
  
  delay_ms(3);
  
  // Entry Mode set
//  LCD_sendCmd(0x00);
//  LCD_sendCmd(0x06); // 0000 0110 to data line pins
  LCD_entyModeSet();
  
  delay_us(30);
} 

void LCD_sendCmd_0(uint8_t data) 
{ 
  GPIOA->ODR &= ~(0xF << DATA_PINS_OFFSET); // clear
  GPIOA->ODR &= ~0x03; // RS pin (PA1) and RW pin (PA2) set to LOW
  GPIOA->ODR |= (data << DATA_PINS_OFFSET);
  ENclock();
} 
 
void LCD_sendCmd(uint8_t data) 
{ 
  GPIOA->ODR &= ~0x03; // RS(PA1)=LOW, RW(PA2)=LOW
  
  GPIOA->ODR &= ~(0x0f << DATA_PINS_OFFSET); // clear 
  GPIOA->ODR |= ((data & 0xf0) >> 4) << DATA_PINS_OFFSET;
  ENclock();
  
  GPIOA->ODR &= ~(0x0f << DATA_PINS_OFFSET); // clear 
  GPIOA->ODR |= ((data & 0x0f) << DATA_PINS_OFFSET);
  ENclock();
} 
 
void LCD_sendData(uint8_t data) 
{ 
  GPIOA->ODR &= ~0x03; // RS(PA1)=LOW, RW(PA2)=LOW (RESET)
  GPIOA->ODR |= 0x02; // RS(PA1)=HIGH
  
  GPIOA->ODR &= ~(0xFF << DATA_PINS_OFFSET); // clear 
  GPIOA->ODR |= ((data & 0xf0) >> 4) << DATA_PINS_OFFSET;
  ENclock();
  
  //delay_us(4);
  
  GPIOA->ODR &= ~(0xFF << DATA_PINS_OFFSET); // clear 
  GPIOA->ODR |= ((data & 0x0f) << DATA_PINS_OFFSET);
  ENclock();
} 

void LCD_sendString(char* str, uint8_t len)
{
  char* ptr = str;
  for(uint8_t i = 0; i < len; i++, ptr++)
  {
    LCD_sendData(*ptr);
    delay_us(20);
  }
  
}

void ENclock() 
{ 
  delay_us(2);
  GPIOA->ODR |= 0x08; // EN pin set
  delay_us(5); 
  GPIOA->ODR &= ~0x08; // EN pin reset
  delay_us(2); 
}

void LCD_entyModeSet()
{
  // this mode Assign cursor moving direction 
  // and enable the shift of entire display.
  // ***S - entire shift off(0) or on(1) 
  // **I* - decrement mode(0) or increment mode(1)
  
  // LCD_sendCmd(0x04);  // 0000 0100 to data line pins 
  // LCD_sendCmd(0x05);  // 0000 0101 to data line pins 
  LCD_sendCmd(0x06);  // 0000 0110 to data line pins 
  // LCD_sendCmd(0x07);  // 0000 0111 to data line pins 
}

void LCD_displayControl()
{
  // Control display/cursor/blink 
  // ***B - blink off(0) or blink on(1) 
  // **C* - cursor off(0) or cursor on(1)
  // *D** - display off(0) or display on(1)
  
  // LCD_sendCmd(0x0c);  // 0000 1100 to data line pins 
  // LCD_sendCmd(0x0d);  // 0000 1101 to data line pins 
  LCD_sendCmd(0x0e);  // 0000 1110 to data line pins 
  // LCD_sendCmd(0x0f);  // 0000 1111 to data line pins 
}

void LCD_setCursore()
{
  LCD_sendCmd(0x01);
}

void LCD_clear()
{
  LCD_sendCmd(0x01);
  delay_ms(2);
}

void LCD_home()
{
  LCD_sendCmd(0x02);
  delay_ms(2);
}
