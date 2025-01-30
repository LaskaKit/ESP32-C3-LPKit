![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_1.jpg)
![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_2.jpg)
# LaskaKit ESP32-C3-LPKit 

The LaskaKit [ESP32-C3-LPKit](https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482) development board is based on the popular Wi-Fi/Bluetooth ESP32-C3, which is widely supported by both the manufacturer and the bastling community.

The board is pin-to-pin and size compatible with the Wemos D1 Mini. Even though the [ESP32-C3-LPKit](https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482) includes a programmer like the popular Wemos D1 Mini, it achieves much lower power consumption and a low-power voltage regulator.</br>
This makes it much more energy efficient. So if you are looking for a compatible board and want to save power at the same time, then the ESP32-C3-LPKit is for you.

![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_4.jpg)

The ESP32-C3-LPKit also includes a charging circuit for the battery, which is charged from USB-C or from the VIN pin. The charging current is selected by a solder bridge on the bottom of the board. The default setting is 400mA.</br>
The voltage measurement of the connected battery is disabled-unconnected by default (solder bridge on the bottom of the PCB). Either the battery (solder bridge) or the voltage connected on pin A0 (solder bridge) can be connected to the ESP32-C3. The measured voltage (battery/external input) is divided by voltage divider. The analog input for measured votlage is GPIO0.

It is necessary to add a definition on which PINs is I2C initiating the i2c module: Wire.begin(8, 10); // (8,10) -> ESP32-C3-LPKit v2; (19,18) -> ESP32-C3-LPKit v1

To program, you need to put the chip in bootloader mode.</br>
**Simply press the FLASH button and press and release RESET. Then release the FLASH button as well.**</br>
On Windows OS you should hear the characteristic sound of the newly connected device.</br>

For the older version of the ESP32-C3-LPKit you need a programmer, not only for them we have created a [suitable programmer](https://www.laskakit.cz/laskakit-ch9102-programmer-usb-c--microusb--uart/), with which programming this board will be a total breeze. When using our programmer, it is no longer necessary to press any buttons before the actual programming. Switching to programming mode is automatic.

| ESP module | 	ESP32-C3 | 
|---|---|
| Input voltage | 	3,7-8V | 
| Current in deep-sleep mode | 7μA | 
| Digital I/O Pins | 9 | 
| Analog inputs | 5 | 
| Dimensions |
| Length |34.2mm | 
| Width | 25.6mm | 
| Height | 7mm | 
| Weight | 8.26g | 

**The board is available on https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482**

Pinout
![LaskaKit ESP32-C3-LPKit pinout](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_pinout.JPG)

