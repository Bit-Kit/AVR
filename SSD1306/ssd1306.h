#ifndef SSD1306_H_
#define SSD1306_H_
#include <avr/io.h>
#include <util/delay.h>
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
#define		ADDRESS		0x78 								          //Adres urządzenia na magistrali TWI, możliwe inne adresy: 0x3C, 0x3D, 0x78, 0x7A
#define		DATA		0xC0								            //Wysyłka bajdu definiującego dane
#define		CMD			0x80								            //Wysyłka bajdu definiującego polecenie
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void SSD1306_Initialization (void); 						  //Inicjalizacja I2C
void SSD1306_Send_CMD(unsigned char cmd);					//Wysyłka do urządzenia sekwencji polecenia
void SSD1306_Send_DATA(unsigned char data);			  //Wysyłka do urządzenia sekwencji danych
void SSD1306_Clear(void);									        //Funkcja czyszczenia wyświetlacza				
void SSD1306_Send_LOGO();									        //Wyświetlenie Logo na wyświetlaczu 128x64
void SSD1306_Send_SYMBOL(unsigned char s, unsigned char y,unsigned char x);		  //Funkcja wysyłki pojedyńczego symbola
void SSD1306_Send_STRING(char *str, char y,char x);                             //Funkcja dzielenia całego wyrazu na pojedyńcze symbole
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
#endif
