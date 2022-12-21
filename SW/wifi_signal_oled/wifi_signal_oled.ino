#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <WiFi.h>

#define i2c_Address 0x3c
//#define i2c_Address 0x3d

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "laskalab";
const char* password = "laskaLAB754125";

void setup()   {
  Wire.begin(8, 10); // 8,10 = ESP32-C3-LPKit v2
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
 //display.setContrast (0); // dim display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Starting...");
  display.display();
  Serial.println("Starting...");

  delay(1000);
  display.setTextSize(5);
}


void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(WiFi.RSSI());
  Serial.println(WiFi.RSSI());
  display.display();
  delay(1000);
}
