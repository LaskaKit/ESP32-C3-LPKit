
#define SLEEP_SEC 15*60         // Measurement interval (seconds)

void setup(void)
{
  Serial.begin(115200);

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){
  Serial.println("going to sleep 5 sek");
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
