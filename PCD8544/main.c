#include "8544.h"
int main(void){
	lcd_init();
	lcd_clear();
	lcd_spi_send(LCD_DATA, 0x7f);
	lcd_spi_send(LCD_DATA, 0x09);
	lcd_spi_send(LCD_DATA, 0x19);
	lcd_spi_send(LCD_DATA, 0x29);
	lcd_spi_send(LCD_DATA, 0x46);	
	for (;;){
	_delay_ms(500);	
	}
	
	return 0;
}
