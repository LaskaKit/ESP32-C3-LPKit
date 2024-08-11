/*
* Example code for ESP32-C3_OLED_kit 
*
* ESP32-C3-LPKit v3.x reads data from SCD41
* It shows the CO2, temperature, humidity
* to OLED display
*
* Hardware:
* ESP32-C3-LPKit v3.x - https://www.laskakit.cz/laskkit-esp-12-board/
* SCD41 Senzor CO2, teploty a vlhkosti vzduchu  - https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
* OLED displej 128x64 1.3" I²C - https://www.laskakit.cz/laskakit-oled-displej-128x64-1-3--i2c/
* For ESP32-C3-LPKit v2.x and 3.x - use (native) USBSerial instead of Serial
*
* Library:
* https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
* https://github.com/adafruit/Adafruit_SH110x
*
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

#include "SparkFun_SCD4x_Arduino_Library.h"

// fonts
#include "DSEG14_Classic_Bold_32px.h"
#include "DSEG14_Classic_Bold_12px.h"

// OLED 
// uncomment only one of them, check the solderbridge on LaskaKit OLED
//#define i2c_Address 0x3c //initialize with the I2C addr 0x3C
#define i2c_Address 0x3d  //initialize with the I2C addr 0x3D

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int co2 = 0;
float temperature = 0.0;
int humidity = 0;

// SCD41
SCD4x SCD41;

#define PIN_ON    4    

void setup() {
  // Speed of Serial
  USBSerial.begin(115200);
  
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for second stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the second stabilisator
  
  // set dedicated I2C pins 8 - SCD, 10 SCL for ESP32-C3-LPKit
  Wire.begin(8, 10);

  /*----- OLED sequence ------*/
  delay(250);                        // wait for the OLED to power up
  display.begin(i2c_Address, true);  // Address 0x3C default
  //display.setContrast (0); // dim display

  // Clear the buffer.
  display.clearDisplay();
  // Set font
  display.setFont(&DSEG14_Classic_Bold_12);
  // Set color of text
  display.setTextColor(SH110X_WHITE);
  // Set position
  display.setCursor(0, 20);
  // Write text
  display.println("Waiting  for");
  display.println("");
  display.println("measurement");
  // Update display
  display.display();

  /*----- SCD41 sequence ------*/
  //             begin, autoCalibrate
  //               |      |
  if (SCD41.begin(false, true) == false) {
    USBSerial.println("SCD41 was not set correctly. Check the connection.");
    while (1)
      ;
  }

  if (SCD41.startLowPowerPeriodicMeasurement() == true) {
    USBSerial.println("Low power mode enabled.");
  }
}


void loop() {

  if(SCD41.readMeasurement())  // wait for a new data (approx 30s)
  {
    /*----- SCD41 sequence ------*/
    co2 = SCD41.getCO2();
    temperature = SCD41.getTemperature();
    humidity = SCD41.getHumidity();

    USBSerial.println();

    USBSerial.print("CO2(ppm):");
    USBSerial.println(co2);

    USBSerial.print("\tTemperature(C):");
    USBSerial.println(temperature);

    USBSerial.print("\tHumidity(%RH):");
    USBSerial.println(humidity);

    /*----- OLED sequence ------*/
    display.clearDisplay();
    // CO2
    display.setFont(&DSEG14_Classic_Bold_32);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(10, 40);
    display.println(co2);

    // Temperature
    display.setFont(&DSEG14_Classic_Bold_12);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(20, 60);
    display.println(temperature);

    // Humidity
    display.setFont(&DSEG14_Classic_Bold_12);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(80, 60);
    display.println(humidity);

    // update display
    display.display();

    digitalWrite(PIN_ON, LOW);   // Turn off the second stabilisator
    // go to sleep for 1 minute
    esp_sleep_enable_timer_wakeup(60 * 1000000);
    esp_deep_sleep_start();
  }

  delay(500);
}
