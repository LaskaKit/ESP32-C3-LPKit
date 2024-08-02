/* Example code how to use deep sleep for ESP32-C3-LPKit v1.x
* For ESP32-C3-LPKit v2.x and 3.x - use (native) USBSerial instead of Serial
*
*  laskakit.cz (2023)
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

  Serial.println("I'm mot sleeping");
  delay(1000);
  digitalWrite(PIN_ON, LOW);   // Turn on the second stabilisator
  Serial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
