#define F_CPU 8000000UL
#include "8544.h"

void lcd_spi_send(uint8_t dc, uint8_t data){
	
	if (dc == LCD_DATA){
		PCD8544_PORT |= (1<<PIN_DC);		
	} else {
		PCD8544_PORT &=~(1<<PIN_DC);
	}
	PCD8544_PORT &=~(1<<PIN_CE);
	for (uint8_t i = 0;i<8; i++){
		PCD8544_PORT = (data & 0x80) ? PCD8544_PORT | (1<<PIN_DIN) : PCD8544_PORT & ~(1<<PIN_DIN);
		data=(data<<1);
		PCD8544_PORT|=(1<<PIN_CLK);
		PCD8544_PORT&=~(1<<PIN_CLK);
	}
	PCD8544_PORT|=(1<<PIN_CE);	
}
void lcd_init(void){
	PCD8544_DDR |= (1<< PIN_RST) | (1<< PIN_CE) | (1<< PIN_DC) | (1<< PIN_DIN) | (1<< PIN_CLK);
	PCD8544_PORT &=~(1<< PIN_RST);
	PCD8544_PORT |=(1<< PIN_RST);
	lcd_spi_send(LCD_ORDER,0x21);
	lcd_spi_send(LCD_ORDER,0xBA);	
	lcd_spi_send(LCD_ORDER,0x04);
	lcd_spi_send(LCD_ORDER,0x14);	
	lcd_spi_send(LCD_ORDER,0x20);
	lcd_spi_send(LCD_ORDER,0x0C);
}
void lcd_clear(void){
	int i;
	for(i=0;i < LCD_X * LCD_Y /8; i++){
		lcd_spi_send(LCD_DATA,0x00);
	}
}

void lcd_set_cursor(uint8_t x, uint8_t y){
	 x=x%12; y=y%6;
	 lcd_spi_send(LCD_ORDER,0x40+y);
	 lcd_spi_send(LCD_ORDER,0x80+x*7);	 	 
}
void lcd_send_string(char *str, uint8_t x, uint8_t y){
	lcd_set_cursor(x,y);
	while(*str){
		lcd_char(*str++);
	}
}

void lcd_char(uint8_t char1){
	if(char1 >= 0x20 && char1 <= 0x80){
		int i;
		lcd_spi_send(LCD_DATA, 0x00);
		for(i=0;i<5;i++){
			lcd_spi_send(LCD_DATA, ASCII[char1 - 0x20][i]);
		}
		lcd_spi_send(LCD_DATA, 0x00);
	}
}
