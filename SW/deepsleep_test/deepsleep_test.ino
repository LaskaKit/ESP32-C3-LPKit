/* Example code how to use deep sleep for ESP32-C3-LPKit v3.x
*
*  laskakit.cz (2024)
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

#define SLEEP_SEC 15         // Measurement interval (seconds)

void setup(void)
{
  USBSerial.begin(115200);

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  USBSerial.println("I'm not sleeping");
  delay(1000);
  USBSerial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  USBSerial.println("ESP in sleep mode");
  USBSerial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
