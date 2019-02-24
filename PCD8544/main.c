#ifndef __8544_H__
    #define __8544_H__
    #include "8544.h"
#endif

// 12x6 symbols LCD
int main(void){
	lcd_init();
	lcd_clear();
	for (;;){
		// your string, position x, position y
		lcd_send_string("I am a man",0,0); 
		lcd_send_string("  who walks",0,1);
		lcd_send_string("       alone",0,2); 
		lcd_send_string("IRON MAIDEN",0,5); 
		_delay_ms(500);	
	}
	return 0;
}
