#ifndef LCD_I2C
#define LCD_I2C
#include "MKL25Z4.h"
void LCD_Init();
void LCD_Clear();
void LCD_Print(char *data);
void LCD_SetCursor(int filas, uint8_t columnas);
void LCD_Command(uint8_t command);
void LCD_Write(uint8_t data);
void LCD_ScrllDisplayRight();
void LCD_ScrllDisplayLeft();
#endif