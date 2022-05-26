# LASKAKIT ESP-12 board

The development board is called **LASKAKIT ESP-12** board which includes popular Wi-Fi module **[ESP-12](https://www.laskarduino.cz/ai-thinker-esp-12e-esp8266-wifi-modul/)** with IC ESP8266, what is supported by manufacturer and also community.

LASKAKIT ESP-12 board is pin-to-pin compatible with Wemos D1 Mini. LASKAKIT ESP-12 is much more energy efficient board instead of Wemos D1 Mini.

If you are looking for a pin-to-pin compatible board with Wemos D1 Mini, you should at least check this board. Thanks to LASKAKIT ESP-12 board, you can save the energy from the batteries of your device while maintaining the performance. 

![LASKAKIT ESP-12 board description](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_desc.jpg)

LASKAKIT ESP-12 board constains [HT7833](https://www.laskarduino.cz/holtek-ht7833-3-3v-0-5a-stabilizator--sot-89/) regulator with really low quiescent current which regulates  the input voltage (typically 5V) to 3.3V. The ESP8266 is included in module [ESP-12](https://www.laskarduino.cz/ai-thinker-esp-12e-esp8266-wifi-modul/).
  
The quiescent current of HT7833 is only 4 uA. The combination with low power consumption in the deepsleep mode of ESP8266 you can achieve only 20 uA in the deepsleep mode. Don't forget to solder the "SLEEP" soldering bridge.

![LASKAKIT ESP-12 board deepsleep current](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_deepsleep.jpg)

## ADC
ADC input of ESP8266 is connected through voltage divider to A0 pin (Vadc1). The maximum input voltage of ESP8266 may be up to 1V. Thanks the built-in votlage divider, you may measure up to 4.3V (with R7 = 330k; R8 = 100k).

The formula how to calculate the input voltage is below.

Vadc1 = voltage on A0 pin

Vadc = voltage on output of voltage divider

![LASKAKIT ESP-12 board ADC voltage divider](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_adc.JPG)

## PINOUT

![LASKAKIT ESP-12 board pinout](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_pinout.jpg)

Thanks to pinout compatibility with Wemos D1 Mini you may to use extended modules - [microSD card](https://www.laskarduino.cz/wemos-d1-mini-microsd-shield/), temperature and humidity sensor [DHT11](https://www.laskarduino.cz/wemos-d1-mini-dht11-shield/)/[DHT22](https://www.laskarduino.cz/wemos-d1-mini-dht22-shield/), [SHT30](https://www.laskarduino.cz/wemos-d1-mini-sht30-shield--i2c/), [BMP180](https://www.laskarduino.cz/wemos-d1-mini-bmp180-shield/) or [OLED](https://www.laskarduino.cz/wemos-d1-mini-64x48-oled-displej-shield--i2c/).

All modules are available on [https://www.laskarduino.cz/esp-a-wemos/](https://www.laskarduino.cz/esp-a-wemos/)

## PROGRAMMING
Install the support of ESP8266 in Arduino IDE

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_Preference.jpg)

[https://arduino.esp8266.com/stable/package_esp8266com_index.json](https://arduino.esp8266.com/stable/package_esp8266com_index.json)

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_Generic_ESP8266_Module.png)

Before the uploading of code, you have to switch the ESP8266 to bootloader mode.

Follow these steps
 * Push the "FLASH" button and hold it
 * Push the "RESET" button and still hold the "FLASH" button
 * Release the "RESET" button and after that also "FLASH" button, ESP-12 is in bootloader
 * Upload your code by "Upload" button in Arduino IDE
 * After the uploading, push the "RESET button and release it to achieve the leaving of bootloader

![LASKAKIT ESP-12 board Arduino IDE](https://github.com/LasKKit/ESP12-Board/blob/main/img/LASKKIT_ESP-12_board_gif.gif)

LASKAKIT ESP-12 board is open-hardware, the schematic and manufacturing data are available on this github.

You may enable the assembly kit which is available on laskarduino.cz

[LASKAKIT ESP-12 board kit](https://www.laskarduino.cz/laskkit-esp-12-board)

[LASKAKIT ESP-12 board bare PCB](https://www.laskarduino.cz/laskkit-esp-12-board--plosny-spoj)
