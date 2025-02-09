/*
* SLAVE zařízení 
*
* Vzorový kód pro využití ESPnow, přes které jsou odeslány teplota a vlhkost vzduchu
* Upozornění: je nezbytné zkopírovat MAC adresu z MASTER zařízení do SLAVE (masterMAC[])
* Nejprve nahraj MASTER kód do ESP32-C3 LPkit a ESP32-C3 zobrazí svou MAC adresu,
* kterou zapíšeš do SLAVE kódu a nahraješ do SLAVE zařízení.
*
* Hardware:
* https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482
* v popřípadě verze s externí anténou pak dokoupit anténu a pigtail
* https://www.laskakit.cz/pigtail-mhf3-ipex3-sma-female--kabel-1-15mm--15cm/
*
* https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
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
#include "Adafruit_SHT4x.h"

// MAC adresa master zařízení (najdi ji pomocí WiFi.macAddress() na masteru)
uint8_t masterMAC[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};

Adafruit_SHT4x sht4;

typedef struct {
    float temperature;
    float humidity;
} SensorData;

SensorData dataToSend;

#define PIN_ON    4  // GPIO pro povolení napájení SHT40

void onSent(const uint8_t *macAddr, esp_now_send_status_t status) {
  USBSerial.print("Odeslání: ");
  USBSerial.println(status == ESP_NOW_SEND_SUCCESS ? "Úspěšné" : "Neúspěšné");
}

void setup() {
  USBSerial.begin(115200);
  pinMode(PIN_ON, OUTPUT);      // nastavení GPIO řídící LDO pro I2C čidla
  digitalWrite(PIN_ON, HIGH);   // zapnutí LDO pro I2C čidla

  // nastavení SDA, SCL pinů
  Wire.begin(8, 10);
  // inicializace SHT40
  if (!sht4.begin()) {
    USBSerial.println("Nepodařilo se inicializovat SHT40!");
    while (1) delay(10);
  }
  
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    USBSerial.println("Chyba při inicializaci ESP-NOW!");
    return;
  }
  
  // callback odeslání dat
  esp_now_register_send_cb(onSent);
  
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, masterMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    USBSerial.println("Chyba při přidání peer zařízení!");
    return;
  }
}

void loop() {
  //čtení dat z SHT40
  sensors_event_t humidity, temp;
  sht4.getEvent(&humidity, &temp);
  
  dataToSend.temperature = temp.temperature;
  dataToSend.humidity = humidity.relative_humidity;

  //zprávy přes USB
  USBSerial.print(dataToSend.temperature); USBSerial.println(" degC");
  USBSerial.print(dataToSend.humidity); USBSerial.println(" %Rh");
  
  //odeslání dat
  esp_err_t result = esp_now_send(masterMAC, (uint8_t *)&dataToSend, sizeof(dataToSend));
  
  if (result == ESP_OK) {
    USBSerial.println("Data úspěšně odeslána");
  } else {
    USBSerial.println("Chyba při odesílání!");
  }

  //delay, možno nahradit deepsleep
  delay(1000);
}
