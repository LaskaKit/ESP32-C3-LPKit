![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_1.jpg)
![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_2.jpg)

# LaskaKit ESP32-C3-LPKit 

Vývojová deska [LaskaKit ESP32-C3-LPKit](https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482) založena na populárním Wi-Fi/Bluetooth ESP32-C3, který je široce podporován jak výrobcem, tak i komunitou bastlířů. 

Deska je pinově a rozměrově kompatibilní s Wemos D1 Mini. I přesto, že [ESP32-C3-LPKit](https://www.laskakit.cz/laskkit-esp-12-board/) obsahuje programátor stejně jako populární Wemos D1 Mini, dosahuje daleko nižší spotřeby energie a ssamozřejmě i úspornější stabilizátor napětí.</br>
Díky tomu je energeticky mnohem úspornější. Pokud tedy hledáš kompatibilní desku a zároveň chcete šetřit energii, pak ESP32-C3-LPKit je pro Tebe jako určený.

![LaskaKit ESP32-C3-LPKit](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_4.jpg)

ESP32-C3-LPKit obsahuje i nabíjecí obvod pro akumulátor, ten se nabíjí z USB-C nebo z pinu VIN. Nabíjecí proud se volí pájecím mostem na spodní straně desky. Výchozí nastavení je 400mA.</br>
Měření napětí připojeného akumulátoru je ve výchozím stavu zakázáno-nepřipojeno (pájecí most na spodní straně DPS). Do ESP32-C3 může být připojeno měření napětí buď akumulátoru (pájecí most) nebo napětí připojené na pinu A0 (pájecí most). Napětí připojené na A0 je sníženo o poměr napěťového děliče. Analogový vstup pro měření napětí je GPIO0.

I2C uŠup je připojen na GPIO8 - SDA a GPIO10 - SCL.

Pro naprogramování je potřeba dostat čip do režimu nahrávání. </br>
**Stačí zmáčknout tlačítko FLASH a zmáčknout a pustit RESET. Poté pustit i tlačítko FLASH** </br>
U OS Windows byste měli uslyšet charakteristický zvuk nově připojého zařízení.</br>

Pro staší verzi ESP32-C3-LPKit je potřeba programátor, nejen k nim jsme [vytvořili vhodný programátor](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/), se kterým bude programování této desky naprostá hračka. Při použití tohoto našeho programátoru již není nutné před vlastním programováním mačkat žádná tlačítka. Přepnutí do režimu programování je automatické.</br>

| ESP modul | 	ESP32-C3 | 
|---|---|
| Vstupní napětí | 	3,7-8V | 
| Odběr proudu v deep-sleep módu | 7μA | 
| Digitální I/O Piny | 9 | 
| Analogové Vstupy | 5 |
| Rozměry |
| Délka |34.2mm | 
| Šířka | 25.6mm | 
| Výška | 7mm | 
| Váha | 8.26g | 

**LaskaKit ESP32-C3-LPkit najdeš na https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482**

Pinout ESP32-C3-LPKit vidíš níže
![LaskaKit ESP32-C3-LPKit pinout](https://github.com/LaskaKit/ESP32-C3-LPKit/blob/main/img/ESP32-C3-LPKit_pinout.JPG)
