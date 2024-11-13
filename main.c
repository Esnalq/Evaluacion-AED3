#include "MKL25Z4.h"
#include "I2C.h"
#include "LCD_i2C.h"
int c;
void main(){
    LCD_Init();
    I2C0_Init();
    while(1){
        LCD_ScrllDisplayLeft();
        LCD_Print(hola);
        for(int i = 0 ; i < 3000000;i++){
        }
        LCD_Clear();
        LCD_ScrllDisplayRight();
        LCD_Print(joaco);
        LCD_Clear();
        for(int i = 0 ; i < 3000000;i++){
        }
        LCD_Clear();
    }
}