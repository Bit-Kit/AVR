#define F_CPU 8000000UL
#define F_SCL 100000L					 //Prędkość transmisji = 100 kHz
#include "i2c.h"
#include <avr/io.h>
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void I2C_Initialization (void){				 //Inicjalizacja TWI
	TWBR = ((F_CPU/F_SCL)-8)/2;			 //Zapis do rejestru przędkości transmisji migistrali 0x20
	TWSR = 0;				 	 //Ustawienie preskalera na zero
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void I2C_Start (void){ 					 //Wysyłka sekwencji START
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));			 //Oczekiwanie na zmianę flagi TWINT
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void I2C_Stop (void){					 //Wysyłka sekwencji STOP
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void I2C_Send_BYTE(unsigned char c){ 			 //Wysyłka bajtu na magistrale
	TWDR = c;					 //Zapisywanie bajtu danych do rejestru
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));			 //Oczekiwanie na zmianę flagi TWINT
}
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
