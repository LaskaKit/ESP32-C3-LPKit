/*
* MASTER zařízení
*
* Vzorový kód pro využití ESPnow. SLAVE zařízení změří teplotu a vlhkost a odešle
* do MASTER zařízení, které hodnoty vypíše do Serial a na OLED displej
* 
* Upozornění: je nezbytné zkopírovat MAC adresu z MASTER zařízení do SLAVE (masterMAC[])
* Nejprve nahraj MASTER kód do ESP32-C3 LPkit a ESP32-C3 zobrazí svou MAC adresu,
* kterou zapíšeš do SLAVE kódu a nahraješ do SLAVE zařízení.
* 
* Hardware:
* https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482
* v popřípadě verze s externí anténou pak dokoupit anténu a pigtail
* https://www.laskakit.cz/laskakit-oled-displej-128x64-1-3--i2c/?variantId=11903
* https://www.laskakit.cz/pigtail-mhf3-ipex3-sma-female--kabel-1-15mm--15cm/
*
* Knihovny:
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/wonho-maker/Adafruit_SH1106/tree/master
* ESP32 package - 2.0.17
*
* laskakit.cz (c) 2025
*/

#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //Nastavý display
#define SH1106_I2C_ADDRESS 0x3D
#define PIN_ON    4    // GPIO pro povolení napájení SH1106 OLED

typedef struct {
    float temperature;
    float humidity;
} SensorData;

SensorData receivedData;

// Callback na přijatá data. Tato funkce se zavolá pouze tehdy, když jsou přijata data
void onReceive(const uint8_t *macAddr, const uint8_t *incomingData, int len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  
  // výstup na USB
  USBSerial.print("Přijato: ");
  USBSerial.print(receivedData.temperature);
  USBSerial.print(" °C, ");
  USBSerial.print(receivedData.humidity);
  USBSerial.println(" % ");

  //obsluha OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2); 
  display.print("T: "); display.print(receivedData.temperature); 
  display.setTextSize(1); 
  display.println(" degC");
  display.setCursor(0, 30);
  display.setTextSize(2); 
  display.print("H: "); display.print(receivedData.humidity); 
  display.setTextSize(1); 
  display.println(" %Rh");
  display.display();
  delay(100);
}

void setup() {
  USBSerial.begin(115200);
  pinMode(PIN_ON, OUTPUT);      // nastavení GPIO řídící LDO pro I2C čidla
  digitalWrite(PIN_ON, HIGH);   // zapnutí LDO pro I2C čidla

  WiFi.mode(WIFI_STA);
  delay(5000);
  USBSerial.print("MAC adresa masteru: ");
  USBSerial.println(WiFi.macAddress()); // Tuto adresu je nutné zapsat do SLAVE zařízení
  USBSerial.println("MAC adresa master musi byt ulozena ve SLAVE zarizeni.");

  // nastavení SDA, SCL pinů
  Wire.begin(8, 10);
  //inicializace OLED
  display.begin(SH1106_I2C_ADDRESS, true);
  display.setTextColor(SH110X_WHITE); 
  display.setTextSize(2); 
  display.clearDisplay();
  
  if (esp_now_init() != ESP_OK) {
    USBSerial.println("Chyba při inicializaci ESP-NOW!");
    return;
  }
  
  //callback na příchozí zprávu
  esp_now_register_recv_cb(onReceive);
}

void loop() {
    // ESP-NOW běží na callbacku, hlavní smyčka může být prázdná
}
