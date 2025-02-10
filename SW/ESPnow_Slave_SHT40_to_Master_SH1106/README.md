# ESPnow - Slave odešle teplotu a vlhkost do Master, Master je zobrazí na OLED displeji

## SLAVE zařízení </br>
Vzorový kód pro využití ESPnow, přes které jsou odeslány teplota a vlhkost vzduchu</br>
Upozornění: je nezbytné zkopírovat MAC adresu z MASTER zařízení do SLAVE (masterMAC[])
Nejprve nahraj MASTER kód do ESP32-C3 LPkit a ESP32-C3 zobrazí svou MAC adresu,
kterou zapíšeš do SLAVE kódu a nahraješ do SLAVE zařízení.
</br>
## MASTER zařízení</br>
Vzorový kód pro využití ESPnow. SLAVE zařízení změří teplotu a vlhkost a odešle
do MASTER zařízení, které hodnoty vypíše do Serial a na OLED displej</br>
Upozornění: je nezbytné zkopírovat MAC adresu z MASTER zařízení do SLAVE (masterMAC[])
Nejprve nahraj MASTER kód do ESP32-C3 LPkit a ESP32-C3 zobrazí svou MAC adresu,
kterou zapíšeš do SLAVE kódu a nahraješ do SLAVE zařízení.</br>
</br>
## Hardware:</br>
https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482</br>
v popřípadě verze s externí anténou pak dokoupit anténu a pigtail</br>
https://www.laskakit.cz/pigtail-mhf3-ipex3-sma-female--kabel-1-15mm--15cm/</br>
https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/</br>
https://www.laskakit.cz/laskakit-oled-displej-128x64-1-3--i2c/?variantId=11903</br>
</br>
## ESP32 package - 2.0.17 </br>
ESP library verze</br>
ESP32 library 3.0.x</br>
Podmínka: Tools -> pokud USB CDC On Boot is ENABLED potom</br>
Serial zmaneá nativní/vestavěné USB</br>
Tools -> pokud USB CDC On Boot je DISABLED potom</br>
Serial znamená UART (Piny RX a TX)</br>
</br>
ESP32 library 2.0.xy</br>
Podmínka: Tools -> USB CDC On Boot musí být zakázaný</br>
potom použijte USBSerial k poslání dat na nativní/vestavěné USB </br>
