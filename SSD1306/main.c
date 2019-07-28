#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "i2c.h"
#include "ssd1306.h"
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void delay(uint16_t val){
	while(val){
	_delay_ms(1); 
	val--;	
	}
}
int main(void){
	I2C_Initialization();
	SSD1306_Initialization();	 
	SSD1306_Send_LOGO();
	delay(1000);
	SSD1306_Clear();
	while(1){
		//Boleslaw Lesmian - Szewczyk
		delay(1000);									      
		SSD1306_Send_STRING("W mglach daleczeje",0,0);
		delay(1000);
		SSD1306_Send_STRING("sierp ksiezyca",1,0);
		delay(2000);
		SSD1306_Send_STRING("Zatkwiony ostrzem",2,0);
		delay(1000);
		SSD1306_Send_STRING("w czub komina",3,0);
		SSD1306_Send_STRING("                  ",0,0);
		SSD1306_Send_STRING("                  ",1,0);
		delay(1000);
		delay(2000);
		SSD1306_Clear();
	}
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
