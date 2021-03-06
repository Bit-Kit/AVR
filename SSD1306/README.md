# Obsługa sterownika SSD1306 do wyświetlacza OLED z matrycą o rozmiarze 128×64

Komunikacja jest oparta o magistralę TWI/I2C. Niektóre wyświetlacze ze sterownikiem SSD1306 również posiadają interfejs SPI.
Wiersze w wyświetlaczu 128 × 64 zdefiniowane jako strony (ang. Pages). Wysokośc takiego wiersza równa się 8 pikseli, co pozwala na wyświetlenie jednego symbolu o rozdzielczości 8 × 6 pikseli.

Pliki źródłowe:

* **[bitmap.h](bitmap.h)** - plik zawierający podstawową konfigurację wyświetlacza, logotyp oraz tablicę zdefiniowanych symboli ASCII
* **[i2c.c](i2c.c)** - realizacja komunikacji TWI/I2C  
* **[i2c.h](i2c.h)** - plik nagłówkowy do i2c.c
* **[ssd1306.c](ssd1306.c)** - realizacja wyświetlenia symboli, wierszy oraz logotypu
* **[ssd1306.h](ssd1306.h)** - plik nagłówkowy do ssd1306.c


---
### Źródła <a name="zrodla"></a>
* [Obsługa sterownika SSD1306 STM32](https://stm32.eu/2016/06/22/obsluga-sterownika-ssd1306-w-dwukolorowym-wyswietlaczu-oled-1/)
* [Obsługa interfejsu TWI/I2C (Cezary Klimasz)](http://ktc.wieik.pk.edu.pl/kurs_avr/avr_twiobsluga.pdf)
* [Datasheet SSD1306](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
