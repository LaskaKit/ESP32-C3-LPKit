/* Example code how to use deep sleep for ESP32-C3-LPKit
*   V4.0: 15 µA
*
*  laskakit.cz (2025)
*
* !!! ESP library version !!!
* ESP32 library 3.0.x
* Condition: Tools -> if USB CDC On Boot is ENABLED then
* Serial means native USB
* Tools -> if USB CDC On Boot is DISABLED then
* Serial means UART
* ---
* ESP32 library 2.0.xy
* Condition: Tools -> USB CDC On Boot must be disabled
* use USBSerial to send data through native USB 
*
* Board: ESP32-C3 Dev Module
*/

#define SLEEP_SEC 15         // Measurement interval (seconds)
#define PIN_ON    4    

void setup(void)
{
  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for second stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the second stabilisator

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  Serial.println("I'm not sleeping");
  delay(1000);
  digitalWrite(PIN_ON, LOW);   // Turn on the second stabilisator
  Serial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
