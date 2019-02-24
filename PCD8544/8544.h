#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_ORDER    0x00
#define LCD_DATA     0x01

#define LCD_X        84
#define LCD_Y        48 

#define PCD8544_DDR DDRD
#define PCD8544_PORT PORTD

#define PIN_RST  PD6 //#Linia resetująca rejestry wyświetlacza. Przed rozpoczęciem pracy należy wygenerować na niej stan zero przez co najmniej 100ns. Podczas normalnej pracy wyświetlacza, na tej linii powinien być ciągle stan wysoki
#define PIN_CE   PD7 //#Linia CS SPI
#define PIN_DC   PD5 //#Linia ustalająca, czy przesyłamy dane (stan wysoki), czy komendy dla wyświetlacza (stan niski)
#define PIN_DIN  PD4 //#Linia danych SPI (MOSI)
#define PIN_CLK  PD3 //#Linia zegarowa SPI (SCLK)

void lcd_spi_send(uint8_t dc, uint8_t data);
void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t x, uint8_t y);
void lcd_send_string(char *str, uint8_t x, uint8_t y);
void lcd_char(uint8_t char1);
