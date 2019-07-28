#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
void I2C_Initialization(void); 						        //Inicjalizacja I2C
void I2C_Start(void); 								            //Wysyłka sekwencji START
void I2C_Stop(void); 								              //Wysyłka sekwencji STOP
void I2C_Send_BYTE(unsigned char c); 			      	//Wysyłka bajtu na magistrale
//========<>========<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>=======<*>========<>========//
#endif
