# Obsługa sterownika SSD1306 do wyświetlacza OLED z matrycą o rozmiarze 128×64


Pliki źródłowe:

* **[bitmap.h](SSD1306/bitmap.h)** - plik zawierający podstawową konfigurację wyświetlacza, logotyp oraz tablicę zdefiniowanych symboli ASCII
* **[i2c.c](SSD1306/i2c.c)** - realizacja komunikacji TWI/I2C  
* **[i2c.h](SSD1306/i2c.h)** - plik nagłówkowy do i2c.c
* **[ssd1306.c](SSD1306/ssd1306.c)** - realizacja wyświetlenia symboli, wierszy oraz logotypu
* **[ssd1306.h](SSD1306/ssd1306.h)** - plik nagłówkowy do ssd1306.c


---
### Źródła <a name="zrodla"></a>
* [Obsługa sterownika SSD1306 STM32](https://stm32.eu/2016/06/22/obsluga-sterownika-ssd1306-w-dwukolorowym-wyswietlaczu-oled-1/)
* [Obsługa interfejsu TWI/I2C (Cezary Klimasz)](http://ktc.wieik.pk.edu.pl/kurs_avr/avr_twiobsluga.pdf)
* [Datasheet SSD1306](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
