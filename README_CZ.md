# LASKAKIT ESP-12 board

Vývojová deska **LASKAKIT ESP-12** board obsahuje populární Wi-Fi modul **[ESP-12](https://www.laskarduino.cz/ai-thinker-esp-12e-esp8266-wifi-modul/)** s čipem ESP8266, který je široce podporován jak výrobcem, tak i komunitou bastlířů.

LASKAKIT ESP-12 board je pinově kompatibilní s Wemos D1 Mini. Oproti Wemos D1 Mini však nabízí jednu velkou výhodu - je energeticky mnohem úspornější.

Pokud tedy hledáte kompatibilní desku a zároveň chcete šetřit energii, pak LASKAKIT ESP-12 board by mohl být pro vás jako určený.

![LASKAKIT ESP-12 board description](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_popis.jpg)

LASKAKIT ESP-12 board obsahuje, kromě ESP8266 v modulu [ESP-12](https://www.laskarduino.cz/ai-thinker-esp-12e-esp8266-wifi-modul/), velmi úsporný regulátor [HT7833](https://www.laskarduino.cz/holtek-ht7833-3-3v-0-5a-stabilizator--sot-89/), který stabilizuje napětí z 5 V na 3.3 V.  
  
Tento stabilizátor má vlastní spotřebu pouhé 4 uA. V kombinaci s nízkou vlastní spotřebou ESP8266 v tzv. režimu deep-sleep, je celková spotřeba lehce přes 20 uA. Stačí zapájet pájecí most “SLEEP”.

![LASKAKIT ESP-12 board deepsleep current](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_deepsleep.jpg)

## ADC
ADC vstup ESP8266 je připojen přes dělič napětí na pin A0 (Vadc1). maximální vstupní napětí ESP8266 může být až 1V, díky děliči napětí tak můžete měřit napětí až 4,3V (při R7 = 330k; R8 = 100k).

Níže vidíte vzorec, podle kterého vypočítáte napětí na pinu A0.
Vadc1 = napětí na A0
Vadc = napětí výstupu děliče napětí

![LASKAKIT ESP-12 board ADC voltage divider](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_adc.JPG)

## PINOUT

![LASKAKIT ESP-12 board pinout](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_pinout.jpg)


Díky kompatibilitě s Wemos D1 Mini může využít i stejné rozšiřující moduly - [microSD karta](https://www.laskarduino.cz/wemos-d1-mini-microsd-shield/), čidlo teploty a vlhkost [DHT11](https://www.laskarduino.cz/wemos-d1-mini-dht11-shield/)/[DHT22](https://www.laskarduino.cz/wemos-d1-mini-dht22-shield/), [SHT30](https://www.laskarduino.cz/wemos-d1-mini-sht30-shield--i2c/), [BMP180](https://www.laskarduino.cz/wemos-d1-mini-bmp180-shield/) nebo [OLED](https://www.laskarduino.cz/wemos-d1-mini-64x48-oled-displej-shield--i2c/).

Všechny moduly najdete na [https://www.laskarduino.cz/esp-a-wemos/](https://www.laskarduino.cz/esp-a-wemos/)

## PROGRAMOVÁNÍ
V Arduino IDE nainstalujte podporu ESP8266,

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_Preference.jpg)

[https://arduino.esp8266.com/stable/package_esp8266com_index.json](https://arduino.esp8266.com/stable/package_esp8266com_index.json)

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_Generic_ESP8266_Module.png)

Pro nahrání kódu do LASKAKIT ESP-12 board v Arduino IDE je nutné přepnout ESP8266 do bootloader módu.

To provedete následujícím postupem

-   Stiskněte tlačítko "FLASH" a držte
    
-   Stiskněte tlačítko "RESET", stále držte "FLASH"
    
-   Uvolněte tlačítko "RESET" a poté i "FLASH"
    
-   Klikněte na tlačítko "Nahrát" v Arduino IDE
    
-   Po nahrání kódu stiskněte tlačítko RESET a uvolněte, kód se spustí

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_gif.gif)

LASKAKIT ESP-12 board is open-hardware, schéma i podklady pro výrobu najdete na tomto githubu.

K dispozici je i stavebnice, kterou můžete zakoupit na laskarduino.cz

[LASKAKIT ESP-12 board kit](https://www.laskarduino.cz/laskkit-esp-12-board)

[LASKAKIT ESP-12 board plošný spoj](https://www.laskarduino.cz/laskkit-esp-12-board--plosny-spoj)

