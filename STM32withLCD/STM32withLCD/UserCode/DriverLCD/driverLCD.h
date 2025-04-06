#ifndef __DRIVERLCD_H
#define __DRIVERLCD_H

#include "delayTim.h"

#define DATA_PINS_OFFSET 0x04

void LCD_Init_4bit(void);
void LCD_sendCmd_0(uint8_t data);
void LCD_sendCmd(uint8_t data);
void LCD_sendData(uint8_t data);
void LCD_sendString(char* str, uint8_t len);
void LCD_displayControl(void);
void LCD_entyModeSet(void);
void LCD_clear(void);
void LCD_home(void);
void ENclock(void);

#endif