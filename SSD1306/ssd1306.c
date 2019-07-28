#define F_CPU 8000000UL
#include "ssd1306.h"
#include "i2c.h"
#include "bitmap.h"
#include <avr/io.h>
#include <util/delay.h>
//Realizacja wysyłki danych do sterownika SSD1306 poprzez TWI/I2C
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Initialization(void){
	I2C_Start();											//Rozpoczęcie sekwencji startu komunikacji
	I2C_Send_BYTE(ADDRESS);									//Wysyłka na magistralę adres urządzenia
	for(unsigned char i=0; i<19; i++){						//Wysyłka podstawowych konfiguracji do sterownika z tablicy "base_conf"
		SSD1306_Send_CMD(pgm_read_byte(base_conf+i));
	}
	I2C_Stop();												//Rozpoczęcie sekwencji stopu komunikacji
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Send_CMD(unsigned char c){						//Wysyłka do urządzenia sekwencji polecenia
	I2C_Send_BYTE(CMD);										//Urządzenie przy otrzymaniu bajtu informacji musi rozpoznać czy to jest bajt danych, czy bajt polecenia
	I2C_Send_BYTE(c);										//To rozpoznawanie odbywa się za pomocą wysłanego wcześniej "zdefiniowanego" bajtu CMD. 
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Send_DATA(unsigned char d){					//Wysyłka do urządzenia sekwencji danych
	I2C_Send_BYTE(DATA);									//Urządzenie przy otrzymaniu bajtu informacji musi rozpoznać czy to jest bajt danych, czy bajt polecenia
	I2C_Send_BYTE(d);										//To rozpoznawanie odbywa się za pomocą wysłanego wcześniej "zdefiniowanego" bajtu DATA
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Clear(void){									//Funkcja czyszczenia wyświetlacza
	uint8_t i, j;
	for (i = 0; i < 8; i ++){ 
		I2C_Start();
		I2C_Send_BYTE(ADDRESS);								
		SSD1306_Send_CMD(0x20);								//Konfiguracja typu adresowania pamięci za pomocą bajtu "Set Memory Addressing"							
		SSD1306_Send_CMD(0x00);								//0x00 = "Horizontal Addr. Mode" tryb w "Set Memory Addressing"	
		SSD1306_Send_CMD(0xB0 + i);							//Set Page Address for "Page Address mode" - ustalenie pozycji Y
		SSD1306_Send_CMD(0x00);								//Set Lower Column Address for Page Addr - młodsze cztery bity adresu kolumn
	    SSD1306_Send_CMD(0x10);								//Set Higer Column Address for Page Addr - starsze cztery bity adresu kolumn
		for (j = 0; j < 128; j ++){
			SSD1306_Send_DATA(0x00);						//0x00 = pusty pixel
		}
		I2C_Stop();											//Rozpoczęcie sekwencji stopu komunikacji
	}
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Send_LOGO(){									//Wyświetlenie Logo na wyświetlaczu 128x64
	I2C_Start();  											//Rozpoczęcie sekwencji startu komunikacji
	I2C_Send_BYTE(ADDRESS);									//Wysyłka na magistralę adres urządzenia
	SSD1306_Send_CMD(0x20);									//Konfiguracja typu adresowania pamięci za pomocą bajtu "Set Memory Addressing"
	SSD1306_Send_CMD(0x00);									//0x00 = "Horizontal Addr. Mode" tryb w "Set Memory Addressing"
	SSD1306_Send_CMD(0x21);									//Bajt "Set Column Address"
	SSD1306_Send_CMD(0x00);									//0x00 = adres początku 0..127 w "Set Column Address"
	SSD1306_Send_CMD(0x7F);									//0x7F = adres końca 0..127 w "Set Column Address"
	SSD1306_Send_CMD(0x22);									//Bajt "Set Page Address"
	SSD1306_Send_CMD(0x00);									//0x00 = adres początku 0..7 w "Set Page Address"
	SSD1306_Send_CMD(0x07);									//0x00 = adres końca 0..7 w "Set Page Address"
	for(unsigned int i=0; i<1024; i++){						//Wysyłka Logo z tablicy 
		SSD1306_Send_DATA(pgm_read_byte(logo+i));
	}
	I2C_Stop();												//Rozpoczęcie sekwencji stopu komunikacji
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//			
void SSD1306_Send_SYMBOL(unsigned char s, unsigned char y,unsigned char x){ //Funkcja wysyłki pojedyńczego symbola
	if((s >= 0x20)&&(s <=0x7F)){
		s = s-32;
		char q1,q2;
		if(x!=0){
			x = x*6;
			q1 = x;
			q1 &=0x0F;
			q2 = x>>4;
			q2 = q2 + 0x10;
		}else{
			q1 = 0x00;
			q2 = 0x10;
		}
		I2C_Start();  											//Rozpoczęcie sekwencji startu komunikacji
		I2C_Send_BYTE(ADDRESS);									//Wysyłka na magistralę adres urządzenia
		SSD1306_Send_CMD(0x20);									//Konfiguracja typu adresowania pamięci za pomocą bajtu "Set Memory Addressing"
		SSD1306_Send_CMD(0x02);									//0x02 = "Page Addr. Mode" tryb w "Set Memory Addressing"					
		SSD1306_Send_CMD(q1);									//Set Lower Column Address for Page Addr - młodsze cztery bity adresu kolumn
		SSD1306_Send_CMD(q2);									//Set Higer Column Address for Page Addr - starsze cztery bity adresu kolumn
		SSD1306_Send_CMD(0xB0+y);								//Set Page Address for "Page Address mode" - ustalenie pozycji Y	
		for(unsigned char i=0; i<5;i++){	
			SSD1306_Send_DATA(pgm_read_byte(&symbol[s][i]));	//Odczytywanie z tabeli symbola
			_delay_ms(20);										//Dodawanie efektu wolnego pisania
		}
		SSD1306_Send_DATA(0x00);								//Dodawanie linijki odstępu po każdy symbole
		I2C_Stop();												//Rozpoczęcie sekwencji stopu komunikacji
	}
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Send_STRING(char *str, char y,char x){				//Funkcja dzielenia całego wyrazu na pojedyńcze symbole
		while(*str){
		SSD1306_Send_SYMBOL(*str++,y,x);
		x=x+1;
	}
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
