#include "MKL25Z4.h"
#include "I2C.h"
#include "LCD_i2C.h"

#define CLEAR 0x01
#define LCD_ADRESS 0x27
#define DDRAM 0x80
#define FILA1 0x80
#define FILA2 0xC0
#define FILA3 0x94
#define FILA4 0xD4
#define LCD_LEFT 0x08
#define LCD_RIGHT 0x0C
#define LCD_ON 0x0E

void LCD_Command(uint8_t command){
    int LSB = (command << 4) & F0;
    int MSB = command & F0;
    I2C_WriteByte(uint8_t LSB | 0x80);
    I2C_WriteByte(uint8_t MSB | 0x80);
}

void LCD_Init(void) {
    I2C_Start(void);//?
    LCD_Command(uint8_t LCD_ON);
}

void LCD_SetCursor(int filas, uint8_t columnas){
    if(filas == 0){
        LCD_Command((FILA1 | uint8_t columnas) | DDRAM );
    } else if(filas == 1){
        LCD_Command((FILA2 | uint8_t columnas) | DDRAM );
    } else if(filas == 2){
        LCD_Command((FILA3 | uint8_t columnas) | DDRAM );
    } else if(filas == 3){
        LCD_Command((FILA4 | uint8_t columnas) | DDRAM );
    }
}

void LCD_Clear(){
    LCD_Command(uint8_t CLEAR);
}

void LCD_ScrllDisplayLeft(){
    LCD_Command(uint8_t LCD_LEFT);
}

void LCD_ScrllDisplayRight(){
    LCD_Command(uint8_t LCD_RIGHT);
}

void LCD_Write(uint8_t data){
    I2C_WriteByte(uint8_t data);
}

void LCD_Print(char *data){
    while(*data){
        LCD_Write(*data++);
    }
}