/* Example code how measure wifi signal and who on OLED with ESP32-C3-LPKit v3.x
*
*  laskakit.cz (2023)
*
* !!! ESP library version !!!
* ESP32 library 3.0.x
* Condition: Tools -> USB CDC On Boot must be enabled
* use HWCDCSerial instead of USBSerial
* ---
* ESP32 library 2.0.xy
* Condition: Tools -> USB CDC On Boot must be disabled
* use USBSerial instead of HWCDCSerial
*
* Board: ESP32-C3 Dev Module
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <WiFi.h>

#define PIN_ON    4  

#define i2c_Address 0x3d
//#define i2c_Address 0x3c    // cut jumper I2C Address on lthe left and solder on the right 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "SSID";
const char* password = "PASSWORD";

void setup()   {
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for second stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the second stabilisator
  
  Wire.begin(8, 10); // 8,10 = ESP32-C3-LPKit v3
  USBSerial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    USBSerial.print(".");
  }
  USBSerial.println("");
  USBSerial.println("WiFi connected");

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
